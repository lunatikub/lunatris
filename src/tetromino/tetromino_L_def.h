#ifndef TETROMINO_L_DEF_H_
# define TETROMINO_L_DEF_H_

/**
 * +----+----+----+----+
 * |....|....|....|....|
 * |....|XX..|....|.X..|
 * |X...|X...|XXX.|.X..|
 * |XXX.|X...|..X.|XX..|
 * +----+----+----+----+
 */
static struct tetromino_def tetromino_L[] = {
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { X, _, _, _ },
      { X, X, X, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { X, _, _, _ },
      { X, X, X, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { X, X, X, _ },
      { _, _, X, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { _, X, _, _ },
      { _, X, _, _ },
      { X, X, _, _ },
    },
  },
};

#define TETROMINO_L_SZ DEF_SZ(L)

#endif /* !TETROMINO_L_DEF_H_ */
