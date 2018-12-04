#include "test_tetromino.hh"

TEST_F(Tetromino, S)
{
  tetromino_push(wall, TETROMINO_S, 0, 0);
  tetromino_push(wall, TETROMINO_S, 1, 2);
  tetromino_push(wall, TETROMINO_S, 0, 0);

  // 4 - .XX.......
  // 3 - XXX.......
  // 2 - ..XX......
  // 1 - .XXX......
  // 0 - XX........

  uint8_t e4[WALL_WIDTH] = { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
  uint8_t e3[WALL_WIDTH] = { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
  uint8_t e2[WALL_WIDTH] = { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 };
  uint8_t e1[WALL_WIDTH] = { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  uint8_t e0[WALL_WIDTH] = { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

  ExpectLine(4, e4);
  ExpectLine(3, e3);
  ExpectLine(2, e2);
  ExpectLine(1, e1);
  ExpectLine(0, e0);
}
