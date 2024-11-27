#include <ncurses.h>

#include "functions.h"

FILE* file;
int x, y;
int reading = 1;

// Handles reading coordinates from a file and displaying a character on the screen.
void Handler(int param) {
  if (fread(&x, sizeof(int), 1, file) == 1 &&
      fread(&y, sizeof(int), 1, file) == 1) {
    clear();
    //mvaddch(y, x, "*");
    mvprintw(y, x, "*");
    refresh();
  } else {
    reading = 0;
  }
}
