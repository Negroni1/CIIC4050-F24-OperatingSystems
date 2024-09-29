#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <unistd.h>

/**
 * The function `show_menu` allows the user to interact with specific counter processes by providing
 * options to stop, continue, change counting direction, or kill a process based on user input.
 * 
 * @param pids The `pids` parameter in the `show_menu` function is an array of process IDs (PIDs)
 * representing the counter processes that the user can interact with. These PIDs are used to identify
 * and manipulate specific counter processes within the menu options provided. The `num_pids` parameter
 * indicates
 * @param num_pids `num_pids` is the number of process IDs (PIDs) stored in the array `pids[]`. This
 * function `show_menu` displays a menu for interacting with specific counter processes identified by
 * their PIDs. The user can choose actions like stopping, continuing, changing counting direction, or
 */
void show_menu(pid_t pids[], int num_pids);

#endif  // FUNCTIONS_H