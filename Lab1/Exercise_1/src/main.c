#include <stdio.h>

#include "functions.h"

int main() {
  printf("Number-guessing Game\n");
  printf("Enter your guess: ");
  int guess = GetUserGuess();

  int rand = GenerateRandNumber();
  if (VerifyGuess(rand, guess)) {
    printf("You Won! :D\n");
  } else {
    printf("You Lose :(\nAnswer was: %d\n", rand);
  }
  return 0;
}
