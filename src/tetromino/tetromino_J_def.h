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
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 1, 0 },
      { 1, 1, 1, 0 },
    },
  },
  {
    {
      { 0, 0, 0, 0 },
      { 1, 0, 0, 0 },
      { 1, 0, 0, 0 },
      { 1, 1, 0, 0 },
    },
  },
  {
    {
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 1, 1, 1, 0 },
      { 1, 0, 0, 0 },
    },
  },
  {
    {
      { 0, 0, 0, 0 },
      { 1, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
    },
  },
};

#define TETROMINO_J_SZ (sizeof(tetromino_J) / sizeof(tetromino_J[0]))

#endif /* !TETROMINO_INTERNAL_H_ */
