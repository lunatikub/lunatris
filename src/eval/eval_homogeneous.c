#include <lunatris/wall/wall.h>
#include <lunatris/eval/eval.h>

/**
 * Homogeneous wall:
 * XX..XXXXX
 * XXXXXXXXX
 *
 * No homogeneous wall:
 * X........
 * X..X.....
 * X..X.X.X.
 */

uint32_t eval_delta_line(wall_t w)
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

uint32_t eval_delta_col(wall_t w)
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
