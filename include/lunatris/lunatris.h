#ifndef __LUNATRIS_H__
#define __LUNATRIS_H__

/**
 * Dimension of a tetris table.
 */
# define WALL_WIDTH (10)
# define WALL_HEIGHT (20)

/* Opaque structure for a wall. */
typedef struct wall* wall_handle;

/**
 * Cell can be empty or filled.
 */
enum cell {
  EMPTY = 0,
  FILLED,
};

#endif /* !__LUNATRIS_H__ */
