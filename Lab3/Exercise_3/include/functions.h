#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define BUFFER_SIZE 10000

extern pthread_mutex_t mutex;

extern int input_buffer[BUFFER_SIZE];
extern int n_read_values;
extern double processed_buffer[BUFFER_SIZE];
extern int n_processed_values;

extern struct timeval time_create_file;
extern struct timeval time_read_file;
extern struct timeval time_process;
extern struct timeval time_write_file;

/**
 * @brief Calculates elapsed time between two time intervals.
 *
 * @param start Start time.
 * @param end End time.
 * @return Elapsed time in milliseconds.
 */
long GetElapsedTime(struct timeval start, struct timeval end);

/**
 * @brief Thread function to check file existence or create it with random data.
 */
void* CreateFile(void* arg);

/**
 * @brief Thread function to read data from the file into input_buffer.
 */
void* ReadFile(void* arg);

/**
 * @brief Thread function to process the data and store results in processed_buffer.
 */
void* ProcessData(void* arg);

/**
 * @brief Thread function to write the processed data to sqrt.txt.
 */
void* WriteFile(void* arg);

#endif  // FUNCTIONS_H
