#include "test_tetromino.hh"

TEST_F(Tetromino, ORotate)
{
  EXPECT_EQ(tetromino_push(wall, TETROMINO_O, 0, 0), TETROMINO_OK);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_O, 1, 0), TETROMINO_EINVAL_ROTATE);
}

TEST_F(Tetromino, OXaxis)
{
  EXPECT_EQ(tetromino_push(wall, TETROMINO_O, 0, 8), TETROMINO_OK);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_O, 0, 9), TETROMINO_EINVAL_X);
}

TEST_F(Tetromino, OYaxis)
{
  for (unsigned i = 0; i < 10; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_O, 0, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_O, 0, 0), TETROMINO_EINVAL_Y);
}

TEST_F(Tetromino, O)
{
  tetromino_push(wall, TETROMINO_O, 0, 0);
  tetromino_push(wall, TETROMINO_O, 0, 1);
  tetromino_push(wall, TETROMINO_O, 0, 2);
  tetromino_push(wall, TETROMINO_O, 0, 0);

  // 5 - XXXX.......
  // 4 - XXXX.......
  // 3 - .XX........
  // 2 - .XX........
  // 1 - XX.........
  // 0 - XX.........

  uint8_t e1[WALL_WIDTH] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  uint8_t e2[WALL_WIDTH] = { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
  uint8_t e3[WALL_WIDTH] = { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

  ExpectLine(0, e3);
  ExpectLine(1, e3);
  ExpectLine(2, e2);
  ExpectLine(3, e2);
  ExpectLine(4, e1);
  ExpectLine(5, e1);
}
