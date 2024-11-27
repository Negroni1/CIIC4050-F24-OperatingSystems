#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <sys/time.h>

#define NUM_CHILDREN 3

/**
 * The function `CpuBoundTask` performs a CPU-bound task by executing a loop for a specified number of
 * iterations.
 * 
 * @param id The `id` parameter in the `CpuBoundTask` function represents the identifier of the process. 
 * It is used to uniquely identify different instances of the task when it is
 * called.
 */
void CpuBoundTask(int id);

/**
 * The function calculates the elapsed time in milliseconds between two timeval structures.
 * 
 * @param start The `start` parameter is a struct timeval representing the starting time.
 * @param end The `struct timeval` parameters `start` and `end` represent points in time.
 * 
 * @return The function `GetElapsedTime` returns the elapsed time in milliseconds between the `start`
 * and `end` time values provided as arguments.
 */
long GetElapsedTime(struct timeval start, struct timeval end);

#endif  // FUNCTIONS_H