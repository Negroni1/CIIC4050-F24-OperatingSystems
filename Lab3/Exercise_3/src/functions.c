#include <math.h>
#include <unistd.h>
#include "functions.h"

pthread_mutex_t mutex;
int input_buffer[BUFFER_SIZE];
int n_read_values = 0;
double processed_buffer[BUFFER_SIZE];
int n_processed_values = 0;

struct timeval time_create_file;
struct timeval time_read_file;
struct timeval time_process;
struct timeval time_write_file;

long GetElapsedTime(struct timeval start, struct timeval end) {
  if (start.tv_sec == end.tv_sec) {
    return ((end.tv_sec - start.tv_sec) * 1000) + 
          ((end.tv_usec - start.tv_usec) / 1000);
    }
  return 0;
}

void* CreateFile(void* arg) {
  pthread_mutex_lock(&mutex);

  if (access("data.txt", F_OK) == 0) {
    pthread_mutex_unlock(&mutex);
    return (void*)1;
  }

  FILE* fp = fopen("data.txt", "w");
  if (fp == NULL) {
    pthread_mutex_unlock(&mutex);
    return (void*)1;  // Return error if file cannot be opened.
  }

  for (int i = 0; i < BUFFER_SIZE; i++) {
    fprintf(fp, "%d\n", rand() % 256);
  }
  fclose(fp);

  gettimeofday(&time_create_file, NULL);
  pthread_mutex_unlock(&mutex);
  return (void*)0;
}

void* ReadFile(void* arg) {
  pthread_mutex_lock(&mutex);

  FILE* fp = fopen("data.txt", "r");
  if (fp == NULL) {
    pthread_mutex_unlock(&mutex);
    return NULL;  // Return if file cannot be opened.
  }

  while (fscanf(fp, "%d", &input_buffer[n_read_values]) == 1 && 
         n_read_values < BUFFER_SIZE) {
    n_read_values++;
  }
  fclose(fp);

  gettimeofday(&time_read_file, NULL);
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void* ProcessData(void* arg) {
  pthread_mutex_lock(&mutex);

  for (int i = 0; i < n_read_values; i++) {
    double yn_1 = input_buffer[i] / 2.0;
    double yn = 0;

    for (int j = 0; j < 10; j++) {
      yn = 0.5 * (yn_1 + input_buffer[i] / yn_1);
      yn_1 = yn;
    }

    processed_buffer[n_processed_values] = yn;
    n_processed_values++;
  }

  gettimeofday(&time_process, NULL);
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void* WriteFile(void* arg) {
  pthread_mutex_lock(&mutex);
  
  FILE* fp = fopen("sqrt.txt", "w");
  if (fp == NULL) {
    pthread_mutex_unlock(&mutex);
    return NULL;  // Return if file cannot be opened.
  }

  for (int i = 0; i < n_processed_values; i++) {
    fprintf(fp, "%.6f\n", processed_buffer[i]);
  }
  fclose(fp);

  gettimeofday(&time_write_file, NULL);
  pthread_mutex_unlock(&mutex);
  return NULL;
}
