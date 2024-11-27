#include <fcntl.h>
#include <linux/input.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

void ReadData(FILE* file_mouse_data, int fd) {
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

int main() {
  // Setup Signal Handler to close the file
  struct sigaction sa;
  sa.sa_handler = Close;
  sigaction(SIGINT, &sa, NULL);

  // Setup binary file
  file_mouse_data = fopen("mouse_data.dat", "wb");
  if (!file_mouse_data) {
    perror("Error opening binary file\n");
    return 1;
  }

  // Setup file to  read mouse positions
  const char* device = "/dev/input/mice";
  int fd = open(device, O_RDONLY);
  if (fd == -1) {
    perror("Error opening device");
    return 1;
  } 
  
  ReadData(file_mouse_data, fd);

  close(fd);
  return 0;
}
