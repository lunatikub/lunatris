#ifndef TETROMINO_DEF_H_
# define TETROMINO_DEF_H_

/**
 * Filled tetromino cell.
 */
#define X (1)

/**
 * Emtpy tetromino cell.
 */
#define _ (0)

/**
 * A tetromino is defined by an array of cells of dim 4x4.
 */
#define TETROMINO_SZ (4)

/**
 * Size of a tetromino definition.
 */
#define DEF_SZ(tetromino)                       \
  (sizeof(tetromino_ ## tetromino)              \
   / sizeof(tetromino_ ## tetromino[0]))

/**
 * Definition of a tetromino.
 */
struct tetromino_def {
  uint8_t t[TETROMINO_SZ][TETROMINO_SZ];
  /* All the following fields will
     be automaticly completed at initialization
     by @c tetromino_defs(). */
  uint8_t hc[TETROMINO_SZ]; /* Height by column. */
  uint8_t w; /* Width of the tetromino. */
  uint8_t h; /* Height of the tetromino. */
};

#endif /* !TETROMINO_DEF_H_ */
