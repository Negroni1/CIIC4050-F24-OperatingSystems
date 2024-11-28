#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

extern int fd;
extern FILE* file_mouse_data;

/**
 * @brief Closes resources and terminates the program.
 *
 * This function closes open file handles and other resources before exiting the program.
 * Specifically, it checks and closes `file_mouse_data` if it is open and prints a message 
 * indicating the file has been closed. It also closes a file descriptor `fd` if it is valid.
 * Finally, the function terminates the program with an exit status of 0.
 *
 * @param param An integer parameter (currently unused).
 */
void Close(int param);

/**
 * @brief Reads mouse event data and calculates terminal coordinates.
 * 
 * This function listens for mouse events, tracks the movement and button presses,
 * calculates absolute and terminal coordinates, and writes the terminal coordinates 
 * to a file.
 * 
 * @details 
 * - The mouse data is read continuously from a file descriptor (`fd`).
 * - The absolute coordinates (`absolute_x` and `absolute_y`) are updated based 
 *   on the mouse movements and are constrained to a screen size of 1028x800.
 * - Terminal coordinates are calculated as percentages of the screen size:
 *   - X-coordinate: range (0, 100)
 *   - Y-coordinate: range (0, 25)
 * - The terminal coordinates are displayed on the console and written as integers 
 *   to a file (`file_mouse_data`).
 */
void ReadData();

#endif  // FUNCTIONS_H
