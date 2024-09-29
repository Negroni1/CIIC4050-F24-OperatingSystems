#include <stdio.h>

#include "functions.h"

int main() {
  fill_deck();

  struct Card hand[5];
  fill_hand(hand);

  hand_contains(hand);
  return 0;
}
