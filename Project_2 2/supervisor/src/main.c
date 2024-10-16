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
  // Set up the SIGCHLD signal handler to prevent zombies
  struct sigaction child_action;
  child_action.sa_handler = SigchldHandler;
  child_action.sa_flags = SA_RESTART | SA_NOCLDSTOP;
  sigaction(SIGCHLD, &child_action, NULL);

  timer_t timer_id;
  timer_create(CLOCK_REALTIME, NULL, &timer_id);
  struct sigaction action;
  action.sa_handler = TimerHandler;
  action.sa_flags = 0;
  sigaction(SIGALRM, &action, NULL);

  struct itimerspec timer_params;
  timer_params.it_value.tv_sec = 1;
  timer_params.it_value.tv_nsec = 5 * 100000000;
  timer_params.it_interval.tv_sec = 1;
  timer_params.it_interval.tv_nsec = 5 * 100000000;

  timer_settime(timer_id, 0, &timer_params, NULL);

  while (1) {
    if (g_running == -1) {
      printf("Process DEAD, restarting...\n");
      int pid = fork();
      if (pid == 0) {
        execlp("./imu_driver", "imu_driver", NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
      } else if (pid > 0) {
        g_running = pid;
      }
    }
    // Sleep 100ms
    usleep(100 * 1000);
  }
  return 0;
}
