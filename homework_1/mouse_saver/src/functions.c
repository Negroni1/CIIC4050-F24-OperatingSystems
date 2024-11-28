#include "functions.h"
#include <stdlib.h>

FILE* file_mouse_data = NULL;
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

// Reads mouse event data and calculates terminal coordinates
void ReadData() {
  signed char data[3];
  int absolute_x = 1028 / 2;
  int absolute_y = 800 / 2;

  printf("Listening for mouse events. Move the mouse or press buttons.\n");
  while (1) {
    if (read(fd, data, sizeof(data)) > 0) {
      absolute_x += data[1];
      absolute_y += (-data[2]);

      if (absolute_x < 0) {
        absolute_x = 0;
      }

      if (absolute_x > 1028) {
        absolute_x = 1028;
      }

      if (absolute_y < 0) {
        absolute_y = 0;
      }

      if (absolute_y > 800) {
        absolute_y = 800;
      }

      // Write terminal coordinates
      float terminal_x = ((float)absolute_x / 1028) * 100;
      float terminal_y = ((float)absolute_y / 800) * 25;
      printf("Coordinates: (%.2f, %.2f)\n", terminal_x, terminal_y);

      int x = (int)terminal_x;
      int y = (int)terminal_y;
      fwrite(&x, sizeof(int), 1, file_mouse_data);
      fwrite(&y, sizeof(int), 1, file_mouse_data);
    }
  }
}