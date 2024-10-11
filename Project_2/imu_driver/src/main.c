#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "constants.h"
#include "functions.h"

int main() {
  printf("Process ID: %d\n", getpid());

  timer_t timer_id;
  struct sigevent sev;
  struct itimerspec timer_params;

  memset(&sev, 0, sizeof(struct sigevent));
  sev.sigev_notify = SIGEV_SIGNAL;
  sev.sigev_signo = SIGRTMIN;

  if (timer_create(CLOCK_REALTIME, &sev, &timer_id) == -1) {
    perror("timer_create");
    exit(EXIT_FAILURE);
  }

  struct sigaction action;
  memset(&action, 0, sizeof(struct sigaction));
  action.sa_handler = TimerHandler;

  if (sigaction(SIGRTMIN, &action, NULL) == -1) {
    perror("sigaction");
    exit(EXIT_FAILURE);
  }

  timer_params.it_value.tv_sec = 0;
  timer_params.it_value.tv_nsec = 200 * 1000000;  // 200 ms
  timer_params.it_interval.tv_sec = 0;
  timer_params.it_interval.tv_nsec = 200 * 1000000;  // 200 ms

  if (timer_settime(timer_id, 0, &timer_params, NULL) == -1) {
    perror("timer_settime");
    exit(EXIT_FAILURE);
  }

  WriteFile();
  sleep(5);
  return 0;
}
