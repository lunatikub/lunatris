#ifndef PROFILING_MEMORY_H
# define PROFILING_MEMORY_H

#include <config.h>
#include <stdlib.h>

#ifdef LUNATRIS_MEMORY

#include <stdint.h>
#include <lunatris/module.h>
#include <lunatris/profiling/struct_def.h>

/**
 * In 'memory-profiling' enabled, redirect on overloaded functions.
 */
#define MALLOC(size, sid) \
  mem_malloc(size, MODULE_ID, sid, __LINE__, __FILE__)

#define CALLOC(nmemb, size, sid) \
  mem_calloc(nmemb, size, MODULE_ID, sid, __LINE__, __FILE__)

#define FREE(ptr, sid) mem_free(ptr)

/**
 * Overload functions of malloc/calloc/free
 * for the memory profiling.
 */
void *mem_malloc(size_t size, enum module_id mid, enum struct_id sid,
                 uint32_t line, const char *file);

void mem_free(void *ptr);

void *mem_calloc(size_t nmemb, size_t size,
                 enum module_id mid, enum struct_id sid,
                 uint32_t line, const char *file);

#else

/**
 * In 'memory-profiling' disabled, redirect on standard functions.
 */
#define MALLOC(size, mid, sid) malloc(size)
#define CALLOC(nmemb, size, sid) calloc(nmemb, size)
#define FREE(ptr, sid) free(ptr)

#endif

#endif /* !PROFILING_MEMORY_H */
