#include "test_tetromino.hh"

TEST_F(Tetromino, LRotate)
{
  for (unsigned i = 0; i < 4; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_L, i, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_L, 4, 0), TETROMINO_EINVAL_ROTATE);
}

TEST_F(Tetromino, LXaxis)
{
  EXPECT_EQ(tetromino_push(wall, TETROMINO_L, 0, 7), TETROMINO_OK);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_L, 0, 8), TETROMINO_EINVAL_X);
}

TEST_F(Tetromino, LYaxis)
{
  for (unsigned i = 0; i < 10; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_L, 0, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_L, 0, 0), TETROMINO_EINVAL_Y);
}

TEST_F(Tetromino, L1)
{
  tetromino_push(wall, TETROMINO_L, 0, 0);
  tetromino_push(wall, TETROMINO_L, 2, 1);
  // 1 - XXXX......
  // 0 - XXXX......
  uint8_t e[WALL_WIDTH] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  ExpectLine(0, e);
  ExpectLine(1, e);
}

TEST_F(Tetromino, L2)
{
  tetromino_push(wall, TETROMINO_L, 0, 0);
  tetromino_push(wall, TETROMINO_L, 2, 0);
  // 2 - XXX.......
  // 1 - X.X.......
  // 0 - XXX.......
  uint8_t e1[WALL_WIDTH] = { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
  uint8_t e2[WALL_WIDTH] = { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 };
  ExpectLine(0, e1);
  ExpectLine(1, e2);
  ExpectLine(2, e1);
}

TEST_F(Tetromino, L3)
{
  tetromino_push(wall, TETROMINO_L, 0, 0);
  tetromino_push(wall, TETROMINO_L, 3, 3);
  tetromino_push(wall, TETROMINO_L, 3, 2);
  // 3 - ...X.
  // 2 - ...XX
  // 1 - X.XXX
  // 0 - XXXXX
  uint8_t e1[WALL_WIDTH] = { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };
  uint8_t e2[WALL_WIDTH] = { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 };
  uint8_t e3[WALL_WIDTH] = { 1, 0, 1, 1, 1, 0, 0, 0, 0, 0 };
  uint8_t e4[WALL_WIDTH] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 };
  ExpectLine(3, e1);
  ExpectLine(2, e2);
  ExpectLine(1, e3);
  ExpectLine(0, e4);
}

  // for (int x = 0; x < 10; ++x) {
  //   std::cout << x;
  // }
  // std::cout << std::endl;
  // std::cout << std::endl;

  // for (int y = 19; y >= 0; --y) {
  //   for (int x = 0; x < 10; ++x) {
  //     std::cout << wall_get(wall, y, x);
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;
