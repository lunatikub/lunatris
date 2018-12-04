#ifndef TETROMINO_I_DEF_H_
# define TETROMINO_I_DEF_H_

/**
 * +----+----+
 * |....|X...|
 * |....|X...|
 * |....|X...|
 * |XXXX|X...|
 * +----+----+
 */
static struct tetromino_def tetromino_I[] = {
  {
    {
      { _, _, _, _ },
      { _, _, _, _ },
      { _, _, _, _ },
      { X, X, X, X },
    },
  },
  {
    {
      { X, _, _, _ },
      { X, _, _, _ },
      { X, _, _, _ },
      { X, _, _, _ },
    },
  },
};

#define TETROMINO_I_SZ DEF_SZ(I)

#endif /* !TETROMINO_I_DEF_H_ */
