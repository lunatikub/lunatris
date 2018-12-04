#include "test_tetromino.hh"

void Tetromino::SetUp(void)
{
  wall_create(&wall);
}

void Tetromino::TearDown(void)
{
  wall_destroy(wall);
}

void Tetromino::ExpectLine(uint8_t y, uint8_t expected[WALL_WIDTH])
{
  for (unsigned x = 0; x < WALL_WIDTH; ++x) {
    EXPECT_EQ(wall_get(wall, y, x), expected[x]);
  }
}
