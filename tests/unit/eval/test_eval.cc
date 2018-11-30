#include "test_eval.hh"

void Eval::SetUp(void)
{
  wall_create(&wall);
}

void Eval::TearDown(void)
{
  wall_destroy(wall);
}

void Eval::SetLine(uint8_t y, uint8_t x_start, uint8_t x_end)
{
  for (unsigned x = x_start; x <= x_end; ++x) {
    wall_set(wall, y, x);
  }
}

void Eval::ExpectLine(uint8_t y, uint8_t expected[WALL_WIDTH])
{
  for (unsigned x = 0; x < WALL_WIDTH; ++x) {
    EXPECT_EQ(wall_get(wall, y, x), expected[x]);
  }
}
