#ifndef PROFILING_MEMORY_H
# define PROFILING_MEMORY_H

#include <config.h>

#ifdef LUNATRIS_MEMORY

#include <stdlib.h>
#include <stdint.h>
#include <lunatris/module.h>

/* Combine module id and structure id to have an unique id. */
#define MEMORY_ID(mid, sid) (mid << 24 & sid)

/**
 * Each structure must have an entry
 * this following enumeration.
 */
enum struct_id {
  SID_WALL,
  SID_POOL,
  SID_RESSOURCE,
};

#define MALLOC(size, sid) lunatris_malloc(size, MEMORY_ID(MODULE_ID, sid))
#define CALLOC(nmemb, size, sid) lunatris_calloc(nmemb, size, MEMORY_ID(MODULE_ID, sid))
#define FREE(ptr, sid) lunatris_free(ptr, MEMORY_ID(MODULE_ID, sid))

/**
 * Malloc/Calloc/Free.
 * Realloc is forbidde.
 */
void *lunatris_malloc(size_t size, uint32_t id);
void *lunatris_calloc(size_t nmemb, size_t size, uint32_t id);
void lunatris_free(void *ptr, uint32_t id);

#else

#include <stdlib.h>

#define MALLOC(size, mid, sid) malloc(size)
#define CALLOC(nmemb, size, sid) calloc(nmemb, size)
#define FREE(ptr, sid) free(ptr)

#endif

#endif /* !PROFILING_MEMORY_H */
