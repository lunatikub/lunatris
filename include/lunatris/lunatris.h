#ifndef __LUNATRIS_H__
#define __LUNATRIS_H__

/**
 * Dimension of a tetris wall.
 */
# define WALL_WIDTH (10)
# define WALL_HEIGHT (20)

/**
 * State of the cell.
 */
enum cell {
  EMPTY = 0,
  FILLED,
};

#endif /* !__LUNATRIS_H__ */
