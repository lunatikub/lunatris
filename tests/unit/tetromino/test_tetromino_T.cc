#include "test_tetromino.hh"

TEST_F(Tetromino, TRotate)
{
  for (unsigned i = 0; i < 4; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_T, i, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_T, 4, 0), TETROMINO_EINVAL_ROTATE);
}

TEST_F(Tetromino, TXaxis)
{
  EXPECT_EQ(tetromino_push(wall, TETROMINO_T, 0, 7), TETROMINO_OK);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_T, 0, 8), TETROMINO_EINVAL_X);
}

TEST_F(Tetromino, TYaxis)
{
  for (unsigned i = 0; i < 10; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_T, 0, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_T, 0, 0), TETROMINO_EINVAL_Y);
}

TEST_F(Tetromino, T_h)
{
  tetromino_push(wall, TETROMINO_T, 0, 0);
  EXPECT_EQ(wall_last_tetromino_height_get(wall), 2);
}

TEST_F(Tetromino, T)
{
  tetromino_push(wall, TETROMINO_T, 0, 0);
  tetromino_push(wall, TETROMINO_T, 3, 2);
  tetromino_push(wall, TETROMINO_T, 1, 0);
  tetromino_push(wall, TETROMINO_T, 2, 1);

  // 3 - XXXX.......
  // 2 - XXXX.......
  // 1 - XXXX.......
  // 0 - XXXX.......

  uint8_t e[WALL_WIDTH] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, };
  ExpectLine(0, e);
  ExpectLine(1, e);
  ExpectLine(2, e);
  ExpectLine(3, e);
}
