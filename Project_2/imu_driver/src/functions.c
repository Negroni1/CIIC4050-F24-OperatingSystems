#include "functions.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "constants.h"

// Timer signal handler.
void TimerHandler(int signum) {
  write_flag = 1;
}

// Signal handler for termination signals.
void TermHandler(int signum) {
  exit(-1);
}

// Reads the last line from a file and retrieves the last state of the robot.
int GetLastLine() {
  FILE* fp = fopen("imu_data.txt", "r");
  if (fp == NULL) {
    return -1;
  }
  char line[256];
  long pos;

  fseek(fp, 0, SEEK_END);
  pos = ftell(fp);
  while (pos > 0) {
    fseek(fp, --pos, SEEK_SET);
    if (fgetc(fp) == '\n') {
      break;
    }
  }

  if (fgets(line, sizeof(line), fp) != NULL) {
    sscanf(line, "%lf, %lf, %lf, %lf, %lf, %lf, %lf", &robot.time, &robot.p_x,
           &robot.p_y, &robot.v_x, &robot.v_y, &robot.acc_x, &robot.acc_y);
    return 1;
  }
  fclose(fp);
  return 0;
}

// Continuously writes robot data to a file.
void WriteFile() {
  GetLastLine();

  struct timespec start_time, current_time;
  clock_gettime(CLOCK_MONOTONIC, &start_time);
  start_time.tv_sec -= (long)robot.time;

  double p_time = 0.0;
  FILE* fp = fopen("imu_data.txt", "a");
  if (fp == NULL) {
    perror("Failed to open file");
    return;
  }
  while (1) {
    if (write_flag) {
      write_flag = 0;

      clock_gettime(CLOCK_MONOTONIC, &current_time);
      robot.time = (current_time.tv_sec - start_time.tv_sec) +
                   ((current_time.tv_nsec - start_time.tv_nsec) / 1e9);

      // Calculate positions and velocities
      double time = robot.time - p_time;
      p_time = robot.time;

      robot.v_x += robot.acc_x * time;
      robot.p_x += robot.v_x * time;
      robot.v_y += robot.acc_y * time;
      robot.p_y += robot.v_y * time;

      // Write the data to the file
      fprintf(fp, "\n%.2f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f", robot.time,
              robot.p_x, robot.p_y, robot.v_x, robot.v_y, robot.acc_x,
              robot.acc_y);

      fflush(fp);
    }
    usleep(10 * 1000);
  }

  fclose(fp);
}
