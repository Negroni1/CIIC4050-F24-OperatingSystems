#include <curses.h> /* ncurses.h incluye stdio.h */
#include <pthread.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  int x;
  int y;
} BallPosition;

#define ENTER_NCURSES 10

int main() {
  pthread_t id1, id2;

  initscr();
  keypad(stdscr, TRUE);
  noecho();

  curs_set(0);

  BallPosition ball_pos;
  int counter_val = 0;
  int dx, dy;
  int row, col;

  ball_pos.x = 10;
  ball_pos.y = 20;

  int key_stroke;
  int break_loop = 0;
  while (!break_loop) {
    key_stroke = getch();
    refresh();
    switch (key_stroke) {
      case KEY_LEFT:
        /* code */
        break;
      case 'f':
        /* code */
        break;
      case ENTER_NCURSES:
        // case KEY_ENTER:
        break_loop = 1;
        break;
    }
  }

  dx = dy = 1;
  while (1) {
    clear();
    getmaxyx(stdscr, row, col); /* Obtiene el numbero de filas y columnas */
    mvprintw(0, 0, "%d", counter_val++);
    mvprintw(ball_pos.y, ball_pos.x, "o");
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

    usleep(100000); /* Duerme por 100ms */
  }

  getch();
  endwin();

  return 0;
}