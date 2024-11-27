#include "functions.h"
#include <stdlib.h>

FILE *file_mouse_data = NULL;
int fd;

// Closes resources and terminates the program.
void Close(int param) {
  if (file_mouse_data) {
    fclose(file_mouse_data);
    printf("\nClose file\n");
  }
  if (fd != -1) {
    close(fd);
  }
  exit(0);
}
