#include <curses.h> /* ncurses.h includes stdio.h */
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#include "functions.h"

int main() {
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);

  counter_val = 0;
  stop_threads = 0;
  ball_pos.x = 10;
  ball_pos.y = 20;

  dx = dy = 1;

  // Initialize mutex
  pthread_mutex_init(&mutex, NULL);

  pthread_t id1, id2;
  pthread_create(&id1, NULL, UpdateBallPosition, NULL);
  pthread_create(&id2, NULL, UpdateCounter, NULL);

  int key_stroke;
  int break_loop = 0;
  while (!break_loop) {
    key_stroke = getch();
    refresh();
    switch (key_stroke) {
      case KEY_LEFT:
        // Handle left arrow
        break;
      case 'f':
        // Handle 'f' key press
        break;
      case ENTER_NCURSES:
        // Stop the program when Enter is pressed
        stop_threads = 1;
        break_loop = 1;
        break;
    }
  }

  // Join the threads
  pthread_join(id1, NULL);
  pthread_join(id2, NULL);

  getch();
  endwin();

  // Destroy the mutex
  pthread_mutex_destroy(&mutex);

  return 0;
}
