#include <lunatris/profiling/memory.h>

#ifdef LUNATRIS_MEMORY

#define MEMORY_MODULE_ID(id) (id >> 24)
#define MEMORY_STRUCT_ID(id) (id & 0x00ffffff)

void *lunatris_malloc(size_t size, uint32_t id)
{
  return malloc(size);
}

void *lunatris_calloc(size_t nmemb, size_t size, uint32_t id)
{
  return calloc(nmemb, size);
}

void lunatris_free(void *ptr, uint32_t id)
{
  free(ptr);
}

#endif /* !LUNATRIS_MEMORY */
