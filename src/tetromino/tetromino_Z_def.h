#ifndef TETROMINO_Z_DEF_H_
# define TETROMINO_Z_DEF_H_

/**
 * +----+----+
 * |....|....|
 * |....|.X..|
 * |XX..|XX..|
 * |.XX.|X...|
 * +----+----+
 */
static struct tetromino_def tetromino_Z[] = {
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { X, X, _, _ },
      { _, X, X, _ },
    },
  },
  {
    {
      { _, _, _, _ },
      { _, X, _, _ },
      { X, X, _, _ },
      { X, _, _, _ },
    },
  },
};

#define TETROMINO_Z_SZ DEF_SZ(Z)

#endif /* !TETROMINO_S_DEF_H_ */
