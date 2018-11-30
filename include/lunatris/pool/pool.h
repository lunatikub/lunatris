#ifndef POOL_H_
# define POOL_H_

/* Opaque structure for a pool. */
typedef struct pool* pool_t;

/**
 * Create and initialize a pool.
 * @param pool Pool to initialize.
 * @param sz Size of the pool.
 * @param data_sz Size of the data.
 */
void pool_create(struct pool **pool, size_t sz, size_t data_sz);

/**
 * Destroy a pool - all ressources has to be
 * @param pool Pool to destroy.
 * @return true if the pool is succesfully destroyed, otherwise return false.
 */
bool pool_destroy(struct pool *pool);

/**
 * Reserve a ressource.
 * @param pool Pool handle.
 * @return return pointer to a free space of data_sz.
 */
void* pool_reserve(struct pool *pool);

/**
 * Release a ressource.
 * @param pool Pool handle.
 * @param data Data to releease.
 */
void pool_release(struct pool *pool, void *data);

/**
 * Extend pool.
 * @param sz Extend size.
 * @param pool Pool handle.
 */
void pool_extend(struct pool *pool, size_t sz);

#endif /* !POOL_H_ */
