#include <string.h>
#include <assert.h>

#include <lunatris/wall/wall.h>
#include <lunatris/profiling/memory.h>

/* profiling */
#define MODULE_ID MODULE_WALL

/**
 * Wall is a table of @c WALL_WIDTH of width
 * and @c WALL_HEIGHT of height.
 */
struct wall {
  uint8_t table[WALL_HEIGHT][WALL_WIDTH];
  uint8_t cells[WALL_HEIGHT]; /* Number of cells filled by line. */
  uint8_t height[WALL_WIDTH]; /* Height of each columns. */
  uint8_t holes[WALL_WIDTH]; /* Holes of each columns. */
};

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
    if (w->height[x] > 0) {
      --w->height[x];
    }
  }
}

static void count_holes(struct wall *w, uint8_t x)
{
  uint8_t nr_holes = 0;

  if (w->height[x] == 1) {
    w->holes[x] = 0;
    return;
  }

  for (uint8_t iter_y = WALL_HEIGHT - w->height[x] + 1;
       iter_y < WALL_HEIGHT; ++iter_y) {
    if (w->table[iter_y][x] == EMPTY) {
      ++nr_holes;
    }
  }
  w->holes[x] = nr_holes;
}

void wall_create(struct wall **w)
{
  struct wall *new_wall = CALLOC(1, sizeof(*new_wall), SID_WALL);
  *w = new_wall;
}

void wall_destroy(struct wall *w)
{
  FREE(w, SID_WALL);
}

void wall_set(struct wall *w, uint8_t y, uint8_t x)
{
  uint8_t ry = check_coord(y, x);
  assert(w->table[ry][x] == EMPTY);
  w->table[ry][x] = FILLED;

  /* Update height of the column. */
  if (w->height[x] < y + 1) {
    w->height[x] = y + 1;
  }

  /* Line is completed ? */
  if (++w->cells[ry] == WALL_WIDTH) {
    complete_line(w, ry);
  }

  /* Count number of holes. */
  count_holes(w, x);
}

enum cell wall_get(struct wall *w, uint8_t y, uint8_t x)
{
  y = check_coord(y, x);
  return w->table[y][x];
}

uint8_t wall_height_get(struct wall *w, uint8_t x)
{
  check_coord(0, x);
  return w->height[x];
}

uint8_t wall_hole_get(struct wall *w, uint8_t x)
{
  check_coord(0, x);
  return w->holes[x];
}

size_t wall_size_get(void)
{
  return sizeof(struct wall);
}
