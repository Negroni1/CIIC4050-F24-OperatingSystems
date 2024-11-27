#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>

#include "functions.h"
int main() {
  pid_t pids[NUM_CHILDREN];
  int priorities[NUM_CHILDREN] = {-10, 0, 10};
  struct timeval start;
  gettimeofday(&start, NULL);
  printf("Start Time: %ld seconds with %ld microseconds\n", start.tv_sec,
         start.tv_usec);
  int i = 0;
  for (i = 0; i < NUM_CHILDREN; i++) {
    pids[i] = fork();
    if (pids[i] < 0) {
      perror("fork");
      exit(1);
    }

    if (pids[i] == 0) {
      printf("Child %d (pid: %d) with priority %d\n", i + 1, getpid(),
             priorities[i]);
      printf("The inital priority is %d\n",
             getpriority(PRIO_PROCESS, getpid()));
      if (setpriority(PRIO_PROCESS, getpid(), priorities[i]) < 0) {
        perror("setpriority");
        exit(1);
      }

      CpuBoundTask(i + 1);
      exit(0);
    }
  }

  int j = 0;
  for (j = 0; j < NUM_CHILDREN; i++) {
    wait(NULL);
  }
  struct timeval end;
  gettimeofday(&end, NULL);
  printf("End Time: %ld seconds with %ld microseconds\n", end.tv_sec,
         end.tv_usec);
  printf("Elapsed Time: %ld\n", GetElapsedTime(start, end));
  return 0;
}
