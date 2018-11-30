#include "test_eval.hh"

TEST_F(Eval, Hole)
{
  EXPECT_EQ(eval_hole(wall), 0u);

  // 0 - X.........
  wall_set(wall, 0, 0);
  EXPECT_EQ(eval_hole(wall), 0u);

  // 1 - .X........
  // 0 - X.........
  wall_set(wall, 1, 1);
  EXPECT_EQ(eval_hole(wall), 1u);

  // 2 - .XX.......
  // 1 - .X........
  // 0 - X.........
  SetLine(2, 1, 2);
  EXPECT_EQ(eval_hole(wall), 3u);

  // 2 - .XX........
  // 1 - .X.........
  // 0 - XXXXXXXXXXX
  SetLine(0, 1, 9);
  EXPECT_EQ(eval_hole(wall), 1u);

  // 2 - X.........X
  // 1 - .XX........
  // 0 - .X.........
  wall_set(wall, 2, 0);
  wall_set(wall, 2, 9);
  EXPECT_EQ(eval_hole(wall), 5u);
}
