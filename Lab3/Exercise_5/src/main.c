#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

int main() {
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);

  counter_val = 0;
  stop_threads = 0;
  BallPosition* balls[MAX_BALLS];     
  pthread_t ball_threads[MAX_BALLS]; 

  int ball_count = 0;

  pthread_mutex_init(&mutex, NULL);

  pthread_t counter_thread;
  pthread_create(&counter_thread, NULL, UpdateCounter, NULL);

  int key_stroke;
  int break_loop = 0;

  while (!break_loop) {
    key_stroke = getch();
    switch (key_stroke) {
      case KEY_LEFT:
        // Handle left arrow
        break;
      case 'f':
        // Handle 'f' key press
        break;
      case ENTER_NCURSES:
        // Stop the program when Enter is pressed
        pthread_mutex_lock(&mutex);
        stop_threads = 1;
        pthread_mutex_unlock(&mutex);
        break_loop = 1;
        break;
      case ' ':
        // Add a new ball when space is pressed
        if (ball_count < MAX_BALLS) {
          // Dynamically allocate memory for the new ball
          balls[ball_count] = (BallPosition*)malloc(sizeof(BallPosition));
          getmaxyx(stdscr, row, col);
          balls[ball_count]->x = rand() % (col - 2) + 1;
          balls[ball_count]->y = rand() % (row - 2) + 1;
          balls[ball_count]->dx = 1;
          balls[ball_count]->dy = 1;
          pthread_create(&ball_threads[ball_count], NULL, UpdateBallPosition,
                         balls[ball_count]);

          ball_count++;
        }
        break;
      case 'c':
        // Handle 'c' key press, change the ball direction
        for (int i = 0; i < ball_count; i++) {
          balls[i]->dx *= -1;
          balls[i]->dy *= -1;
        }
        break;
    }
  }

  for (int i = 0; i < ball_count; i++) {
    pthread_join(ball_threads[i], NULL);
    free(balls[i]);
  }
  pthread_join(counter_thread, NULL);

  endwin();

  pthread_mutex_destroy(&mutex);

  return 0;
}
