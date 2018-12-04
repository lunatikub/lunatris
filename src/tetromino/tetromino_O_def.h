#ifndef TETROMINO_O_DEF_H_
# define TETROMINO_O_DEF_H_

/**
 * +----+
 * |....|
 * |....|
 * |XX..|
 * |XX..|
 * +----+
 */
static struct tetromino_def tetromino_O[] = {
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { X, X, _, _ },
      { X, X, _, _ },
    },
  },
};

#define TETROMINO_O_SZ DEF_SZ(O)

#endif /* !TETROMINO_O_DEF_H_ */
