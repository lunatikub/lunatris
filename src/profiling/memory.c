#include <stdio.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>

#include <lunatris/profiling/memory.h>
#include <lunatris/utils/macro.h>

#ifdef LUNATRIS_MEMORY

#define FILENAME_LEN (64)

/**
 * Metadata of a block allcoated.
 */
struct mem_meta {
  uint64_t id; /* Unique identifier of the allocation. */
  enum module_id mid; /* Module identifier. */
  enum struct_id sid; /* Structure identifier. */
  size_t size; /* Block size. */
  struct timeval start; /* Start time allocation. */
  struct timeval end; /* End time allocation (free). */
  uint32_t line; /* Line which the allocation is done. */
  char file[FILENAME_LEN]; /* File which the allocation is done. */
  SLIST_ENTRY(mem_meta) next;
};

/**
 * Real structure allocated on a user allocation
 * in order to store identifer of meta before the data.
 */
struct mem_block {
  uint64_t id; /* Identifier of the meta data. */
  char data[]; /* data */
};

/**
 * Global memory profiling shared between all threads.
 * This instance is intialize in the constructor and
 * cleanup in the desctructor.
 */
static struct mem_profiling mem_profil;

/**
 * Main structure to manage memory allocations.
 */
struct mem_profiling {
  SLIST_HEAD(, mem_meta) alived; /* List of alived allocations. */
  SLIST_HEAD(, mem_meta) freed; /* List of freed allocations. */
  pthread_mutex_t lock; /* The structure has to be manipulated under the lock. */
  uint64_t id; /* Counter for the unique id by allocation. */
};

/**
 * Allocate a new metadata.
 */
static inline struct mem_meta*
mem_meta_new(size_t size, enum module_id mid, enum struct_id sid,
             uint32_t line, const char *file)
{
  struct mem_meta *meta = malloc(sizeof(*meta));
  assert(meta != NULL);
  memset(meta, 0, sizeof(*meta));

  pthread_mutex_lock(&mem_profil.lock);
  meta->id = mem_profil.id++;
  pthread_mutex_unlock(&mem_profil.lock);

  meta->size = size;
  meta->mid = mid;
  meta->sid = sid;
  gettimeofday(&meta->start, NULL);
  meta->line = line;
  strcpy(meta->file, file);

  return meta;
}

/**
 * Malloc a new block with the user data size requested.
 */
static inline struct mem_block* mem_block_malloc(size_t size, uint64_t id)
{
  struct mem_block *block = malloc(sizeof(*block) + size);
  assert(block != NULL);

  block->id = id;
  return block;
}

/**
 * Calloc a new block with the user data size requested.
 */
static inline struct mem_block* mem_block_calloc(size_t nmemb, size_t size, uint64_t id)
{
  struct mem_block *block = malloc(nmemb * size + sizeof(*block));
  assert(block != NULL);
  memset(block->data, 0, nmemb * size);

  block->id = id;
  return block;
}

/**
 * Find a meta in the alived allocations.
 * Lock has to be taken.
 */
static struct mem_meta* meta_find(uint64_t id)
{
  struct mem_meta *iter;

  SLIST_FOREACH(iter, &mem_profil.alived, next) {
    if (iter->id == id) {
      return iter;
    }
  }

  return iter;
}

static __attribute__((constructor)) void mem_constructor(void)
{
  printf("----- start memory profiling\n");
  SLIST_INIT(&mem_profil.alived);
  SLIST_INIT(&mem_profil.freed);
  mem_profil.id = 1;
  pthread_mutex_init(&mem_profil.lock, NULL);
}

static void report_leak(void)
{
  printf("----- memory leak report\n");
  struct mem_meta *iter;

  if (SLIST_EMPTY(&mem_profil.alived)) {
    printf("No leak detected.\n");
    return;
  }

  SLIST_FOREACH(iter, &mem_profil.alived, next) {
    printf("%s (line:%u), module: '%s', struct: '%s', size: '%lu'\n",
           iter->file,
           iter->line,
           module_name(iter->mid),
           struct_name(iter->sid),
           iter->size);
  }

  abort();
}

static void report_allocation(void)
{
  printf("----- memory allocation report\n");
  struct mem_meta *iter;

  SLIST_FOREACH(iter, &mem_profil.freed, next) {
    printf("%s, %s, %lu, %ld.%06ld, %ld.%06ld\n",
           module_name(iter->mid),
           struct_name(iter->sid),
           iter->size,
           iter->start.tv_sec,
           iter->start.tv_usec,
           iter->end.tv_sec,
           iter->end.tv_usec);
  }
}

static __attribute__((destructor)) void mem_destructor(void)
{
  struct mem_meta *iter;

  report_leak();
  report_allocation();

  while (!SLIST_EMPTY(&mem_profil.freed)) {
    iter = SLIST_FIRST(&mem_profil.freed);
    SLIST_REMOVE_HEAD(&mem_profil.freed, next);
    free(iter);
  }
  pthread_mutex_destroy(&mem_profil.lock);
  printf("----- end memory profiling\n");
}

void *mem_malloc(size_t size, enum module_id mid, enum struct_id sid,
                 uint32_t line, const char *file)
{
  struct mem_meta *meta = mem_meta_new(size, mid, sid, line, file);
  struct mem_block *block = mem_block_malloc(size, meta->id);

  pthread_mutex_lock(&mem_profil.lock);
  SLIST_INSERT_HEAD(&mem_profil.alived, meta, next);
  pthread_mutex_unlock(&mem_profil.lock);

  return block->data;
}

void *mem_calloc(size_t nmemb, size_t size, enum module_id mid, enum struct_id sid,
                 uint32_t line, const char *file)
{
  struct mem_meta *meta = mem_meta_new(nmemb * size, mid, sid, line, file);
  struct mem_block *block = mem_block_calloc(nmemb, size, meta->id);

  pthread_mutex_lock(&mem_profil.lock);
  SLIST_INSERT_HEAD(&mem_profil.alived, meta, next);
  pthread_mutex_unlock(&mem_profil.lock);

  return block->data;
}

void mem_free(void *ptr)
{
  struct mem_meta *meta;
  struct mem_block *block = container_of(ptr, typeof(*block), data);

  pthread_mutex_lock(&mem_profil.lock);
  {
    meta = meta_find(block->id);
    assert(meta != NULL); /* Invalid free. */
    SLIST_REMOVE(&mem_profil.alived, meta, mem_meta, next);
    gettimeofday(&meta->end, NULL);
    SLIST_INSERT_HEAD(&mem_profil.freed, meta, next);
  }
  pthread_mutex_unlock(&mem_profil.lock);

  free(block);
}

#endif /* !LUNATRIS_MEMORY */
