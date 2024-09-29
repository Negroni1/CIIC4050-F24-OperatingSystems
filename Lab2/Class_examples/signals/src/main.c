#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int num) {
  write(STDOUT_FILENO, "I won't die%d\n", 13);
  // exit(1);
}

int main() {
  int i = 0;

  struct sigaction sa;
  sa.sa_handler = handler;
  sigaction(SIGINT, &sa, NULL);

  struct sigaction sa2;
  sa2.sa_handler = handler;
  sigaction(SIGUSR1, &sa2, NULL);

  while (1) {
    printf("wasting %d cycles. LOL! %d\n", i++, getpid());
    sleep(1);
  }

  return 0;
}
