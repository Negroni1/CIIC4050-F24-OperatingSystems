#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_LENGTH 50

/**
 * @brief Replaces occurrences of a character in a string with another character.
 *
 * This function allocates memory for a new string and replaces all occurrences
 * of a specified character (find) in the source string (src) with another
 * character (replacement). The resulting string is stored in the destination
 * pointer (dst).
 *
 * @param src The source string to find the soon to be replaced.
 * @param dst A pointer to a pointer where the new string with replacements will be stored.
 * @param find The character to be replaced in the source string.
 * @param replacement The character that will replace occurrences of find.
 *
 */
void Replace(char* src, char** dst, char find, char replacement);

/**
 * @brief Inserts a string into a string at each occurrence of a specified character.
 *
 * This function allocates memory for a new string and inserts the specified
 * string (ins) into the destination string (dst) at every occurrence of a
 * specified character (find) in the source string (src).
 *
 * @param src The source string where the lookup will occur.
 * @param dst A pointer to a pointer where the new string with insertions will be stored.
 * @param find The character in the source string after which the string will be inserted.
 * @param ins The string that will be inserted into the destination string.
 *
 */
void Insert(char* src, char** dst, char find, char* ins);

#endif  // FUNCTIONS_H
