#include <curses.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#include "functions.h"

void* UpdateBallPosition(void* arg) {
  while (!stop_threads) {
    getmaxyx(stdscr, row, col);
    mvprintw(ball_pos.y, ball_pos.x, " ");
    refresh();

    ball_pos.x += dx;
    ball_pos.y += dy;

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

    mvprintw(ball_pos.y, ball_pos.x, "o");  
    refresh();
    usleep(100000);
  }

  return NULL;
}

void* UpdateCounter(void* arg) {
  while (!stop_threads) {
    refresh();
    mvprintw(0, 0, "Counter: %d", counter_val++);
    usleep(1000000);
  }
  return NULL;
}