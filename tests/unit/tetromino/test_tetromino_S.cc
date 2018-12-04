#include "test_tetromino.hh"

TEST_F(Tetromino, SRotate)
{
  for (unsigned i = 0; i < 2; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_S, i, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_S, 2, 0), TETROMINO_EINVAL_ROTATE);
}

TEST_F(Tetromino, SXaxis)
{
  EXPECT_EQ(tetromino_push(wall, TETROMINO_S, 1, 8), TETROMINO_OK);
  EXPECT_EQ(tetromino_push(wall, TETROMINO_S, 1, 9), TETROMINO_EINVAL_X);
}

TEST_F(Tetromino, SYaxis)
{
  for (unsigned i = 0; i < 10; ++i) {
    EXPECT_EQ(tetromino_push(wall, TETROMINO_S, 0, 0), TETROMINO_OK);
  }
  EXPECT_EQ(tetromino_push(wall, TETROMINO_S, 0, 0), TETROMINO_EINVAL_Y);
}

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

  uint8_t e4[WALL_WIDTH] = { 0, 1, 1, 0, 0, 0, 0, 0, 0 };
  uint8_t e3[WALL_WIDTH] = { 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  uint8_t e2[WALL_WIDTH] = { 0, 0, 1, 1, 0, 0, 0, 0, 0 };
  uint8_t e1[WALL_WIDTH] = { 0, 1, 1, 1, 0, 0, 0, 0, 0 };
  uint8_t e0[WALL_WIDTH] = { 1, 1, 0, 0, 0, 0, 0, 0, 0 };

  ExpectLine(4, e4);
  ExpectLine(3, e3);
  ExpectLine(2, e2);
  ExpectLine(1, e1);
  ExpectLine(0, e0);
}


  // for (int x = 0; x < 10; ++x) {
  //   std::cout << x;
  // }
  // std::cout << std::endl;
  // std::cout << std::endl;

  // for (int y = 19; y >= 0; --y) {
  //   for (int x = 0; x < 10; ++x) {
  //     if (wall_get(wall, y, x)) {
  //       std::cout << "X";
  //     } else {
  //       std::cout << ".";
  //     }
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;
