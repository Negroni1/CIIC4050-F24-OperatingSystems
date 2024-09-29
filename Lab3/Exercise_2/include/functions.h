#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <pthread.h>

pthread_mutex_t mutex;

double result_1;
double result_2;
double result_3;
double result_4;
double result_5;

struct timeval time1, time2, time3, time4, time5;

pthread_cond_t cond_threads_done;

double array[1000000];
int completed_threads;

/**
 * The function calculates the elapsed time in milliseconds between two timeval structures.
 * 
 * @param start The `struct timeval` type is commonly used in C programming for representing time
 * values. It typically includes two members: `tv_sec` for seconds and `tv_usec` for microseconds.
 * @param end The `struct timeval` parameters `start` and `end` represent points in time. The `tv_sec`
 * member represents the number of seconds since the epoch, and the `tv_usec` member represents the
 * number of microseconds within the current second.
 * 
 * @return The function `get_elapsed_time` returns the elapsed time in milliseconds between the `start`
 * and `end` time values provided as arguments.
 */
long get_elapsed_time(struct timeval start, struct timeval end);

/**
 * The function CalculateSegment1 calculates the sum of elements in a segment of an array and signals
 * completion using mutex and condition variables in a multi-threaded environment.
 */
void* CalculateSegment1(void* arg);

/**
 * The function CalculateSegment2 calculates the sum of elements in a specific segment of an array and
 * signals completion using mutex and condition variables in a multi-threaded environment.
 */
void* CalculateSegment2(void* arg);

/**
 * The function CalculateSegment3 calculates the sum of elements in a specific segment of an array and
 * signals completion using mutex and condition variables in a multi-threaded environment.
 */
void* CalculateSegment3(void* arg);

/**
 * The function CalculateSegment4 calculates the sum of elements in a specific segment of an array and
 * signals completion using mutex and condition variables.
 */
void* CalculateSegment4(void* arg);

/**
 * The function CalculateSegment5 calculates the sum of elements in a specific segment of an array and
 * signals completion using mutex and condition variables in a multi-threaded environment.
 */
void* CalculateSegment5(void* arg);

/**
 * The Total function calculates and prints the sum of five result variables after waiting for a
 * condition signal.
 */
void* Total(void* arg);


#endif  // FUNCTIONS_H