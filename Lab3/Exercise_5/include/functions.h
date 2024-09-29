#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <pthread.h>

typedef struct {
  int x;
  int y;
  int dx;
  int dy;
} BallPosition;

#define ENTER_NCURSES 10
#define MAX_BALLS 10

extern int dx, dy;
extern int row, col;
extern int counter_val;
extern int stop_threads;
extern pthread_mutex_t mutex;

/**
 * The function `UpdateBallPosition` updates the position of a ball on the screen while checking for
 * collisions with window boundaries.
 */
void* UpdateBallPosition(void* arg);

/**
 * The function `UpdateCounter` increments a counter value and displays it on the screen in a
 * multi-threaded environment with a delay of 1 second.
 */
void* UpdateCounter(void* arg);

#endif  // FUNCTIONS_H
