#include <lunatris/wall/wall.h>

#include "wall_internal.h"
#include "eval.h"

uint32_t eval_dl(struct wall *w)
{
  uint32_t dl = 0;

  for (uint8_t y = 0; y < WALL_HEIGHT; ++y) {
    for (uint8_t x = 0; x < WALL_WIDTH - 1; ++x) {
      if (wall_get(w, y, x) + wall_get(w, y, x + 1) == FILLED) {
        ++dl;
      }
    }
  }
  return dl;
}

uint32_t eval_dc(struct wall *w)
{
  uint32_t dc = 0;
  for (uint8_t x = 0; x < WALL_WIDTH; ++x) {
    for (uint8_t y = 0; y < WALL_HEIGHT - 1; ++y) {
      if (wall_get(w, y, x) + wall_get(w, y + 1, x) == FILLED) {
        ++dc;
      }
    }
  }
  return dc;
}

uint32_t eval_h(struct wall* w)
{
  uint32_t h = 0;

  for (uint8_t x = 0; x < WALL_WIDTH; ++x) {
    h += w->holes[x];
  }
  return h;
}
