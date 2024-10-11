#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
/**
 * @brief Timer signal handler.
 *
 * This function sets the write_flag variable to 1 when a timer signal is received,
 * indicating that data should be written to the file.
 *
 * @param signum The signal number received.
 */
void TimerHandler(int signum);

/**
 * @brief Reads the last line from a file and retrieves the last state of the robot.
 *
 * This function seeks to the end of the specified file, finds the last line, 
 * and parses the values into the robot structure. If the file is empty,
 * it returns 0.
 *
 * @return 1 if the last line was read successfully, 0 if the file is empty.
 */
int GetLastLine();

/**
 * @brief Continuously writes robot data to a file.
 *
 * This function opens a file for appending and enters an infinite loop,
 * writing the robot's state (time, position, velocity, and acceleration) 
 * to the file whenever the write_flag is set. It calculates the new state 
 * of the robot based on its acceleration and time elapsed since the last 
 * write. The function runs until terminated externally.
 */
void WriteFile();

#endif  // FUNCTIONS_H