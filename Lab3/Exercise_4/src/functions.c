#include <curses.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#include "functions.h"

void* UpdateBallPosition(void* arg) {
  while (!stop_threads) {
    pthread_mutex_lock(&mutex);

    getmaxyx(stdscr, row, col);
    mvprintw(ball_pos.y, ball_pos.x, " ");
    refresh();

    ball_pos.x += dx;
    ball_pos.y += dy;

    // Check for collision with the window boundaries
    if (ball_pos.x >= col - 1) {
      dx = -1;
    }
    if (ball_pos.y >= row - 1) {
      dy = -1;
    }
    if (ball_pos.x <= 1) {
      dx = 1;
    }
    if (ball_pos.y <= 1) {
      dy = 1;
    }

    mvprintw(ball_pos.y, ball_pos.x, "o");  // Draw the ball
    refresh();

    pthread_mutex_unlock(&mutex);

    usleep(100000);  // Sleep for 100ms to slow down ball movement
  }

  return NULL;
}

void* UpdateCounter(void* arg) {
  while (!stop_threads) {
    pthread_mutex_lock(&mutex);

    mvprintw(0, 0, "Counter: %d", counter_val++);
    refresh();

    pthread_mutex_unlock(&mutex);

    usleep(1000000);  // Sleep for 1s to slow down counter increment
  }
  return NULL;
}