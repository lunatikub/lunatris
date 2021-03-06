#ifndef WALL_H_
# define WALL_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <lunatris/lunatris.h>

/* Opaque structure for a wall. */
typedef struct wall* wall_t;

/**
 * Create and initialize a wall.
 * @param wall Wall to initialize.
 */
void wall_create(wall_t *wall);

/**
 * Destroy a wall.
 * @param wall Wall to destroy.
 */
void wall_destroy(wall_t wall);

/**
 * Set a cell of the wall.
 * @param wall Wall handle.
 * @param y y-axis coord.
 * @param x x-axis coord.
 * @return True has been completed, otherwise return false.
 */
bool wall_set(wall_t wall, uint8_t y, uint8_t x);

/**
 * Get a cell of the wall.
 * @param wall Wall handle.
 * @param y y-axis coord.
 * @param x x-axis coord.
 * @return @c EMPTY or @c FILLED.
 */
enum cell wall_get(wall_t, uint8_t y, uint8_t x);

/**
 * Get height of a column.
 * @param wall Wall handle.
 * @param x x-axis column.
 * @return height of the column.
 */
uint8_t wall_height_get(wall_t w, uint8_t x);

/**
 * Get number of holes of a column.
 * @param wall Wall handle.
 * @param x x-asis coord.
 * @return number of holes.
 */
uint8_t wall_hole_get(wall_t w, uint8_t x);

/**
 * Get the size of a wall.
 * Useful for pool implementation.
 * @return size of a wall.
 */
size_t wall_size_get(void);

/**
 * Get the last tetromino height.
 */
uint8_t wall_last_tetromino_height_get(wall_t w);

/**
 * Set the last tetromino height.
 */
void wall_last_tetromino_height_set(wall_t w, uint8_t h);

/**
 * Get the number of lines completed by the last play.
 */
uint8_t wall_nr_line_completed_get(struct wall *w);

/**
 * Set the number of lines completed by the last play.
 */
void wall_nr_line_completed_set(struct wall *w, uint8_t nr);

#endif /* !WALL_H_ */
