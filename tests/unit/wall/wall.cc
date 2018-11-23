#include <gtest/gtest.h>

extern "C" {
#include <lunatris/wall/wall.h>
}

GTEST_API_ int
main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

class Wall: public testing::Test
{
};

TEST_F(Wall, Basic)
{
}
