#ifndef TETROMINO_S_DEF_H_
# define TETROMINO_S_DEF_H_

/**
 * +----+----+
 * |....|....|
 * |....|X...|
 * |.XX.|XX..|
 * |XX..|.X..|
 * +----+----+
 */
static struct tetromino_def tetromino_S[] = {
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { _, X, X, _ },
      { X, X, _, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { X, _, _, _ },
      { X, X, _, _ },
      { _, X, _, _ },
    },
  },
};

#define TETROMINO_S_SZ DEF_SZ(S)

#endif /* !TETROMINO_S_DEF_H_ */
