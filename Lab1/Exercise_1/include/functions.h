#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

/**
 * @brief Generates a random number.
 * 
 * This function initializes a random number generator using the current time 
 * as the seed and returns a random number in the range [0, N-1].
 * 
 * @return int A random number in the range [0, N-1].
 */
int GenerateRandNumber();

/**
 * @brief Get the user's guess.
 * 
 * This function prompts the user to enter an integer value, reads the input,
 * and returns the user's guess.
 * 
 * @return int 
 */
int GetUserGuess();

/**
 * @brief Verifies if the user's guess is correct.
 * 
 * This function compares the random number generated with the user's guess 
 * and returns 1 for true if they match, otherwise returns 0 for false.
 * 
 * @param rand The randomly generated number. 
 * @param guess The user's guess. 
 * @return int Returns 1 if the guess matches the random number, otherwise returns 0.
 */
int VerifyGuess(int rand, int guess);

#endif  // FUNCTIONS_H
