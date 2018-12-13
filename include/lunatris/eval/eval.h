#ifndef EVAL_H_
# define EVAL_H_

/**
 * Name: Transition of lines.
 * Description: Number of transitions between full/empty
 * or empty/full cell for each lines.
 * ID: dl (Delta Line).
 * Aim: Homogeneous of the wall.
 */
uint32_t eval_delta_line(wall_t w);

/**
 * Name: Transition of columns.
 * Description: Number of transitions between full/empty
 * or empty/full cell for each column.
 * ID: dl (Delta Column).
 * Aim: Homogeneous of the wall.
 */
uint32_t eval_delta_col(wall_t w);

/**
 * Name: Number of holes.
 * Description: Number of empty cells at least
 * covered by one filled cell.
 * ID: h
 * Aim: Not have holes.
 */
uint32_t eval_hole(wall_t w);

/**
 * Name: Sum of wells.
 * Description: Sum w ∈ wells (1 + 2 + ... + depth(w))
 * ID: w
 * Aim: Not have wells.
 */
uint32_t eval_well(wall_t w);

/**
 * Name: Height of the last tetromino.
 * Description: Height of the last tetromino played.
 * ID: l
 * Aim: Prevent to grow up the height of the wall.
 */
uint32_t eval_height(wall_t w);

/**
 * Name: Erosion
 * Description: Number of lines completed with the last play.
 * ID: e
 * Aim: Encourage to complete lines.
 */
uint32_t eval_erosion(wall_t w);

#endif /* !EVAL_H_ */
