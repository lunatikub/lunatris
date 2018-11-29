#include <lunatris/wall/wall.h>
#include <lunatris/eval/eval.h>

/**
 *     0123456789
 *     ----------
 * 3 - X.........
 * 2 - X.X.......
 * 1 - X.X.X.....
 * 0 - X.X.X.X...
 *
 * col 0: no bigger neighbor
 * col 1: -> left neighbor height 4, right neighbor height: 3
 *        -> min bigger neighbor: 3
 *        -> 3 + 2 + 1 = 6
 * col 2: no bigger neighbor
 * col 3: 2 + 1  = 3
 * col 4: no bigger neighbor
 * col 5: 1
 * ...
 * Sum w ∈ wells (1 + 2 + ... + depth(w)) = 6 + 3 + 1 = 10
 */

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

uint32_t eval_well(wall_handle w)
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
