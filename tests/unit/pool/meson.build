test_pool_src = files(
  'test_pool.cc',
)

unit_test_pool = executable(
  'unit-test-pool',
  test_pool_src,
  pool_src,
  profiling_src,
  main_test_src,
  include_directories: [ lunatris_inc  ],
  c_args: common_args,
  cpp_args: common_args + [ '-std=gnu++11' ],
  dependencies: [ gtest_dep ],
)

run_target(
  'unit-test-pool',
  command: [ unit_test_pool.full_path() ],
  depends: unit_test_pool,
)

test('unit-test-pool', unit_test_pool)
