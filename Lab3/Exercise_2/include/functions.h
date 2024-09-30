#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <pthread.h>
#include <sys/time.h>

#define SIZE_MAX 1000000
#define AMOUNT_THREADS 5
#define SIZE_SEGMENT 200000

pthread_mutex_t mutex;
pthread_cond_t cond_threads_done;

double result[AMOUNT_THREADS];
struct timeval time_taken[AMOUNT_THREADS];

double array[SIZE_MAX];
int completed_threads;

/**
 * @brief Calculates the elapsed time in milliseconds between two timeval structures.
 * 
 * @param start Start time.
 * @param end End time.
 * @return Elapsed time in milliseconds.
 */
long GetElapsedTime(struct timeval start, struct timeval end);

/**
 * @brief Function executed by each thread to calculate the sum of a segment of the array.
 */
void* CalculateSegment(void* arg);

/**
 * @brief Function to calculate and print the total sum of all segments after all threads are done.
 */
void* Total(void* arg);

#endif  // FUNCTIONS_H
