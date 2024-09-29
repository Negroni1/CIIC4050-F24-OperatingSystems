#include "functions.h"

int main() {
  struct Time t = {15, 5, 31};
  PrintTime(t);
  t = GetTime();
  PrintTime(t);
  return 0;
}
