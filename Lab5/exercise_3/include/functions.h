#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <pthread.h>
#include <sys/time.h>

typedef struct {
  int id;
  int priority;
  int policy;
  struct timeval time;
} ThreadArgs;

/**
 * The function ThreadFunc prints information about the thread's scheduling policy and priority, runs a
 * loop with a delay, and records the end time.
 * 
 * @param arg The `arg` parameter in the `ThreadFunc` function is a void pointer that is cast to a
 * `ThreadArgs` pointer inside the function. It is used to pass arguments to the thread function,
 * specifically an instance of the `ThreadArgs` struct which likely contains information needed by the
 * thread such
 * 
 * @return The function `ThreadFunc` returns a `NULL` pointer.
 */
void* ThreadFunc(void* arg);

/**
 * The function calculates the elapsed time in seconds between two timeval structures.
 * 
 * @param start The `struct timeval` type is commonly used in C programming to represent time values.
 * It typically contains two fields: `tv_sec` for seconds and `tv_usec` for microseconds. In the
 * `GetElapsedTime` function you provided, `start` and `end` are instances of `struct timeval
 * @param end The `end` parameter is a struct timeval variable that represents the end time for which
 * you want to calculate the elapsed time. It typically contains two components:
 * 
 * @return The function `GetElapsedTime` returns the elapsed time in seconds between the `start` and
 * `end` time values provided as arguments.
 */
long GetElapsedTime(struct timeval start, struct timeval end);

#endif  // FUNCTIONS_H
