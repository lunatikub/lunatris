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
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 1, 1, 0, 0 },
      { 1, 1, 0, 0 },
    },
  },
};

#define TETROMINO_O_SZ (sizeof(tetromino_O) / sizeof(tetromino_O[0]))

#endif /* !TETROMINO_INTERNAL_H_ */
