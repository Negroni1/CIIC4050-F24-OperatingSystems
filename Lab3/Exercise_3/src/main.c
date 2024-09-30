#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "functions.h"

int main() {
  pthread_mutex_init(&mutex, NULL);

  n_read_values = 0;
  n_processed_values = 0;

  struct timeval start;
  gettimeofday(&start, NULL);

  pthread_t thread_file;
  pthread_create(&thread_file, NULL, CreateFile, NULL);
  pthread_join(thread_file, NULL);

  pthread_t thread_read;
  pthread_t thread_process;
  pthread_t thread_write;

  pthread_create(&thread_read, NULL, ReadFile, NULL);
  pthread_create(&thread_process, NULL, ProcessData, NULL);
  pthread_create(&thread_write, NULL, WriteFile, NULL);

  pthread_join(thread_read, NULL);
  pthread_join(thread_process, NULL);
  pthread_join(thread_write, NULL);

  pthread_mutex_destroy(&mutex);

  printf("Time elapsed for each thread:\n");
  printf("+ Thread Create File time: %ld ms\n", GetElapsedTime(start, time_create_file));
  printf("+ Thread Read File time: %ld ms\n", GetElapsedTime(start, time_read_file));
  printf("+ Thread Process Data time: %ld ms\n", GetElapsedTime(start, time_process));
  printf("+ Thread Write File time: %ld ms\n", GetElapsedTime(start, time_write_file));

  return 0;
}
