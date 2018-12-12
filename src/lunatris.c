#include <lunatris/lunatris.h>
#include <lunatris/displayer/displayer.h>
#include <lunatris/wall/wall.h>
#include <lunatris/tetromino/tetromino.h>

struct lunatris {
  wall_t wall;
  displayer_t disp;
};

static void lunatris_init(struct lunatris *lunatris)
{
  wall_create(&lunatris->wall);
  displayer_start(&lunatris->disp, lunatris->wall);
}

static void lunatris_cleanup(struct lunatris *lunatris)
{
  displayer_stop(lunatris->disp);
  wall_destroy(lunatris->wall);
}

int main(void)
{
  struct lunatris lunatris;

  lunatris_init(&lunatris);

  #include <unistd.h>
  sleep(1);
  tetromino_push(lunatris.wall, TETROMINO_I, 0, 0);
  displayer_notify(lunatris.disp);
  sleep(1);
  tetromino_push(lunatris.wall, TETROMINO_I, 1, 0);
  displayer_notify(lunatris.disp);
  sleep(1);
  tetromino_push(lunatris.wall, TETROMINO_I, 0, 0);
  displayer_notify(lunatris.disp);
  sleep(1);

  lunatris_cleanup(&lunatris);

  return 0;
}
