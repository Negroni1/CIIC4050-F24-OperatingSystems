#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "functions.h"

int main() {
  pthread_t p_input;
  pthread_t p_arcsine;

  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&p_cond_input, NULL);
  pthread_cond_init(&p_cond_arcsine, NULL);

  pthread_create(&p_input, NULL, UserInput, NULL);
  pthread_create(&p_arcsine, NULL, CalculateArcsine, NULL);

  pthread_join(p_input, NULL);
  pthread_join(p_arcsine, NULL);

  pthread_cond_destroy(&p_cond_input);
  pthread_cond_destroy(&p_cond_arcsine);
  pthread_mutex_destroy(&mutex);

  return 0;
}
