#include <lunatris_test.hh>

extern "C" {
#include <lunatris/eval/eval.h>
}

TEST_F(LunatrisTest, EvalDL)
{
  uint32_t dl = 0;

  EXPECT_EQ(eval_dl(wall), dl);

  // 0 - X.........
  wall_set(wall, 0, 0);
  ++dl;
  EXPECT_EQ(eval_dl(wall), dl);

  // 1 - X.X.X.X.X.
  wall_set(wall, 1, 0);
  wall_set(wall, 1, 2);
  wall_set(wall, 1, 4);
  wall_set(wall, 1, 6);
  wall_set(wall, 1, 8);
  dl += 9;
  EXPECT_EQ(eval_dl(wall), dl);

  // 2 - XXXXX.....
  SetLine(2, 0, 5);
  ++dl;
  EXPECT_EQ(eval_dl(wall), dl);

  // 3 - .XX.......
  SetLine(3, 1, 2);
  dl += 2;
  EXPECT_EQ(eval_dl(wall), dl);
}

TEST_F(LunatrisTest, EvalDC)
{
  uint32_t dc = 0;

  EXPECT_EQ(eval_dl(wall), dc);

  // 1 - ..........
  // 0 - X.........
  wall_set(wall, 0, 0);
  ++dc;
  EXPECT_EQ(eval_dc(wall), dc);

  // 1 - XXXXXXXXX.
  // 0 - X.........
  SetLine(1, 0, 8);
  dc = 17;
  EXPECT_EQ(eval_dc(wall), dc);

  // 2 - X.........
  // 1 - XXXXXXXXX.
  // 0 - X.........
  wall_set(wall, 2, 0);
  dc = 17;
  EXPECT_EQ(eval_dc(wall), dc);

  // 3 - .XX.......
  // 2 - X.........
  // 1 - XXXXXXXXX.
  // 0 - X.........
  wall_set(wall, 3, 1);
  wall_set(wall, 3, 2);
  dc += 4;
  EXPECT_EQ(eval_dc(wall), dc);
}

TEST_F(LunatrisTest, EvalH)
{
  EXPECT_EQ(eval_h(wall), 0u);

  // 0 - X.........
  wall_set(wall, 0, 0);
  EXPECT_EQ(eval_h(wall), 0u);

  // 1 - .X........
  // 0 - X.........
  wall_set(wall, 1, 1);
  EXPECT_EQ(eval_h(wall), 1u);

  // 2 - .XX.......
  // 1 - .X........
  // 0 - X.........
  SetLine(2, 1, 2);
  EXPECT_EQ(eval_h(wall), 3u);

  // 2 - .XX........
  // 1 - .X.........
  // 0 - XXXXXXXXXXX
  SetLine(0, 1, 9);
  EXPECT_EQ(eval_h(wall), 1u);

  // 2 - X.........X
  // 1 - .XX........
  // 0 - .X.........
  wall_set(wall, 2, 0);
  wall_set(wall, 2, 9);
  EXPECT_EQ(eval_h(wall), 5u);

}

TEST_F(LunatrisTest, EvalW)
{
  // 1 - X.........
  // 0 - X.........
  wall_set(wall, 1, 0);
  wall_set(wall, 0, 0);
  EXPECT_EQ(eval_w(wall), 0u);

  // 1 - X.X.......
  // 0 - X.X.......
  wall_set(wall, 1, 2);
  wall_set(wall, 0, 2);
  EXPECT_EQ(eval_w(wall), 3u);

  // 2 - X.........
  // 1 - X.X.......
  // 0 - X.X.......
  wall_set(wall, 2, 0);
  EXPECT_EQ(eval_w(wall), 3u);

  // 2 - X......X.X
  // 1 - X.X....X.X
  // 0 - X.X....X.X
  wall_set(wall, 0, 7);
  wall_set(wall, 1, 7);
  wall_set(wall, 2, 7);
  wall_set(wall, 0, 9);
  wall_set(wall, 1, 9);
  wall_set(wall, 2, 9);
  EXPECT_EQ(eval_w(wall), 9u);
}

TEST_F(LunatrisTest, EvalW_limit)
{
  // 1 - .X........
  // 0 - .X........
  wall_set(wall, 0, 1);
  wall_set(wall, 1, 1);
  EXPECT_EQ(eval_w(wall), 3u);

  // 1 - .X......X.
  // 0 - .X......X.
  wall_set(wall, 0, 8);
  wall_set(wall, 1, 8);
  EXPECT_EQ(eval_w(wall), 6u);
}
