#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include "functions.h"

void* UserInput(void* arg) {
  while (1) {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&p_cond_input, &mutex);

    printf("Enter a number between 0 and 1: ");
    scanf("%lf", &user_number);

    if (user_number >= 100) {
      pthread_cond_signal(&p_cond_arcsine);
      pthread_mutex_unlock(&mutex);
      break;
    }

    pthread_cond_signal(&p_cond_arcsine);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void* CalculateArcsine(void* arg) {
  while (1) {
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&p_cond_input);
    pthread_cond_wait(&p_cond_arcsine, &mutex);

    if (user_number >= 100) {
      pthread_mutex_unlock(&mutex);
      break;
    }

    if (user_number > 0.0 && user_number < 1.0) {
      printf("Arcsine of %lf is %lf\n", user_number, asin(user_number));
    }

    pthread_cond_signal(&p_cond_input);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}