#ifndef TETROMINO_L_DEF_H_
# define TETROMINO_L_DEF_H

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
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 1, 0, 0, 0 },
      { 1, 1, 1, 0 },
    },
  },
  {
    {
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 1, 0, 0, 0 },
      { 1, 1, 1, 0 },
    },
  },
  {
    {
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 1, 1, 1, 0 },
      { 0, 0, 1, 0 },
    },
  },
  {
    {
      { 0, 0, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 1, 1, 0, 0 },
    },
  },
};

#define TETROMINO_L_SZ (sizeof(tetromino_L) / sizeof(tetromino_L[0]))

#endif /* !TETROMINO_INTERNAL_H_ */
