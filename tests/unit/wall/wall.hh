#ifndef WALL_HH_
# define WALL_HH_

#include <gtest/gtest.h>

extern "C" {
#include <lunatris/wall/wall.h>
#include "eval.h"
#include "wall_internal.h"
}

class Wall: public testing::Test
{
protected:
  wall_handle wall;
  virtual void SetUp(void);
  virtual void TearDown(void);

  void SetLine(uint8_t y, uint8_t x_start, uint8_t x_end);
  void ExpectLine(uint8_t y, uint8_t expected[WALL_WIDTH]);
  void Dump(void);
};

#endif /* !WALL_HH_ */
