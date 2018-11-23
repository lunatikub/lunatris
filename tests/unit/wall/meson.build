test_wall_src = files(
  'wall.cc',
)

test_wall_inc = [
]

unit_test_wall = executable(
  'unit-test-wall',
  test_wall_src,
  wall_src,
  include_directories: [ test_wall_inc, lunatris_inc ],
  c_args: common_args,
  cpp_args: common_args,
  dependencies: [ gtest_dep ],
)

run_target(
  'unit-test-wall',
  command: [ unit_test_wall.full_path() ],
  depends: unit_test_wall,
)

test('unit-test-wall', unit_test_wall)
