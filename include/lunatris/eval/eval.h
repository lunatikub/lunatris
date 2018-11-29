#ifndef EVAL_H_
# define EVAL_H_

/**
 * Name: Transition of lines.
 * Description: Number of transitions between full/empty
 * or empty/full cell for each lines.
 * ID: dl (Delta Line).
 * Aim: Homogeneous of the wall.
 */
uint32_t eval_dl(wall_handle w);

/**
 * Name: Transition of columns.
 * Description: Number of transitions between full/empty
 * or empty/full cell for each column.
 * ID: dl (Delta Column).
 * Aim: Homogeneous of the wall.
 */
uint32_t eval_dc(wall_handle w);

/**
 * Name: Number of holes.
 * Description: Number of empty cells at least
 * covered by one filled cell.
 * ID: h
 * Aim: Not have holes.
 */
uint32_t eval_h(wall_handle w);

/**
 * Name: Sum of wells.
 * Description: Sum w∈puits (1 + 2 + ... + depth(w))
 * ID: w
 * Aim: Not have wells.
 */
uint32_t eval_w(wall_handle w);

#endif /* !EVAL_H_ */