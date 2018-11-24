#ifndef WALL_INTERNAL_H_
# define WALL_INTERNAL_H_

# include <stdint.h>

# include <lunatris/lunatris.h>

/**
 * Wall is a table of @c WALL_WIDTH of width
 * and @c WALL_HEIGHT of height.
 */
struct wall {
  uint8_t table[WALL_HEIGHT][WALL_WIDTH];
  uint8_t cells[WALL_HEIGHT]; /* Number of cells filled by line. */
  uint8_t h[WALL_WIDTH]; /* Height of each columns. */
};

/**
 * Return the height of a column,
 * @param x x-axis column.
 */
uint8_t wall_height_get(wall_handle, uint8_t x);

#endif /* !WALL_INTERNAL_H_ */
