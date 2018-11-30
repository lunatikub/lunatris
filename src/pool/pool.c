#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/queue.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

#include <lunatris/utils.h>
#include <lunatris/pool/pool.h>

struct ressource {
  STAILQ_ENTRY(ressource) next;
  char data[];
};

struct pool {
  pthread_mutex_t lock;
  STAILQ_HEAD(, ressource) ressources;
  size_t free_sz; /* Number of free ressources. */
  size_t sz; /* Size of the pool. */
  size_t data_sz; /* Size of the data. */
};

/**
 * Allocate a new ressource.
 */
static struct ressource* ressource_new(size_t data_sz)
{
  struct ressource *new_ressource =
    calloc(1, sizeof(*new_ressource) + data_sz);
  assert(new_ressource != NULL);

  return new_ressource;
}

void pool_extend(struct pool *pool, size_t sz)
{
  pthread_mutex_lock(&pool->lock);
  {
    for (size_t i = 0; i < sz; ++i) {
      struct ressource *new_ressource = ressource_new(pool->data_sz);
      STAILQ_INSERT_HEAD(&pool->ressources, new_ressource, next);
    }

    pool->sz += sz;
    pool->free_sz += sz;
  }
  pthread_mutex_unlock(&pool->lock);
}

void pool_create(struct pool **pool, size_t sz, size_t data_sz)
{
  struct pool *new_pool = calloc(1, sizeof(*new_pool));
  assert(new_pool != NULL);
  *pool = new_pool;

  pthread_mutex_init(&new_pool->lock, NULL);
  new_pool->data_sz = data_sz;
  STAILQ_INIT(&new_pool->ressources);

  pool_extend(new_pool, sz);
}

bool pool_destroy(struct pool *pool)
{
  struct ressource *iter;

  if (pool->free_sz != pool->sz) {
    return false;
  }

  while (!STAILQ_EMPTY(&pool->ressources)) {
    iter = STAILQ_FIRST(&pool->ressources);
    STAILQ_REMOVE_HEAD(&pool->ressources, next);
    free(iter);
  }

  pthread_mutex_destroy(&pool->lock);
  free(pool);

  return true;
}

void* pool_reserve(struct pool *pool)
{
  struct ressource *ressource;

  pthread_mutex_lock(&pool->lock);
  {
    if (STAILQ_EMPTY(&pool->ressources)) {
      pthread_mutex_unlock(&pool->lock);
      return NULL;
    }

    ressource = STAILQ_FIRST(&pool->ressources);
    STAILQ_REMOVE_HEAD(&pool->ressources, next);
    --pool->free_sz;
  }
  pthread_mutex_unlock(&pool->lock);

  return ressource->data;
}

void pool_release(struct pool *pool, void *data)
{
  struct ressource *ressource =
    container_of(data, typeof(*ressource), data);

  pthread_mutex_lock(&pool->lock);
  {
    STAILQ_INSERT_TAIL(&pool->ressources, ressource, next);
    ++pool->free_sz;
    memset(ressource->data, 0, pool->data_sz);
  }
  pthread_mutex_unlock(&pool->lock);
}
