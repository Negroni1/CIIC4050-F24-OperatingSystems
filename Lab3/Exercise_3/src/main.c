#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "functions.h"

int main() {
  // Initialize mutex.
  pthread_mutex_init(&mutex, NULL);

  // Initialize indexes.
  n_read_values = 0;
  n_processed_values = 0;

  // Start timer.
  struct timeval start;
  gettimeofday(&start, NULL);

  // Thread identifiers.
  pthread_t thread_file;
  pthread_create(&thread_file, NULL, CreateFile, NULL);
  pthread_join(thread_file, NULL);

  pthread_t thread_read;
  pthread_t thread_process;
  pthread_t thread_write;

  // Create threads.
  pthread_create(&thread_read, NULL, ReadFile, NULL);
  pthread_create(&thread_process, NULL, ProcessData, NULL);
  pthread_create(&thread_write, NULL, WriteFile, NULL);

  // Wait for all threads to finish.
  pthread_join(thread_read, NULL);
  pthread_join(thread_process, NULL);
  pthread_join(thread_write, NULL);

  // Clean up mutex
  pthread_mutex_destroy(&mutex);

  // Print thread execution times.
  printf("Time elapsed for each thread:\n");
  printf("+ Thread Create File time: %ld ms\n", GetElapsedTime(start, time_create_file));
  printf("+ Thread Read File time: %ld ms\n", GetElapsedTime(start, time_read_file));
  printf("+ Thread Process Data time: %ld ms\n", GetElapsedTime(start, time_process));
  printf("+ Thread Write File time: %ld ms\n", GetElapsedTime(start, time_write_file));

  return 0;
}
