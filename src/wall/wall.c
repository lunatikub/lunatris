#include <assert.h>

#include <lunatris/wall/wall.h>

void wall_set(struct wall *w, uint8_t x, uint8_t y)
{
  assert(y < WALL_HEIGTH);
  assert(x < WALL_WIDTH);

  w->table[x][y] = 1;
}
