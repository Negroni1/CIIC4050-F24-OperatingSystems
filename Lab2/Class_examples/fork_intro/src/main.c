#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {
  pid_t p = fork();
  if (p == 0) {
    printf("im the child: %d\n", getpid());

    if (execlp("ls", "ls", "-l", NULL) == -1) {
      // If execl fails, print the error
      perror("error launching child: ");
      exit(EXIT_FAILURE);
    }

    return 0;
  } else {
    wait(NULL);
    printf("im the parent: %d\n", getpid());
    // return 0;
  }
}
