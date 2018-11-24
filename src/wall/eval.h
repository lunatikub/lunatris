#ifndef EVAL_H_
# define EVAL_H_

/**
 * Number of transitions between full/empty cell for each lines.
 * ID: dl - Delta Line.
 * aim: homogeneous of the wall.
 */
uint32_t eval_dl(struct wall *w);

/**
 * Number of transitions between full/empty cell for each column.
 * ID: dl - Delta Column.
 * aim: homogeneous of the wall.
 */
uint32_t eval_dc(struct wall *w);

#endif /* !EVAL_H_ */
