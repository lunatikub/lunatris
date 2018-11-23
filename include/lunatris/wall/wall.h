#ifndef WALL_H_
# define WALL_H_

# include <stdint.h>

# define WALL_WIDTH (10)
# define WALL_HEIGTH (20)

struct wall {
  uint8_t table[WALL_HEIGTH][WALL_WIDTH];
};

/**
 * Set a case of the wall
 * @param x x-axis coord
 * @param y y-axis coord
 */
void wall_set(struct wall *w, uint8_t x, uint8_t y);

#endif /* !WALL_H_ */
