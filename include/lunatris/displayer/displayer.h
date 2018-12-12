#ifndef DISPLAYER_H_
# define DISPLAYER_H_

#include <lunatris/wall/wall.h>

/* Opaque structure for a displayer. */
typedef struct displayer* displayer_t;

/**
 * Start the displayer.
 */
void displayer_start(displayer_t *disp, wall_t wall);

/**
 * Stop the displayer.
 */
void displayer_stop(displayer_t disp);

/**
 * Notify the displayer to update the screen.
 */
void displayer_notify(displayer_t disp);

#endif /* !DISPLAYER_H_ */
