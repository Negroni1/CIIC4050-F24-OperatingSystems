#include <stdio.h>

#include "functions.h"

int main() {
  char src[MAX_LENGTH / 2], ins[MAX_LENGTH / 2], find[1], replacement[1];
  int edit;
  char** dst;

  // Ask the user for the original string
  printf("Original string: ");
  fgets(src, sizeof(char) * MAX_LENGTH / 2, stdin);

  // Ask the user for the character to be search for
  printf("Character to search: ");
  scanf(" %c", find);

  // Ask the user which action the will like to proceed to
  printf("What would you like to do?\n0: Replace\n1: Insert\n");
  scanf(" %d", &edit);
  if (!edit) {
    printf("Replacement character: ");
    scanf(" %c", replacement);
    Replace(src, dst, find[0], replacement[0]);
  }
  if (edit) {
    printf("String to insert: ");
    scanf(" %s", ins);
    Insert(src, dst, find[0], ins);
  }

  printf("Resulting string: %s", *dst);
  return 0;
}
