#include <stdio.h>

#include "functions.h"

int main() {
  char* str;
  NumToStr(1234, &str);
  printf("%s", str);
  return 0;
}
