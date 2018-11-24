test_wall_src = files(
  'main.cc',
  'wall.cc',
  'test_wall.cc',
  'test_eval.cc',
)

unit_test_wall = executable(
  'unit-test-wall',
  test_wall_src,
  wall_src,
  include_directories: [ wall_internal_inc, lunatris_inc ],
  c_args: common_args,
  cpp_args: common_args + [ '-std=gnu++11' ],
  dependencies: [ gtest_dep ],
)

run_target(
  'unit-test-wall',
  command: [ unit_test_wall.full_path() ],
  depends: unit_test_wall,
)

test('unit-test-wall', unit_test_wall)
