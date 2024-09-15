#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 Make another program that creates three children using fork(). Each child will
 print the message “I’m a child, and my id is: <pid>” before creating two more
 children and waiting for them to end. The children of the child processes must
 use the exec() function to invoke the greetings program.*
 *
*/
int main() {
  pid_t id_child;
  int childs = 0;
  while (childs < 3) {
    id_child = fork();
    if (id_child == 0) {
      printf("I'm a child, and my id is: %d\n", getpid());
      int n = 0;
      while (n < 2) {
        pid_t id_grand_child = fork();
        if (id_grand_child == 0) {

          if (execl("./greetings", "./greetings", NULL) == -1) {
            perror("Error launching child");
            exit(EXIT_FAILURE);
          }
        }
        n++;
      }
      wait(NULL);
      exit(0);
    }
    childs++;
  }
  wait(NULL);
  return 0;
}
