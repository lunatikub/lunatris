#include <lunatris/wall/wall.h>
#include <lunatris/eval/eval.h>

/**
 *     0123456789
 *     ----------
 * 3 - X.........
 * 2 - .X........
 * 1 - ..X.......
 * 0 - ...X......
 *
 * Number of holes
 * col 0: 3
 * col 1: 2
 * col 2: 1
 * col 3 to 9: 0
 */

uint32_t eval_hole(wall_handle w)
{
  uint32_t h = 0;

  /* Sum of each number of hole by col. */
  for (uint8_t x = 0; x < WALL_WIDTH; ++x) {
    h += wall_hole_get(w, x);
  }

  return h;
}
