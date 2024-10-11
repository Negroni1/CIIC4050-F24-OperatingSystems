#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>

#include "functions.h"

// Global variable indicating the running state of the process.
// -1 indicates that the process is not running.
int g_running = -1;

/**
 * @brief Main function that monitors and restarts the imu_driver process.
 *
 * This function enters an infinite loop, checking the status of the
 * g_running variable. If the process is not running, it attempts to restart
 * the imu_driver by forking a new process. If the fork fails, an error
 * message is printed. The main function sleeps for 100 milliseconds between checks.
 *
 */
int main() {
  while (1) {
    if (g_running < 0) {
      printf("Process DEAD, restarting...\n");
      int pid = fork();
      if (pid == 0) {
        execlp("../../imu_driver/build/imu_driver",
               "../../imu_driver/build/imu_driver", NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
      } else {
        wait(NULL);
      }
    }
    // Sleep 100ms
    usleep(100 * 1000);
  }
  return 0;
}
