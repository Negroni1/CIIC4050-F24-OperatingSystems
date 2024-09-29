#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * The function `add_params` dynamically adds a parameter to a list of commands.
 * 
 * @param to_be_commands `to_be_commands` is a pointer to a pointer to a character array. It is used to
 * store a list of commands or parameters.
 * @param param_out The `param_out` parameter is a pointer to an integer. It is used to keep track of
 * the number of parameters added to the `to_be_commands` array. Each time a parameter is added, the
 * value pointed to by `param_out` is incremented to reflect the new total number of parameters
 * @param param The `param` parameter to be added to the list of parameters.
 */
void add_params(char*** to_be_commands, int* param_out, char* param);

/**
 * The function `add_command` adds a command to a list of commands to be executed.
 * 
 * @param execute_commands `execute_commands` is a pointer to a pointer to a pointer to a character. It
 * is used to store a list of commands to be executed. Each command is represented as an array of
 * strings (arguments) terminated by a NULL pointer. The function `add_command` adds a new command to
 * this
 * @param commands_out The `commands_out` parameter is a pointer to an integer that represents the
 * number of commands currently stored in the `execute_commands` array. This value is used to keep
 * track of the number of commands added so far.
 * @param to_be_commands `to_be_commands` is a pointer to an array of strings that represent the
 * commands and arguments to be executed. Each string in the array is a command or an argument for the
 * command to be executed. The array is terminated with a NULL pointer to indicate the end of the list.
 * @param param_out The `param_out` parameter in the `add_command` function represents the number of
 * parameters in the `to_be_commands` array that are to be executed. It is used to determine the size
 * of the `to_be_commands` array and to null-terminate the parameter list by setting the last element
 */
void add_command(char**** execute_commands, int* commands_out,
                 char** to_be_commands, int param_out);

/**
 * The function `commands_array` parses a string of terminal commands into individual commands and
 * parameters.
 * 
 * @param execute_commands The `execute_commands` parameter in the provided function `commands_array`
 * is a pointer to a pointer to a pointer to a character. This parameter is used to store the parsed
 * commands and parameters in a 3-dimensional array. The function populates this array with the parsed
 * commands and their respective parameters.
 * @param commands_out The `commands_out` parameter in the `commands_array` function is a pointer to an
 * integer. This parameter is used to store the total number of commands that have been parsed and
 * added to the `execute_commands` array. The function updates the value pointed to by `commands_out`
 * with the total
 */
void commands_array(char**** execute_commands, int* commands_out);

/**
 * The function `execute_parsed_commands` forks child processes to execute parsed commands and waits
 * for each child process to finish before proceeding.
 * 
 * @param execute_commands `execute_commands` is a 2D array of strings where each row represents a
 * command to be executed, and each column represents an argument of that command. The last row of the
 * array is typically reserved for the NULL terminator to indicate the end of the commands.
 * @param command_count The `command_count` parameter in the `execute_parsed_commands` function
 * represents the number of commands to be executed. It is used to determine the number of iterations
 * in the loop that forks a child process to execute each command.
 */
void execute_parsed_commands(char*** execute_commands, int command_count);

#endif  // FUNCTIONS_H