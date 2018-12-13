#ifndef TEST_EVAL_HH_
# define TEST_EVAL_HH_

#include <gtest/gtest.h>

extern "C" {
#include <lunatris/wall/wall.h>
#include <lunatris/eval/eval.h>
#include <lunatris/tetromino/tetromino.h>
}

class Eval: public testing::Test
{
protected:
  wall_t wall;
  virtual void SetUp(void);
  virtual void TearDown(void);

  void SetLine(uint8_t y, uint8_t x_start, uint8_t x_end);
  void ExpectLine(uint8_t y, uint8_t expected[WALL_WIDTH]);
};

#endif /* !TEST_EVAL_HH_ */
