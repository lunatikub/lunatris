test_tetromino_src = files(
  'test_tetromino.cc',
  'test_tetromino_I.cc',
  'test_tetromino_O.cc',
  'test_tetromino_L.cc',
  'test_tetromino_J.cc',
)

unit_test_tetromino = executable(
  'unit-test-tetromino',
  test_tetromino_src,
  tetromino_src,
  wall_src,
  profiling_src,
  main_test_src,
  include_directories: [ lunatris_inc ],
  c_args: common_args,
  cpp_args: common_args + [ '-std=gnu++11' ],
  dependencies: [ gtest_dep ]
)

run_target(
  'unit-test-tetromino',
  command: [ unit_test_tetromino.full_path() ],
  depends: unit_test_tetromino,
)

test('unit-test-tetromino', unit_test_tetromino)
