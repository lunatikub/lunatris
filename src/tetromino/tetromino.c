#include <assert.h>
#include <lunatris/tetromino/tetromino.h>

/**
 * A tetromino is defined by an array of cells of dim 4x4.
 */
#define TETROMINO_SZ (4)

/**
 * Definition of a tetromino.
 */
struct tetromino_def {
  uint8_t t[TETROMINO_SZ][TETROMINO_SZ];
  /* All the following fields will
     be automaticly completed at initialization
     by @c tetromino_defs(). */
  uint8_t hc[TETROMINO_SZ]; /* Height by column. */
  uint8_t w; /* Width of the tetromino. */
  uint8_t h; /* Height of the tetromino. */
};

/**
 * Import all definitions of each tetromino.
 */
#include "tetromino_I_def.h"
#include "tetromino_O_def.h"
#include "tetromino_L_def.h"

/**
 * Return true if the tetromino can be push at the x position.
 * Otherwise return fasle.
 */
static bool
check_x_axis(const struct tetromino_def *def, uint8_t x)
{
  if (x > WALL_WIDTH - def->w) {
    return false;
  }
  return true;
}

/**
 * Return the definition of the tetromino.
 */
static struct tetromino_def*
tetromino_def_get(enum tetromino tetromino, uint8_t *nr_rotate)
{
#define DEF_CASE(tetromino)                             \
  case TETROMINO_ ## tetromino:                         \
    *nr_rotate = TETROMINO_ ## tetromino ## _SZ;        \
    return tetromino_ ## tetromino;

  switch (tetromino) {
    DEF_CASE(I);
    DEF_CASE(O);
    DEF_CASE(L);
    default:
      return NULL;
  };

#undef DEF_CASE
}

/**
 * Get the height ot the tetromino to push at the x position.
 */
static uint8_t
tetromino_height_get(const struct tetromino_def *def,
                     wall_t wall, uint8_t x)
{
  uint8_t tetromino_h = 0;

  for (uint8_t i = 0; i < def->w; ++i) {
    uint8_t h = wall_height_get(wall, i + x) - def->hc[i] + 1;
    if (tetromino_h < h) {
      tetromino_h = h;
    }
  }

  return tetromino_h;
}

/**
 * Set the cells of the wall when the tetromino
 * is pushed at the x position.
 */
static void
tetromino_wall_set(const struct tetromino_def *def,
                   wall_t wall, uint8_t h, uint8_t x)
{
  for (uint8_t i = 0; i < TETROMINO_SZ; ++i) {
    for (uint8_t j = 0; j < TETROMINO_SZ; ++j) {
      if (def->t[i][j]) {
        wall_set(wall, TETROMINO_SZ - i + h - 1, j + x);
      }
    }
  }
}

enum tetromino_error
tetromino_push(wall_t wall, enum tetromino tetromino,
               uint8_t rotate, uint8_t x)
{
  uint8_t nr_rotate;
  const struct tetromino_def *defs = tetromino_def_get(tetromino, &nr_rotate);
  assert(defs != NULL);

  if (rotate >= nr_rotate) {
    return TETROMINO_EINVAL_ROTATE;
  }

  const struct tetromino_def *def = &defs[rotate];

  if (check_x_axis(def, x) == false) {
    return TETROMINO_EINVAL_X;
  }

  uint8_t h = tetromino_height_get(def, wall, x);
  if (h - 1 + def->h > WALL_HEIGHT) {
    return TETROMINO_EINVAL_Y;
  }

  tetromino_wall_set(def, wall, h, x);
  return TETROMINO_OK;
}

/**
 * Determinate the height of each column of
 * a tetromino definition.
 */
static void tetromino_def_hc(struct tetromino_def *def)
{
  int8_t x;
  int8_t y;

  for (x = 0; x < TETROMINO_SZ; ++x) {
    uint8_t h = 0;
    for (y = TETROMINO_SZ - 1; y >= 0; --y) {
      if (def->t[y][x] == FILLED && h == 0) {
        h = TETROMINO_SZ - y;
      }
    }
    def->hc[x] = h;
  }
}

/**
 * Determinate the width of a tetromino definition.
 */
static void tetromino_def_w(struct tetromino_def *def)
{
  uint8_t w = 0;

  for (uint8_t x = 0; x < TETROMINO_SZ; ++x) {
    for (uint8_t y = 0; y < TETROMINO_SZ; ++y) {
      if (def->t[y][x] == FILLED) {
        ++w;
        break;
      }
    }
  }
  def->w = w;
}

static void tetromino_def_h(struct tetromino_def *def)
{
  for (uint8_t y = 0; y < TETROMINO_SZ; ++y) {
    for (uint8_t x = 0; x < TETROMINO_SZ; ++x) {
      if (def->t[y][x] == FILLED) {
        def->h = TETROMINO_SZ - y;
        return;
      }
    }
  }
}

/**
 * Determinate properties definition for each
 * rotation of a tetromino.
 */
static void tetromino_def(struct tetromino_def *def, size_t sz)
{
  for (uint8_t i = 0; i < sz; ++i) {
    tetromino_def_hc(&def[i]);
    tetromino_def_w(&def[i]);
    tetromino_def_h(&def[i]);
  }
}

/**
 * Determinate properties of each tetromino.
 */
static void __attribute__((constructor)) tetromino_defs(void)
{
#define TETROMINO_DEF(tetromino) \
  tetromino_def(tetromino_ ## tetromino, \
                TETROMINO_ ## tetromino ## _SZ)

  TETROMINO_DEF(I);
  TETROMINO_DEF(O);
  TETROMINO_DEF(L);

#undef TETROMINO_DEF
}
