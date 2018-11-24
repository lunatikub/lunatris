#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <lunatris/wall/wall.h>
#include "wall_internal.h"

static inline uint8_t check_coord(uint8_t y, uint8_t x)
{
  assert(y < WALL_HEIGHT);
  assert(x < WALL_WIDTH);
  return (WALL_HEIGHT - 1) - y;
}

static void complete_line(struct wall *w, uint8_t y)
{
  for (int8_t iter_y = y; iter_y > 0; --iter_y) {
    memmove(w->table[iter_y], w->table[iter_y - 1], WALL_WIDTH);
    w->cells[iter_y] = w->cells[iter_y - 1];
  }
  memset(w->table[0], 0, WALL_WIDTH);

  for (uint8_t x = 0; x < WALL_WIDTH; ++x) {
    if (w->h[x] > 0) {
      --w->h[x];
    }
  }
}

void wall_create(struct wall **w)
{
  struct wall *new_wall = malloc(sizeof(*new_wall));
  assert(new_wall != NULL);
  memset(new_wall, 0, sizeof((*new_wall)));
  *w = new_wall;
}

void wall_destroy(struct wall *w)
{
  free(w);
  w = NULL;
}

void wall_set(struct wall *w, uint8_t y, uint8_t x)
{
  uint8_t ry = check_coord(y, x);
  assert(w->table[ry][x] == EMPTY);
  w->table[ry][x] = FILLED;

  /* Update height of the column. */
  if (w->h[x] < y + 1) {
    w->h[x] = y + 1;
  }

  /* Line is completed ? */
  if (++w->cells[ry] == WALL_WIDTH) {
    complete_line(w, ry);
  }
}

enum cell wall_get(struct wall *w, uint8_t y, uint8_t x)
{
  y = check_coord(y, x);
  return w->table[y][x];
}

uint8_t wall_height_get(struct wall *w, uint8_t x)
{
  check_coord(0, x);
  return w->h[x];
}
