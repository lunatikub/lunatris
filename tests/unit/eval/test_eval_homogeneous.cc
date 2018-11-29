#include <lunatris_test.hh>

extern "C" {
#include <lunatris/eval/eval.h>
}

TEST_F(LunatrisTest, EvalDeltaLine)
{
  uint32_t dl = 0;

  EXPECT_EQ(eval_delta_line(wall), dl);

  // 0 - X.........
  wall_set(wall, 0, 0);
  ++dl;
  EXPECT_EQ(eval_delta_line(wall), dl);

  // 1 - X.X.X.X.X.
  wall_set(wall, 1, 0);
  wall_set(wall, 1, 2);
  wall_set(wall, 1, 4);
  wall_set(wall, 1, 6);
  wall_set(wall, 1, 8);
  dl += 9;
  EXPECT_EQ(eval_delta_line(wall), dl);

  // 2 - XXXXX.....
  SetLine(2, 0, 5);
  ++dl;
  EXPECT_EQ(eval_delta_line(wall), dl);

  // 3 - .XX.......
  SetLine(3, 1, 2);
  dl += 2;
  EXPECT_EQ(eval_delta_line(wall), dl);
}

TEST_F(LunatrisTest, EValDeltaCol)
{
  uint32_t dc = 0;

  EXPECT_EQ(eval_delta_col(wall), dc);

  // 1 - ..........
  // 0 - X.........
  wall_set(wall, 0, 0);
  ++dc;
  EXPECT_EQ(eval_delta_col(wall), dc);

  // 1 - XXXXXXXXX.
  // 0 - X.........
  SetLine(1, 0, 8);
  dc = 17;
  EXPECT_EQ(eval_delta_col(wall), dc);

  // 2 - X.........
  // 1 - XXXXXXXXX.
  // 0 - X.........
  wall_set(wall, 2, 0);
  dc = 17;
  EXPECT_EQ(eval_delta_col(wall), dc);

  // 3 - .XX.......
  // 2 - X.........
  // 1 - XXXXXXXXX.
  // 0 - X.........
  wall_set(wall, 3, 1);
  wall_set(wall, 3, 2);
  dc += 4;
  EXPECT_EQ(eval_delta_col(wall), dc);
}
