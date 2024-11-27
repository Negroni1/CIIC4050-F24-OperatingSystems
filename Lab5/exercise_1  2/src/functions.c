#include <stdio.h>

#include "functions.h"

// CpuBoundTask performs a CPU-bound task by executing a loop for a specified number of iterations.
void CpuBoundTask(int id) {
  printf("Process %d started, pid %d\n", id, getpid());
  int n = 0;
  for (n = 0; n < 30; n++) {
    volatile long v = 0;
    for (v = 0; v < 1000000000; v++)
      ;
  }
}

// GetElapsedTime returns the elapsed time in milliseconds between two timeval structures
long GetElapsedTime(struct timeval start, struct timeval end) {
  return ((end.tv_sec - start.tv_sec) * 1000) +
         ((end.tv_usec - start.tv_usec) / 1000);
}