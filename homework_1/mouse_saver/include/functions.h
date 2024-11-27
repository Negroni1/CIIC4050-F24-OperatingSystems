#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

int fd;
FILE* file_mouse_data = NULL;

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

#endif  // FUNCTIONS_H