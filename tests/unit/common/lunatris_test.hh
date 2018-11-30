#ifndef WALL_HH_
# define WALL_HH_

#include <gtest/gtest.h>

extern "C" {
#include <lunatris/wall/wall.h>
#include <lunatris/pool/pool.h>
}

class LunatrisTest: public testing::Test
{
protected:
  wall_t wall;
  pool_t pool;
  virtual void SetUp(void);
  virtual void TearDown(void);

  void SetLine(uint8_t y, uint8_t x_start, uint8_t x_end);
  void ExpectLine(uint8_t y, uint8_t expected[WALL_WIDTH]);
  void Dump(void);
};

#endif /* !WALL_HH_ */
