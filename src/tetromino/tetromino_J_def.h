#ifndef TETROMINO_J_DEF_H_
# define TETROMINO_J_DEF_H

/**
 * +----+----+----+----+
 * |....|....|....|....|
 * |....|X...|....|XX..|
 * |..X.|X...|XXX.|.X..|
 * |XXX.|XX..|X.,.|.X..|
 * +----+----+----+----+
 */
static struct tetromino_def tetromino_J[] = {
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { _, _, X, _ },
      { X, X, X, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { X, _, _, _ },
      { X, _, _, _ },
      { X, X, _, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { X, X, X, _ },
      { X, _, _, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { X, X, _, _ },
      { _, X, _, _ },
      { _, X, _, _ },
    },
  },
};

#define TETROMINO_J_SZ DEF_SZ(J)

#endif /* !TETROMINO_J_DEF_H_ */
