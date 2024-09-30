#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

#include "functions.h"

// Global variables
int dx, dy;
int row, col;
int counter_val;
int stop_threads;
pthread_mutex_t mutex;

void* UpdateBallPosition(void* arg) {
  while (!stop_threads) {
    BallPosition* ball = (BallPosition*)arg;

    pthread_mutex_lock(&mutex);
    getmaxyx(stdscr, row, col);
    mvprintw(ball->y, ball->x, " ");
    refresh();

    ball->x += ball->dx;
    ball->y += ball->dy;

    if (ball->x >= col - 1) {
      ball->dx = -1;
    }
    if (ball->y >= row - 1) {
      ball->dy = -1;
    }
    if (ball->x <= 0) {
      ball->dx = 1;
    }
    if (ball->y <= 1) {
      ball->dy = 1;
    }

    mvprintw(ball->y, ball->x, "o");
    refresh();

    pthread_mutex_unlock(&mutex);

    usleep(100000);
  }

  return NULL;
}

void* UpdateCounter(void* arg) {
  while (!stop_threads) {
    refresh();
    pthread_mutex_lock(&mutex);

    mvprintw(0, 0, "Counter: %d", counter_val++);
    refresh();

    pthread_mutex_unlock(&mutex);

    usleep(1000000);
  }

  return NULL;
}
