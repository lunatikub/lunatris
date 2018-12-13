#include <lunatris/wall/wall.h>
#include <lunatris/eval/eval.h>

/**
 * Erosion is the number of lines completed
 * by the last tetromino play.
 */

uint32_t eval_erosion(wall_t w)
{
  return wall_nr_line_completed_get(w);
}
