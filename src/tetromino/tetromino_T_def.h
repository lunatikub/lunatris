#ifndef TETROMINO_T_DEF_H_
# define TETROMINO_T_DEF_H_

/**
 * +----+----+----+----+
 * |....|....|....|....|
 * |....|X...|....|.X..|
 * |.X..|XX..|XXX.|XX..|
 * |XXX.|X...|.X..|.X..|
 * +----+----+----+----+
 */
static struct tetromino_def tetromino_T[] = {
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { _, X, _, _ },
      { X, X, X, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { X, _, _, _ },
      { X, X, _, _ },
      { X, _, _, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { X, X, X, _ },
      { _, X, _, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { _, X, _, _ },
      { X, X, _, _ },
      { _, X, _, _ },
    },
  },
};

#define TETROMINO_T_SZ DEF_SZ(T)

#endif /* !TETROMINO_T_DEF_H_ */
