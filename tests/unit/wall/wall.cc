#include "wall.hh"

void Wall::SetUp(void)
{
  wall_create(&wall);
}

void Wall::TearDown(void)
{
  wall_destroy(wall);
}

void Wall::SetLine(uint8_t y, uint8_t x_start, uint8_t x_end)
{
  for (unsigned x = x_start; x <= x_end; ++x) {
    wall_set(wall, y, x);
  }
}

void Wall::ExpectLine(uint8_t y, uint8_t expected[WALL_WIDTH])
{
  for (unsigned x = 0; x < WALL_WIDTH; ++x) {
    EXPECT_EQ(wall_get(wall, y, x), expected[x]);
  }
}

void Wall::Dump(void)
{
  std::cout << "      ";
  for (unsigned x = 0; x < WALL_WIDTH; ++x) {
    std::cout << x;
  }
  std::cout << std::endl;
  std::cout << "      ";
  for (unsigned x = 0; x < WALL_WIDTH; ++x) {
    std::cout << "-";
  }
  std::cout << std::endl;

  for (int y = 19; y >= 0; --y) {
    std::cout << 19 - y;
    if (y >= 10) {
      std::cout << " ";
    }
    std::cout << " ";
    std::cout << y << " ";
    if (y < 10) {
      std::cout << " ";
    }
    for (int x = 0; x < WALL_WIDTH; ++x) {
      std::cout << wall_get(wall, y, x);
    }
    std::cout << std::endl;
  }

  std::cout << "      ";
  for (unsigned x = 0; x < WALL_WIDTH; ++x) {
    std::cout << "-";
  }
  std::cout << std::endl;
  std::cout << "      ";
  for (unsigned x = 0; x < WALL_WIDTH; ++x) {
    std::cout << x;
  }
  std::cout << std::endl;
}
