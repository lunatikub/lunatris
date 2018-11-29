test_eval_src = files(
  'test_eval_well.cc',
  'test_eval_homogeneous.cc',
  'test_eval_hole.cc',
)

unit_test_eval = executable(
  'unit-test-eval',
  test_eval_src,
  eval_src,
  wall_src,
  test_common_src,
  include_directories: [ lunatris_inc, common_test_inc ],
  c_args: common_args,
  cpp_args: common_args + [ '-std=gnu++11' ],
  dependencies: [ gtest_dep ],
)

run_target(
  'unit-test-eval',
  command: [ unit_test_eval.full_path() ],
  depends: unit_test_eval,
)

test('unit-test-eval', unit_test_eval)
