#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
double user_number;
pthread_cond_t p_cond_input;
pthread_cond_t p_cond_arcsine;

/**
 * The function `UserInput` waits for user input of a number between 0 and 1, signals another thread
 * upon input, and exits if the input is greater than or equal to 100.
 */
void* UserInput(void* arg);

/**
 * The `CalculateArcsine` function calculates the arcsine of a user-provided number within a specified
 * range and waits for the input signal to be received
 */
void* CalculateArcsine(void* arg);

#endif  // FUNCTIONS_H