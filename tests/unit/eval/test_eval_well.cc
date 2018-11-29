#include <lunatris_test.hh>

extern "C" {
#include <lunatris/eval/eval.h>
}

TEST_F(LunatrisTest, EvalWell)
{
  // 1 - X.........
  // 0 - X.........
  wall_set(wall, 1, 0);
  wall_set(wall, 0, 0);
  EXPECT_EQ(eval_well(wall), 0u);

  // 1 - X.X.......
  // 0 - X.X.......
  wall_set(wall, 1, 2);
  wall_set(wall, 0, 2);
  EXPECT_EQ(eval_well(wall), 3u);

  // 2 - X.........
  // 1 - X.X.......
  // 0 - X.X.......
  wall_set(wall, 2, 0);
  EXPECT_EQ(eval_well(wall), 3u);

  // 2 - X......X.X
  // 1 - X.X....X.X
  // 0 - X.X....X.X
  wall_set(wall, 0, 7);
  wall_set(wall, 1, 7);
  wall_set(wall, 2, 7);
  wall_set(wall, 0, 9);
  wall_set(wall, 1, 9);
  wall_set(wall, 2, 9);
  EXPECT_EQ(eval_well(wall), 9u);
}

TEST_F(LunatrisTest, EvalWellLimit)
{
  // 1 - .X........
  // 0 - .X........
  wall_set(wall, 0, 1);
  wall_set(wall, 1, 1);
  EXPECT_EQ(eval_well(wall), 3u);

  // 1 - .X......X.
  // 0 - .X......X.
  wall_set(wall, 0, 8);
  wall_set(wall, 1, 8);
  EXPECT_EQ(eval_well(wall), 6u);
}

TEST_F(LunatrisTest, EvalWellCascade)
{
  // 4 - X.........
  // 3 - X.X.......
  // 2 - X.X.X.....
  // 1 - X.X.X.X...
  // 0 - X.X.X.X.X.
  //     ----------
  //     0123456789

  // col 1: 4 + 3 + 2 + 1 = 10
  // col 3: 3 + 2 + 1 = 6
  // col 5: 2 + 1 = 3
  // col 7: 1
  // col 9: 1
  // sum = 10 + 6 + 3 + 1 + 1 = 21

  wall_set(wall, 4, 0);
  wall_set(wall, 3, 0);
  wall_set(wall, 2, 0);
  wall_set(wall, 1, 0);
  wall_set(wall, 0, 0);

  wall_set(wall, 3, 2);
  wall_set(wall, 2, 2);
  wall_set(wall, 1, 2);
  wall_set(wall, 0, 2);

  wall_set(wall, 2, 4);
  wall_set(wall, 1, 4);
  wall_set(wall, 0, 4);

  wall_set(wall, 1, 6);
  wall_set(wall, 0, 6);

  wall_set(wall, 0, 8);

  EXPECT_EQ(eval_well(wall), 21u);
}
