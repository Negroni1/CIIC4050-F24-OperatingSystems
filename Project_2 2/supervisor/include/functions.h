#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Global variable to check if process is running
extern int g_running;

/**
 * @brief Signal handler for the timer that checks the PID of the imu_driver process.
 *
 * This function is invoked when a signal is received. It sets the global variable 
 * g_running to the PID of the imu_driver process.
 *
 * @param signum The signal number received.
 */
void TimerHandler(int signum);

/**
 * @brief Signal handler for SIGCHLD to reap zombie processes.
 *
 * This function is called when the SIGCHLD signal is received.
 * It calls waitpid in a loop to clean up any child processes 
 * that have terminated, preventing zombie processes from accumulating.
 *
 * @param signo The signal number (SIGCHLD).
 */
void SigchldHandler(int signo);

/**
 * @brief Gets the PID of a process by its name.
 *
 * This function uses the pgrep command to find the PID of a process 
 * with the specified name.
 *
 * @param process_name The name of the process to search for.
 * @return The PID of the process if found, -1 on failure.
 */
int GetPidByName(const char* process_name);

#endif  // FUNCTIONS_H