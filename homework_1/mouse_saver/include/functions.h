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
 * @brief Listens for mouse events and processes them into terminal coordinates.
 *
 * This function continuously reads mouse data from the input device file descriptor
 * and translates the relative movement into absolute screen coordinates. It maps
 * these coordinates to a terminal coordinate space and writes them to a file.
 *
 * @param file_mouse_data Pointer to the file where terminal coordinates are logged.
 * @param fd File descriptor of the mouse input device.
 */
void ReadData(FILE* file_mouse_data, int fd);

#endif  // FUNCTIONS_H
