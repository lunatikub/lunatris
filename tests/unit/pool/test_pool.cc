#include <lunatris_test.hh>

TEST_F(LunatrisTest, Pool)
{
  const size_t pool_sz = 12;
  uint32_t *data[pool_sz];

  pool_create(&pool, pool_sz, sizeof(data[0]));
  {
    for (uint32_t i = 0; i < pool_sz; ++i) {
      data[i] = (uint32_t*)pool_reserve(pool);
      EXPECT_NE(data[i], nullptr);
      *data[i] = i;
    }

    void *tmp = pool_reserve(pool);
    EXPECT_EQ(tmp, nullptr);

    pool_release(pool, data[4]);
    data[4] = (uint32_t*)pool_reserve(pool);
    EXPECT_NE(data[4], nullptr);
    EXPECT_EQ(*data[4], 0u);
    *data[4] = 4;

    for (uint32_t i = 0; i < pool_sz; ++i) {
      EXPECT_EQ(*data[i], i);
      pool_release(pool, data[i]);
    }
  }
  EXPECT_EQ(pool_destroy(pool), true);
}

TEST_F(LunatrisTest, PoolNoRelease)
{
  pool_create(&pool, 1, 1);
  void *tmp = pool_reserve(pool);
  EXPECT_EQ(pool_destroy(pool), false);
  pool_release(pool, tmp);
  EXPECT_EQ(pool_destroy(pool), true);
}

TEST_F(LunatrisTest, PoolExtend)
{
  void *ptr[5];

  pool_create(&pool, 2, 1);

  EXPECT_NE((ptr[0] = pool_reserve(pool)), nullptr);
  EXPECT_NE((ptr[1] = pool_reserve(pool)), nullptr);
  pool_extend(pool, 1);
  EXPECT_NE((ptr[2] = pool_reserve(pool)), nullptr);
  EXPECT_NE(ptr[2], nullptr);
  EXPECT_EQ(pool_reserve(pool), nullptr);
  pool_extend(pool, 2);
  EXPECT_NE((ptr[3] = pool_reserve(pool)), nullptr);
  EXPECT_NE((ptr[4] = pool_reserve(pool)), nullptr);

  for (uint32_t i = 0; i < 5; ++i) {
    pool_release(pool, ptr[i]);
  }

  EXPECT_EQ(pool_destroy(pool), true);
}
