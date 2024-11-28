#include <fcntl.h>
#include <linux/input.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

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

  ReadData();

  close(fd);
  return 0;
}
