#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "constants.h"
#include "functions.h"

int main() {
  timer_t timer_id;
  timer_create(CLOCK_REALTIME, NULL, &timer_id);
  struct sigaction action;
  action.sa_handler = TimerHandler;
  action.sa_flags = 0;
  sigaction(SIGALRM, &action, NULL);

  struct itimerspec timer_params;

  timer_params.it_value.tv_sec = 0;
  timer_params.it_value.tv_nsec = 200 * 1000000;  // 200 ms
  timer_params.it_interval.tv_sec = 0;
  timer_params.it_interval.tv_nsec = 200 * 1000000;  // 200 ms

  timer_settime(timer_id, 0, &timer_params, NULL);

  WriteFile();
  sleep(5);
  return 0;
}
