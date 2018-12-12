#include <pthread.h>
#include <curses.h>

#include <lunatris/profiling/memory.h>
#include <lunatris/displayer/displayer.h>
#include <lunatris/wall/wall.h>

/**
 * Main structure for the displayer.
 */
struct displayer {
  pthread_t thread;
  pthread_cond_t cond;
  pthread_mutex_t lock;
  bool stop; /* Notify the main thread to stop. */
  wall_t wall; /* Reference to the main wall to display. */
};

/**
 *         0
 *       0 +-------->
 *         |
 *         |
 * Y( ) -> |
 *         v
 */
#define Y(Y) ((Y) + 1)

/**
 *     X( )
 *     |
 *   0 v
 * 0 +-------->
 *   |
 *   |
 *   |
 *   v
 */
#define X(X) ((X) + 1)

/**
 * Margin of the decoration on x-axis.
 */
#define X_MARGIN (3)

/**
 * Display the decoration of the wall.
 */
static void displayer_decoration(void)
{
  for (int y = 0; y < WALL_HEIGHT; ++y) {
    mvprintw(Y(y), X(0), "%2u|", WALL_HEIGHT - y);
    mvprintw(Y(y), X(WALL_WIDTH + X_MARGIN), "|");
  }
  for (int x = 0; x < WALL_WIDTH; ++x) {
    mvprintw(Y(WALL_HEIGHT), X(x + X_MARGIN), "_");
    mvprintw(Y(WALL_HEIGHT + 1), X(x + X_MARGIN), "%i", x);
  }
}

/**
 * Display the main wall.
 */
static void displayer_wall(wall_t wall)
{
  for (int y = 0; y < WALL_HEIGHT; y++) {
    for (int x = 0; x < WALL_WIDTH; ++x) {
      mvprintw(Y(y), X(x + X_MARGIN),
               wall_get(wall, WALL_HEIGHT - y - 1, x) == FILLED ? "X" : ".");
    }
  }
}

/**
 * Update and display the wall and the tretrominos.
 */
static void displayer_refresh(struct displayer *disp)
{
  displayer_wall(disp->wall);
  refresh();
}

/**
 * Thread displayer main function.
 */
static void* displayer_main(void *arg)
{
  struct displayer *disp = arg;

  displayer_decoration();
  displayer_refresh(disp);

  while (disp->stop == false) {
    pthread_mutex_lock(&disp->lock);
    pthread_cond_wait(&disp->cond, &disp->lock);
    pthread_mutex_unlock(&disp->lock);

    displayer_refresh(disp);
  }

  return NULL;
}

void displayer_notify(struct displayer *disp)
{
  pthread_mutex_lock(&disp->lock);
  pthread_cond_signal(&disp->cond);
  pthread_mutex_unlock(&disp->lock);
}

void displayer_start(struct displayer **displayer, wall_t wall)
{
  struct displayer *disp = CALLOC(1, sizeof(*disp), SID_DISPLAYER);
  *displayer = disp;

  initscr();

  disp->stop = false;
  disp->wall = wall;

  pthread_cond_init(&disp->cond, NULL);
  pthread_mutex_init(&disp->lock, NULL);
  pthread_create(&disp->thread, NULL, displayer_main, disp);
}

void displayer_stop(struct displayer *disp)
{
  pthread_mutex_lock(&disp->lock);
  disp->stop = true;
  pthread_cond_signal(&disp->cond);
  pthread_mutex_unlock(&disp->lock);

  pthread_join(disp->thread, NULL);
  endwin();
  pthread_mutex_destroy(&disp->lock);
  pthread_cond_destroy(&disp->cond);
}
