#include "functions.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESS 10

int GenerateRandNumber() {
  srand(time(NULL));
  return rand() % MAX_GUESS;
}

int GetUserGuess() {
  int guess;
  scanf("%d", &guess);
  return guess;
}

int VerifyGuess(int rand, int guess) {
  return rand == guess;
}
