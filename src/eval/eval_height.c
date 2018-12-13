#include <lunatris/wall/wall.h>
#include <lunatris/eval/eval.h>

/**
 * Last tetromino height.
 * Information is filled in the wall structure
 * by the tetromino_push function.
 */

uint32_t eval_height(wall_t w)
{
  return wall_last_tetromino_height_get(w);
}
