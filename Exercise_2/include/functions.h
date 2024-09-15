#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void add_params(char ***to_be_commands, int *param_out, char *param);

void add_command(char ****execute_commands, int *commands_out,
                 char **to_be_commands, int param_out);

void commands_array(char ****execute_commands, int *commands_out);

void execute_parsed_commands(char ***execute_commands, int command_count);

#endif // FUNCTIONS_H