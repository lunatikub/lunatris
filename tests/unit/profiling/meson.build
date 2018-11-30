test_profiling_src = files(
  'test_memory.cc',
  'test_perf.cc',
)

unit_test_profiling = executable(
  'unit-test-profiling',
  test_profiling_src,
  profiling_src,
  main_test_src,
  include_directories: [ lunatris_inc ],
  c_args: common_args,
  cpp_args: common_args + [ '-std=gnu++11' ],
  dependencies: [ gtest_dep ],
)

run_target(
  'unit-test-profiling',
  command: [ unit_test_profiling.full_path() ],
  depends: unit_test_profiling,
)

test('unit-test-profiling', unit_test_profiling)
