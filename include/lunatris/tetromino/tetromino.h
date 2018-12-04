#ifndef TETROMINO_H_
# define TETROMINO_H_

#include <stdint.h>
#include <stdbool.h>

#include <lunatris/wall/wall.h>

/**
 * +---------+---------+---------+
 * | I: XXXX | L: XXX  | J: XXX  |
 * |         |      X  |    X    |
 * +---------+---------+---------+
 * | O:  XX  | S:  XX  | T:  X   |
 * |     XX  |    XX   |    XXX  |
 * +---------+---------+---------+
 * | Z: XX   |
 * |     XX  |
 * +---------+
 */
enum tetromino {
  TETROMINO_I,
  TETROMINO_J,
  TETROMINO_L,
  TETROMINO_O,
  TETROMINO_S,
  TETROMINO_T,
  TETROMINO_Z,
};

enum tetromino_error {
  TETROMINO_OK, /* OK. */
  TETROMINO_EINVAL_ROTATE, /* Invalid rotate. */
  TETROMINO_EINVAL_X, /* Invalid x-axis coord. */
  TETROMINO_EINVAL_Y, /* Invalid y-axis coord. */
};

/**
 * Push a tetromino in a wall.
 *
 * @param wall Wall handle.
 * @param tetromino Tetromino to push.
 * @param rotate Rotate of the tetromino.
 * @param x x-axis coord.
 *
 * @return Return @c TETROMINO_OK if the play is valid,
 * otherwise return an error.
 */
enum tetromino_error
tetromino_push(wall_t wall, enum tetromino tetromino,
               uint8_t rotate, uint8_t x);

#endif /* !TETROMINO_H_ */
