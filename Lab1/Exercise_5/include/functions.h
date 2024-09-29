#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * @brief Translate an integer into a sentence.
 *
 * This function converts a given integer (number) into a string representing
 * the number in words. It allocates memory for a new string, constructs
 * the string by mapping each digit of the number to its corresponding word, and
 * then stores the result in the pointer provided (str).
 *
 * @param number The integer to be converted into words.
 * @param str A pointer to a pointer where the resulting string representation will be stored.
 *
 */
void NumToStr(int number, char** str);

#endif  // FUNCTIONS_H
