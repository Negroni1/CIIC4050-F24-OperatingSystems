#include "functions.h"

#include <stdio.h>

void PrintTime(struct Time t) {
  printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

struct Time GetTime() {
  int hours, minutes, seconds = -1;
  printf("---Update Time---\n");

  // Get hours from user and validate them
  printf("Enter Hours: ");
  scanf("%d", &hours);
  while (hours > 23 || hours < 0) {
    printf("Invalid hour, try again: ");
    scanf("%d", &hours);
  }

  // Get minutes from user and validate them
  printf("Enter Minutes: ");
  scanf("%d", &minutes);
  while (minutes > 60 || minutes < 0) {
    printf("Invalid minutes, try again: ");
    scanf("%d", &minutes);
  }

  // Get seconds from user and validate them
  printf("Enter Seconds: ");
  scanf("%d", &seconds);
  while (seconds > 60 || seconds < 0) {
    printf("Invalid seconds, try again: ");
    scanf("%d", &seconds);
  }

  struct Time t = {hours, minutes, seconds};
  return t;
}
