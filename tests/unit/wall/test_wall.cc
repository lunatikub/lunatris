#include "wall.hh"

TEST_F(Wall, Init)
{
  uint8_t empty_line[WALL_WIDTH] = { 0 };

  for (unsigned y = 0; y < WALL_HEIGHT; ++y) {
    ExpectLine(y, empty_line);
  }
}

TEST_F(Wall, WrongCoord)
{
  EXPECT_DEATH(wall_set(wall, -1, 0), "Assertion `y < WALL_HEIGHT' failed.");
  EXPECT_DEATH(wall_set(wall, 0, -1), "Assertion `x < WALL_WIDTH' failed.");
}

TEST_F(Wall, SetAlreadySet)
{
  wall_set(wall, 0, 0);
  EXPECT_DEATH(wall_set(wall, 0, 0), "Assertion `w->table.* == EMPTY' failed.");
}

TEST_F(Wall, BasicSet)
{
  EXPECT_EQ(EMPTY, wall_get(wall, 0, 0));
  wall_set(wall, 0, 0);
  EXPECT_EQ(FILLED, wall_get(wall, 0, 0));
  wall_set(wall, 5, 5);
  EXPECT_EQ(FILLED, wall_get(wall, 5, 5));
}

/**
 *      0123456789
 * 19 - XXXXXXXXX.
 * ...
 * 1  - XXXXXXXXX.
 * 0  - XXXXXXXXX.
 */
TEST_F(Wall, MultipleSet)
{
  for (unsigned y = 0; y < WALL_HEIGHT; ++y) {
    SetLine(y, 0, 8); // Don't complete the line
  }

  uint8_t expected[WALL_WIDTH] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };

  for (unsigned y = 0; y < WALL_HEIGHT; ++y) {
    ExpectLine(y, expected);
  }
}

/**
 *     0123456789
 * 4 - X.........
 * 3 - XXX.......
 * 2 - XXXXXX....
 * 1 - XXXXXXXXX.
 * 0 - XXXXXXXXXX
 */
TEST_F(Wall, BasicCompleteLine)
{
  SetLine(4, 0, 0);
  SetLine(3, 0, 2);
  SetLine(2, 0, 5);
  SetLine(1, 0, 8);
  SetLine(0, 0, 8);

  EXPECT_EQ(5, wall_height_get(wall, 0));
  EXPECT_EQ(4, wall_height_get(wall, 1));
  EXPECT_EQ(4, wall_height_get(wall, 2));
  EXPECT_EQ(3, wall_height_get(wall, 3));
  EXPECT_EQ(3, wall_height_get(wall, 5));
  EXPECT_EQ(2, wall_height_get(wall, 6));
  EXPECT_EQ(2, wall_height_get(wall, 7));
  EXPECT_EQ(2, wall_height_get(wall, 8));
  EXPECT_EQ(0, wall_height_get(wall, 9));

  wall_set(wall, 0, 9); // complete the line 0

  EXPECT_EQ(4, wall_height_get(wall, 0));
  EXPECT_EQ(3, wall_height_get(wall, 1));
  EXPECT_EQ(3, wall_height_get(wall, 2));
  EXPECT_EQ(2, wall_height_get(wall, 3));
  EXPECT_EQ(2, wall_height_get(wall, 5));
  EXPECT_EQ(1, wall_height_get(wall, 6));
  EXPECT_EQ(1, wall_height_get(wall, 7));
  EXPECT_EQ(1, wall_height_get(wall, 8));
  EXPECT_EQ(0, wall_height_get(wall, 9));

  uint8_t expected[4][WALL_WIDTH] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  };

  ExpectLine(0, expected[0]);
  ExpectLine(1, expected[1]);
  ExpectLine(2, expected[2]);
  ExpectLine(3, expected[3]);
}

/**
 *      0123456789
 * 19 - XXXXXXXXXO
 * ...
 * 1  - XXXXXXXXXO
 * 0  - XXXXXXXXXO
 *
 * 'O' in a seconde time
 */
TEST_F(Wall, ComplexCompleteLine)
{
  for (unsigned y = 0; y < WALL_HEIGHT; ++y) {
    SetLine(y, 0, 8); // Don't complete the line
  }

  uint8_t almost_full_line[WALL_WIDTH] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
  uint8_t empty_line[WALL_WIDTH] = { 0 };

  for (int i = 0; i < WALL_HEIGHT; ++i) {
    wall_set(wall, 0, 9);
    for (int j = WALL_HEIGHT - 1; j > WALL_HEIGHT - 1 - i; --j) {
      ExpectLine(j, empty_line);
    }
    for (int j = WALL_HEIGHT - 2 - i; j > 0; --j) {
      ExpectLine(j, almost_full_line);
    }
  }
}
