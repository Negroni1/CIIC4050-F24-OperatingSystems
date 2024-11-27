#include "functions.h"
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <sys/time.h>

//  The function ThreadFunc prints information about the thread's scheduling policy and priority, runs a
//  loop with a delay, and records the end time.void* ThreadFunc(void* arg) {
void* ThreadFunc(void* arg) {
  ThreadArgs* thread_args = (ThreadArgs*)arg;

  // Get thread scheduling policy and priority
  int policy;
  struct sched_param param;
  pthread_getschedparam(pthread_self(), &policy, &param);

  const char* policy_str = (policy == SCHED_FIFO)    ? "SCHED_FIFO"
                           : (policy == SCHED_RR)    ? "SCHED_RR"
                           : (policy == SCHED_OTHER) ? "SCHED_OTHER"
                                                     : "UNKNOWN";

  printf("Thread %lu is running with policy %s and priority %d\n",
         pthread_self(), policy_str, param.sched_priority);

  int i = 0;
  while (i < 200) {
    for (volatile long j = 0; j < 1000000000; j++)
      ;
    printf("Thread %d running. iteration %d\n", thread_args->id, i);
    i++;
  }

  // Record end time after loop completes
  struct timeval end;
  gettimeofday(&end, NULL);
  thread_args->time = end;

  return NULL;
}

// GetElapsedTime calculates the elapsed time in seconds between two timeval structures
long GetElapsedTime(struct timeval start, struct timeval end) {
  return ((end.tv_sec - start.tv_sec)) +
         ((end.tv_usec - start.tv_usec) / 1000000);
}
