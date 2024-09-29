#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void fill_deck() {
  char* suits[4] = {"clubs", "diamonds", "hearts", "spades"};
  char* ranks[13] = {"A", "2", "3",  "4",    "5",     "6",   "7",
                     "8", "9", "10", "Jack", "Queen", "Kind"};
  int pos = 0;
  for (int suit = 0; suit < 4; suit++) {
    for (int rank = 0; rank < 13; rank++) {
      struct Card c = {suits[suit], ranks[rank], rank + 1};
      *(deck + pos) = c;
      pos++;
    }
  }
}

void fill_hand(struct Card hand[5]) {
  srand(time(NULL));
  int pos = 0;
  while (pos < 5) {
    int card = rand() % 52;
    *(hand + pos) = *(deck + card);
    pos++;
  }
}

void hand_contains(struct Card hand[5]) {
  printf("Your Hand!\n");
  for (int i = 0; i < 5; i++) {
    printf("{%s:%s}\n", hand[i].rank, hand[i].suit);
  }
  int p = is_pair(hand);

  if (is_straight(hand) && p == 0) {
    printf("You have a STRAIGHT\n");
  } else if (count_kinds(hand) == 4) {
    printf("You have a FOUR OF A KIND\n");
  } else if (is_flush(hand)) {
    printf("You have a FLUSH\n");
  } else if (count_kinds(hand) == 3 && p != 2) {
    printf("You have a THREE OF A KIND\n");
  } else if (p == 2) {
    printf("You have a TWO PAIRS\n");
  } else if (p == 1) {
    printf("You have a PAIR\n");
  }
}

int is_pair(struct Card hand[5]) {
  int pairs = 0;
  for (int card = 0; card < 5; card++) {
    for (int s_card = card + 1; s_card < 5; s_card++) {
      if (*(hand + card)->rank == *(hand + s_card)->rank) {
        pairs++;
      }
    }
  }
  return pairs;
}

int count_kinds(struct Card hand[5]) {
  int clubs, diamonds, hearts, spades = 0;
  for (int card = 0; card < 5; card++) {
    if (strcmp(hand[card].rank, "clubs")) {
      clubs++;
    }
    if (strcmp(hand[card].rank, "diamonds")) {
      diamonds++;
    }
    if (strcmp(hand[card].rank, "hearts")) {
      hearts++;
    }
    if (strcmp(hand[card].rank, "spades")) {
      spades++;
    }
  }
  if (clubs == 3 || diamonds == 3 || hearts == 3 || spades == 3) {
    return 3;
  }
  if (clubs == 4 || diamonds == 4 || hearts == 4 || spades == 4) {
    return 4;
  }
  return 0;
}

int is_flush(struct Card hand[5]) {
  char first = *(hand)->suit;
  for (int card = 1; card < 5; card++) {
    if (first != *(hand + card)->suit) {
      return 0;
    }
  }
  return 1;
}

int is_straight(struct Card hand[5]) {

  // Sort the hand based on card values.
  int sorted_hand[5];
  int pos = 0;
  int last_min = 0;
  while (pos < 5) {
    int card = hand[pos].value;
    for (int i = 0; i < 5; i++) {
      if (hand[i].value < card && hand[i].value > last_min) {
        card = hand[i].value;
      }
    }
    last_min = card;
    sorted_hand[pos] = card;
    pos++;
  }

  // Check sequence.
  int min = sorted_hand[0];
  for (int check = 1; check < 5; check++) {
    if (sorted_hand[check] != min + 1) {
      return 0;
    }
    min = sorted_hand[check];
  }
  return 1;
}
