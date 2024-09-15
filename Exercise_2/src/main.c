#include "functions.h"

#include <stdio.h>

int main() {
  char ***execute_commands = NULL;
  int command_out = 0;

  // Parse user input into commands and parameters
  commands_array(&execute_commands, &command_out);

  // Execute the parsed commands
  execute_parsed_commands(execute_commands, command_out);

  return 0;
}
