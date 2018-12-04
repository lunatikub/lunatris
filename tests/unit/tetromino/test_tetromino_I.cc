#include "test_tetromino.hh"

TEST_F(Tetromino, IRotate)
{
  EXPECT_EQ(tetromino_push(wall, TETROMINO_I, 0, 0), TETROMINO_OK);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_I, 1, 0), TETROMINO_OK);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_I, 2, 0), TETROMINO_EINVAL_ROTATE);
}

TEST_F(Tetromino, IXaxis)
{
  EXPECT_EQ(tetromino_push(wall, TETROMINO_I, 0, 6), TETROMINO_OK);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_I, 0, 7), TETROMINO_EINVAL_X);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_I, 1, 9), TETROMINO_OK);
}

TEST_F(Tetromino, IYaxis)
{
  for (unsigned i = 0; i < 5; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_I, 1, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_I, 1, 0), TETROMINO_EINVAL_Y);
}

TEST_F(Tetromino, I)
{
  uint8_t e1[WALL_WIDTH] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  uint8_t e2[WALL_WIDTH] = { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 };

  // 0 ..........
  tetromino_push(wall, TETROMINO_I, 0, 0);
  // 0 XXXX......
  ExpectLine(0, e1);

  tetromino_push(wall, TETROMINO_I, 0, 0);
  // 1 XXXX......
  // 0 XXXX......
  ExpectLine(0, e1);
  ExpectLine(1, e1);

  tetromino_push(wall, TETROMINO_I, 0, 2);
  // 2 ..XXXX....
  // 1 XXXX......
  // 0 XXXX......
  ExpectLine(0, e1);
  ExpectLine(1, e1);
  ExpectLine(2, e2);

  uint8_t e3[WALL_WIDTH] = { 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 };
  tetromino_push(wall, TETROMINO_I, 0, 6);
  // 2 ..XXXX....
  // 1 XXXX......
  // 0 XXXX..XXXX
  ExpectLine(0, e3);
  ExpectLine(1, e1);
  ExpectLine(2, e2);

  uint8_t e4[WALL_WIDTH] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 0 };
  tetromino_push(wall, TETROMINO_I, 0, 5);
  // 3 .....XXXX.
  // 2 ..XXXX....
  // 1 XXXX......
  // 0 XXXX..XXXX
  ExpectLine(0, e3);
  ExpectLine(1, e1);
  ExpectLine(2, e2);
  ExpectLine(3, e4);

  tetromino_push(wall, TETROMINO_I, 1, 0);
  tetromino_push(wall, TETROMINO_I, 1, 9);
  tetromino_push(wall, TETROMINO_I, 0, 1);
  //   0123456789
  // 5 X.........
  // 4 X........X
  // 3 XXXXXXXXXX
  // 2 X.XXXX...X
  // 1 XXXX.....X
  // 0 XXXX..XXXX
  uint8_t e5[WALL_WIDTH] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 1 };
  uint8_t e6[WALL_WIDTH] = { 1, 0, 1, 1, 1, 1, 0, 0, 0, 1 };
  uint8_t e7[WALL_WIDTH] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
  uint8_t e8[WALL_WIDTH] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  ExpectLine(0, e3);
  ExpectLine(1, e5);
  ExpectLine(2, e6);
  ExpectLine(3, e7);
  ExpectLine(4, e8);
}

TEST_F(Tetromino, ITetris)
{
  tetromino_push(wall, TETROMINO_I, 1, 0);
  tetromino_push(wall, TETROMINO_I, 1, 1);
  tetromino_push(wall, TETROMINO_I, 1, 2);
  tetromino_push(wall, TETROMINO_I, 1, 3);
  tetromino_push(wall, TETROMINO_I, 1, 4);
  tetromino_push(wall, TETROMINO_I, 1, 5);
  tetromino_push(wall, TETROMINO_I, 1, 6);
  tetromino_push(wall, TETROMINO_I, 1, 7);
  tetromino_push(wall, TETROMINO_I, 1, 8);

  uint8_t e1[WALL_WIDTH] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
  ExpectLine(0, e1);
  ExpectLine(1, e1);
  ExpectLine(2, e1);
  ExpectLine(3, e1);

  tetromino_push(wall, TETROMINO_I, 1, 9);

  uint8_t empty[WALL_WIDTH] = { 0 };
  ExpectLine(0, empty);
  ExpectLine(1, empty);
  ExpectLine(2, empty);
  ExpectLine(3, empty);
}
