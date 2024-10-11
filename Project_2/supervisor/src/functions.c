#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>

#include "functions.h"

// Signal handler for the timer that checks the PID of the imu_driver process.
void TimerHandler(int signum) {
  int new_pid = GetPidByName("imu_driver");
  if (new_pid != g_running) {
    g_running = -1;
  }
  char buffer[50];
  int length =
      snprintf(buffer, sizeof(buffer), "imu_driver PID: %d\n", g_running);
  write(STDOUT_FILENO, buffer, length);
  g_running = new_pid;
}

// Signal handler for SIGCHLD to reap zombie processes.
void SigchldHandler(int signo) {
  while (waitpid(-1, NULL, WNOHANG) > 0)
    ;
}

// Gets the PID or running state of a process by its name.
int GetPidByName(const char* process_name) {
  char command[256];
  snprintf(command, sizeof(command), "pgrep -x %s", process_name);
  FILE* fp = popen(command, "r");
  if (fp == NULL) {
    perror("popen");
    return -1;
  }
  int pid = -1;
  if (fscanf(fp, "%d", &pid) == 1) {
    // Successfully retrieved a PID
  }
  pclose(fp);
  return pid;
}