#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
  int x;
  int y;
} BallPosition;

#define ENTER_NCURSES 10

int dx, dy;
int row, col;
int counter_val;
int stop_threads;
BallPosition ball_pos;

/**
 * @brief The function `UpdateBallPosition` updates the position of a ball on the screen while checking for
 * collisions with window boundaries.
 */
void* UpdateBallPosition(void* arg);

/**
 * @brief The function `UpdateCounter` increments a counter value and displays it on the screen in a
 * multi-threaded environment with a delay of 1s.
 */
void* UpdateCounter(void* arg);

#endif  // FUNCTIONS_H