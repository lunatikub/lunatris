#include <lunatris/wall/wall.h>
#include <lunatris/eval/eval.h>

uint32_t eval_dl(wall_handle w)
{
  uint32_t dl = 0;

  for (uint8_t y = 0; y < WALL_HEIGHT; ++y) {
    for (uint8_t x = 0; x < WALL_WIDTH - 1; ++x) {
      /* Transition full/empty or empty/full. */
      if (wall_get(w, y, x) + wall_get(w, y, x + 1) == FILLED) {
        ++dl;
      }
    }
  }

  return dl;
}

uint32_t eval_dc(wall_handle w)
{
  uint32_t dc = 0;

  for (uint8_t x = 0; x < WALL_WIDTH; ++x) {
    for (uint8_t y = 0; y < WALL_HEIGHT - 1; ++y) {
      /* Transition full/empty or empty/full. */
      if (wall_get(w, y, x) + wall_get(w, y + 1, x) == FILLED) {
        ++dc;
      }
    }
  }

  return dc;
}

uint32_t eval_h(wall_handle w)
{
  uint32_t h = 0;

  /* Sum of each number of hole by col. */
  for (uint8_t x = 0; x < WALL_WIDTH; ++x) {
    h += wall_hole_get(w, x);
  }

  return h;
}

/**
 * Sum(1): 1
 * Sum(2): 1 + 2 = 3
 * Sum(N): 1 + 2 + ... + N = (N * (N + 1)) / 2
 */
static inline uint8_t sum(uint8_t h)
{
  return (h * (h + 1)) / 2;
}

/**
 * Return the minimal height of both neighbors.
 */
static inline uint8_t min_height_neighbors(wall_handle w, uint8_t x)
{
  uint8_t left_h = WALL_HEIGHT;
  uint8_t right_h = WALL_HEIGHT;

  if (x != 0) {
    left_h = wall_height_get(w, x - 1);
  }

  if (x != WALL_WIDTH - 1) {
    right_h = wall_height_get(w, x + 1);
  }

  return left_h > right_h ? right_h : left_h;
}

uint32_t eval_w(wall_handle w)
{
  uint32_t well = 0;

  for (uint8_t x = 0; x < WALL_WIDTH; ++x) {
    uint8_t min_h = min_height_neighbors(w, x);
    uint8_t h = wall_height_get(w, x);
    if (min_h > h) {
      well += sum(min_h - h);
    }
  }

  return well;
}
