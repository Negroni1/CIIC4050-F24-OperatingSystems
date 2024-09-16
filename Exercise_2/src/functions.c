#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// The function `add_params` dynamically allocates memory for a new parameter, duplicates the
// parameter, and stores it in an array of strings.
void add_params(char*** to_be_commands, int* param_out, char* param) {
  *to_be_commands = realloc(*to_be_commands, (*param_out + 1) * sizeof(char*));
  (*to_be_commands)[*param_out] =
      strdup(param);  // Duplicate the parameter and store it
  (*param_out)++;
}

// The function `add_command` adds a new command to a list of commands to be executed.
void add_command(char**** execute_commands, int* commands_out,
                 char** to_be_commands, int param_out) {
  to_be_commands = realloc(to_be_commands, (param_out + 1) * sizeof(char*));
  to_be_commands[param_out] = NULL;
  *execute_commands =
      realloc(*execute_commands, (*commands_out + 1) * sizeof(char**));
  (*execute_commands)[*commands_out] = to_be_commands;
  (*commands_out)++;
}

// The function `commands_array` parses a string of terminal commands into individual
// commands and parameters.
void commands_array(char**** execute_commands, int* commands_out) {
  char commands[500];
  printf("terminal $ ");
  fgets(commands, sizeof(commands), stdin);
  commands[strlen(commands) - 1] = ';';
  commands[strlen(commands)] = '\n';
  // Variables for parsing
  int pos = 0, command_index = 0, param_out = 0;
  char command[50];  // Buffer for individual commands/parameters
  char** to_be_commands = NULL;

  *execute_commands = NULL;
  *commands_out = 0;

  while (commands[pos] != '\0') {
    // Handle spaces to terminate parameters
    if (commands[pos] == ' ') {
      if (command_index > 0) {
        command[command_index] = '\0';  // Terminate the command string
        add_params(&to_be_commands, &param_out, command);  // Add parameter
        command_index = 0;  // Reset for the next word
      }
      // Handle semicolons to terminate commands
    } else if (commands[pos] == ';') {
      if (command_index > 0) {
        command[command_index] = '\0';
        add_params(&to_be_commands, &param_out, command);
        command_index = 0;
      }
      add_command(execute_commands, commands_out, to_be_commands, param_out);
      to_be_commands = NULL;  // Reset the current command
      param_out = 0;          // Reset the number of parameters
    } else {
      // Build the command/parameter character by character
      command[command_index++] = commands[pos];
    }
    pos++;
  }
  // Handle the last parameter and command if there's no trailing semicolon
  if (command_index > 0) {
    command[command_index] = '\0';
    add_params(&to_be_commands, &param_out, command);
  }
  if (param_out > 0) {
    add_command(execute_commands, commands_out, to_be_commands, param_out);
  }
}

// The function `execute_parsed_commands` forks child processes to execute parsed commands
void execute_parsed_commands(char*** execute_commands, int command_count) {
  for (int i = 0; i < command_count - 1; i++) {
    pid_t pid = fork();
    if (pid == 0) {  // Child process
      execvp(execute_commands[i][0],
             execute_commands[i]);  // Pass command to execvp
      perror("exec failed");        // Print the error if exec fails
      exit(EXIT_FAILURE);
    } else if (pid > 0) {
      wait(NULL);  // Parent waits for the child to finish
    } else {
      perror("fork failed");
    }
  }
}