#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Time {
  int hours;
  int minutes;
  int seconds;
};

/**
 * @brief Prints the time in HH:MM:SS format.
 *
 * This function takes the `Time` structure as input and prints the time
 * in a formatted string as `HH:MM:SS`.
 *
 * @param t The `Time` structure containing hours, minutes, and seconds.
 */
void PrintTime(struct Time);

/**
 * @brief Prompts the user to input time values and returns a `Time` structure.
 *
 * This function asks the user to enter hours, minutes, and seconds. It validates
 * the input to ensure the values are within acceptable ranges (hours: 0-23, minutes: 0-59,
 * seconds: 0-59). If the user provides invalid input, they are prompted to try again.
 *
 * @return struct Time A `Time` structure populated with the validated hours, minutes, and seconds.
 */
struct Time GetTime();

#endif  // FUNCTIONS_H
