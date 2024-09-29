#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {
  pid_t id;
  id = fork();

  if (id == 0) {
    printf(" im the son, %d\n", getpid());
    sleep(1);
    // execlp("ls", "ls", "-l", NULL);
    printf("Im done!!\n");
    exit(18);
  }
  int x;
  sleep(2);
  // wait(&x);
  waitpid(300, &x, 0);

  printf("my son returned %d", WEXITSTATUS(x));

  ///

  printf(" im the parent, %d\n", getpid());
  printf(" I'm %d  and fork returned %d\n\n", getpid(), id);

  return 0;
}
