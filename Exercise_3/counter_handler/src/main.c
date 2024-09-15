#include "functions.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  // Get the PIDs from the command-line arguments
  pid_t pids[5];
  int num_pids = argc - 1;
  for (int i = 0; i < num_pids; i++) {
    pids[i] = atoi(argv[i + 1]);
  }
  // Show the user interface and handle inputs
  show_menu(pids, num_pids);

  return 0;
}
