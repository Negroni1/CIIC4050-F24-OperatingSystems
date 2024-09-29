#include "functions.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void NumToStr(int number, char** str) {
  printf("The number %d in string is: ", number);

  // Calculate the maximum required size for the string
  int number_size = ((int)log10(number)) + 1;
  char* new_str = malloc((number_size * 6 + 1) * sizeof(char));

  // Make a list with all numbers
  int list_numbers[number_size];
  for (int i = 0; i < number_size; i++) {
    list_numbers[number_size - i - 1] = number % 10;
    number /= 10;
  }

  for (int i = 0; i < number_size; i++) {
    switch (list_numbers[i]) {
      case 1:
        strcat(new_str, "one");
        break;
      case 2:
        strcat(new_str, "two");
        break;
      case 3:
        strcat(new_str, "three");
        break;
      case 4:
        strcat(new_str, "four");
        break;
      case 5:
        strcat(new_str, "five");
        break;
      case 6:
        strcat(new_str, "six");
        break;
      case 7:
        strcat(new_str, "seven");
        break;
      case 8:
        strcat(new_str, "eight");
        break;
      case 9:
        strcat(new_str, "nine");
        break;
      default:
        strcat(new_str, "zero");
    }
    strcat(new_str, " ");
  }
  strcat(new_str, "\n");

  // Allocate memory for str and copy the result
  *str = (char*)malloc((strlen(new_str) + 1) * sizeof(char));
  strcpy(*str, new_str);
}
