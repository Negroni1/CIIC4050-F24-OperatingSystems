#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

void* UserInput();
void* CalculateArcsine();

pthread_mutex_t mutex;
double user_number = 0;
pthread_cond_t p_cond_input;
pthread_cond_t p_cond_arcsine;

int main() {
  pthread_t p_input;
  pthread_t p_arcsine;

  pthread_mutex_init(&mutex, NULL);

  pthread_create(&p_input, NULL, UserInput, NULL);
  pthread_create(&p_arcsine, NULL, CalculateArcsine, NULL);

  pthread_join(p_input, NULL);
  pthread_join(p_arcsine, NULL);

  pthread_cond_destroy(&p_cond_input);
  pthread_cond_destroy(&p_cond_arcsine);
  pthread_mutex_destroy(&mutex);

  return 0;
}

void* UserInput() {
  while (1) {
    pthread_mutex_lock(&mutex);
    
    pthread_cond_signal(&p_cond_arcsine);
    if (user_number < 100) {
      printf("Enter a number between 0 and 1: ");
      scanf("%lf", &user_number);
    } else {
      pthread_cond_signal(&p_cond_arcsine);
      pthread_mutex_unlock(&mutex);
      break;
    }
    
    pthread_cond_wait(&p_cond_input, &mutex);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void* CalculateArcsine() {
  while (1) {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&p_cond_arcsine, &mutex);
    
    if (user_number >= 100) {
      pthread_mutex_unlock(&mutex);
      break;
    }
    if (user_number >= 0.0 && user_number <= 1.0) {
      printf("Arcsine of %lf is %lf\n", user_number, asin(user_number));
    }

    pthread_cond_signal(&p_cond_input);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}