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
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 1, 1, 1, 1 },
    },
  },
  {
    {
      { 1, 0, 0, 0 },
      { 1, 0, 0, 0 },
      { 1, 0, 0, 0 },
      { 1, 0, 0, 0 },
    },
  },
};

#define TETROMINO_I_SZ (sizeof(tetromino_I) / sizeof(tetromino_I[0]))

#endif /* !TETROMINO_INTERNAL_H_ */
