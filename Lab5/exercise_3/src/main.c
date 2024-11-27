#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

#include "functions.h"

int main() {
  pthread_t t[4];
  struct timeval start;
  gettimeofday(&start, NULL);

  ThreadArgs threads[4];
  for (int i = 0; i < 4; i++) {
    // Set scheduling policy: FIFO for first two threads, RR for others
    threads[i].id = i;
    if (i < 2) {
      threads[i].policy = SCHED_FIFO;
    } else {
      threads[i].policy = SCHED_RR;
    }
  }

  // Set priority for each thread
  threads[0].priority = 50;
  threads[1].priority = 50;
  threads[2].priority = 50;
  threads[3].priority = 50;

  struct sched_param param;
  pthread_attr_t attr;

  // Create threads
  for (int i = 0; i < 4; i++) {
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, threads[i].policy);
    param.sched_priority = threads[i].priority;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&t[i], &attr, ThreadFunc, (void*)&threads[i]);
  }

  // Wait for all threads to finish
  for (int i = 0; i < 4; i++) {
    pthread_join(t[i], NULL);
  }

  for (int i = 0; i < 4; i++) {
    printf("Thread %d time taken: %ld s\n", threads[i].id,
           GetElapsedTime(start, threads[i].time));
  }

  return 0;
}
