#ifndef TEST_TETROMINO_HH_
# define TEST_TETROMINO_HH_

#include <gtest/gtest.h>

extern "C" {
#include <lunatris/tetromino/tetromino.h>
}

class Tetromino: public testing::Test
{
protected:
  wall_t wall;
  virtual void SetUp(void);
  virtual void TearDown(void);
  void ExpectLine(uint8_t y, uint8_t expected[WALL_WIDTH]);
};

#endif /* !TEST_TETROMINO_HH_ */
