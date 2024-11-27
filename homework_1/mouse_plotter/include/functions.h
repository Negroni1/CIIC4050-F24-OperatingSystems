#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern FILE* file;
extern int x, y;
extern int reading;

/**
 * @brief Handles reading coordinates from a file and displaying a character on the screen.
 *
 * This function attempts to read two integers, `x` and `y`, from a file. If successful,
 * it clears the screen, moves to the specified coordinates, and displays an asterisk (`*`).
 * If the read operation fails, it sets a global variable `reading` to 0 to indicate the end
 * of the reading process.
 *
 * @param param An integer parameter (currently unused).
 */
void Handler(int param);

#endif  // FUNCTIONS_H
