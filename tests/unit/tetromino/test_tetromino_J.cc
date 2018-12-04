#include "test_tetromino.hh"

TEST_F(Tetromino, JRotate)
{
  for (unsigned i = 0; i < 4; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_J, i, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_J, 4, 0), TETROMINO_EINVAL_ROTATE);
}

TEST_F(Tetromino, JXaxis)
{
  EXPECT_EQ(tetromino_push(wall, TETROMINO_J, 0, 7), TETROMINO_OK);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_J, 0, 8), TETROMINO_EINVAL_X);
}

TEST_F(Tetromino, JYaxis)
{
  for (unsigned i = 0; i < 10; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_J, 0, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_J, 0, 0), TETROMINO_EINVAL_Y);
}

TEST_F(Tetromino, J1)
{
  tetromino_push(wall, TETROMINO_J, 0, 1);
  tetromino_push(wall, TETROMINO_J, 2, 0);
  // 1 - XXXX......
  // 0 - XXXX......
  uint8_t e[WALL_WIDTH] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  ExpectLine(0, e);
  ExpectLine(1, e);
}

TEST_F(Tetromino, J2)
{
  tetromino_push(wall, TETROMINO_J, 0, 0);
  tetromino_push(wall, TETROMINO_J, 2, 0);
  // 2 - XXX.......
  // 1 - X.X.......
  // 0 - XXX.......
  uint8_t e1[WALL_WIDTH] = { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
  uint8_t e2[WALL_WIDTH] = { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 };
  ExpectLine(0, e1);
  ExpectLine(1, e2);
  ExpectLine(2, e1);
}

TEST_F(Tetromino, J3)
{
  tetromino_push(wall, TETROMINO_J, 3, 0);
  tetromino_push(wall, TETROMINO_J, 1, 2);
  // 2 - XXX........
  // 1 - .XX........
  // 0 - .XXX.......
  uint8_t e1[WALL_WIDTH] = { 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  uint8_t e2[WALL_WIDTH] = { 0, 1, 1, 0, 0, 0, 0, 0, 0 };
  uint8_t e3[WALL_WIDTH] = { 0, 1, 1, 1, 0, 0, 0, 0, 0 };
  ExpectLine(2, e1);
  ExpectLine(1, e2);
  ExpectLine(0, e3);
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
