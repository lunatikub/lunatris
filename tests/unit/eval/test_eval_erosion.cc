#include "test_eval.hh"

TEST_F(Eval, NrLinesCompleted)
{
  for (int i = 0; i < 9; ++i) {
    tetromino_push(wall, TETROMINO_I, 1, i);
    EXPECT_EQ(wall_nr_line_completed_get(wall), 0);
  }
  tetromino_push(wall, TETROMINO_I, 1, 9);
  EXPECT_EQ(wall_nr_line_completed_get(wall), 4);

  for (int i = 0; i < 8; i += 2) {
    tetromino_push(wall, TETROMINO_O, 0, i);
    EXPECT_EQ(wall_nr_line_completed_get(wall), 0);
  }
  tetromino_push(wall, TETROMINO_O, 0, 8);
  EXPECT_EQ(wall_nr_line_completed_get(wall), 2);

  tetromino_push(wall, TETROMINO_T, 0, 0);
  EXPECT_EQ(wall_nr_line_completed_get(wall), 0);
  tetromino_push(wall, TETROMINO_T, 0, 3);
  EXPECT_EQ(wall_nr_line_completed_get(wall), 0);
  tetromino_push(wall, TETROMINO_T, 0, 6);
  EXPECT_EQ(wall_nr_line_completed_get(wall), 0);


  tetromino_push(wall, TETROMINO_I, 1, 9);
  EXPECT_EQ(wall_nr_line_completed_get(wall), 1);
}
