#ifndef WALL_H_
# define WALL_H_

# include <stdint.h>

# include <lunatris/lunatris.h>

# define WALL_WIDTH (10)
# define WALL_HEIGHT (20)

/* Opaque structure for a wall. */
typedef struct wall* wall_handle;

/**
 * Create and initialize a wall.
 * @param wall Wall to initialize.
 */
void wall_create(wall_handle *wall);

/**
 * Destroy a wall.
 * @param wall Wall to destroy.
 */
void wall_destroy(wall_handle wall);

/**
 * Set a cell of the wall.
 * @param wall Wall handle.
 * @param y y-axis coord.
 * @param x x-axis coord.
 */
void wall_set(wall_handle wall, uint8_t y, uint8_t x);

/**
 * Get a cell of the wall.
 * @param wall Wall handle.
 * @param y y-axis coord.
 * @param x x-axis coord.
 * @return @c EMPTY or @c FILLED.
 */
enum cell wall_get(wall_handle, uint8_t y, uint8_t x);

/**
 * Return the height of a column,
 * @param x x-axis column.
 */
uint8_t wall_height_get(wall_handle, uint8_t x);

#endif /* !WALL_H_ */
