#ifndef EVAL_H_
# define EVAL_H_

/**
 * Name: Transition of lines.
 * Description: Number of transitions between full/empty
 * or empty/full cell for each lines.
 * ID: dl (Delta Line).
 * Aim: homogeneous of the wall.
 */
uint32_t eval_dl(struct wall *w);

/**
 * Name: Transition of columns.
 * Description: Number of transitions between full/empty
 * or empty/full cell for each column.
 * ID: dl (Delta Column).
 * Aim: homogeneous of the wall.
 */
uint32_t eval_dc(struct wall *w);

/**
 * Name: Number of holes.
 * Description: Number of empty cells at least
 * covered by one filled cell.
 * ID: h
 * Aim: should not have hole.
 */
uint32_t eval_h(struct wall *w);

#endif /* !EVAL_H_ */
