#include "functions.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void textHandler() {
  char** text = malloc(HEIGHT * sizeof(char*));
  for (int i = 0; i < HEIGHT; i++) {
    text[i] = malloc(WIDTH * sizeof(char));
  }

  int size = getText(text);

  printf("What alignmet would you like?\n");
  printf("0: Left\n1: Right\n2: Center\n3: Justify\n4: Show me all of them\n");
  int alignment;
  scanf("%d", &alignment);
  switch (alignment) {
    case 0:
      leftAlign(size, text);
      break;
    case 1:
      rightAlign(size, text);
      break;
    case 2:
      centerAlign(size, text);
      break;
    case 3:
      justifyAlign(size, text);
      break;
    default:
      leftAlign(size, text);
      rightAlign(size, text);
      centerAlign(size, text);
      justifyAlign(size, text);
  }
}

int getText(char** text) {
  printf("Enter text:\n");
  int size = 1;
  for (int i = 0; i < HEIGHT; i++) {
    char* line;
    line = malloc(WIDTH * sizeof(char));
    fgets(line, sizeof(line), stdin);
    if (isspace(line[0])) {
      break;
    }
    strncpy(text[i], line, WIDTH - 1);
    text[i][WIDTH - 1] = '\0';
    size++;
  }
  return size;
}

void leftAlign(int size, char** text) {
  printf("You text align to the left:\n");
  for (int i = 0; i < size; i++) {
    printf("%s", text[i]);
  }
  printf("\n");
}

void rightAlign(int size, char** text) {
  printf("You text align to the right:\n");
  for (int i = 0; i < size; i++) {
    char* line = malloc(WIDTH * sizeof(char));
    memset(line, ' ', WIDTH - 1);
    strcpy(&line[WIDTH - strlen(text[i]) - 1], text[i]);
    printf("%s", line);
  }
  printf("\n");
}

void centerAlign(int size, char** text) {
  printf("You text align to the center:\n");
  for (int i = 0; i < size; i++) {
    char* line = malloc(WIDTH * sizeof(char));
    memset(line, ' ', WIDTH - 1);
    strcpy(&line[(WIDTH - strlen(text[i])) / 2], text[i]);
    printf("%s", line);
  }
  printf("\n");
}

void justifyAlign(int size, char** text) {
  printf("You text align to the justify:\n");

  for (int i = 0; i < size; i++) {
    int length = strlen(text[i]);
    int count_gaps = 0;

    // Count spaces between words
    for (int letter = 0; letter < length; letter++) {
      if (text[i][letter] == ' ') {
        count_gaps++;
      }
    }

    // Calculate the number of spaces between words
    int space_between_words = (WIDTH - length) / count_gaps;
    int extra_spaces = (WIDTH - length) % count_gaps;

    for (int letter = 0; letter < length; letter++) {
      if (text[i][letter] == ' ') {
        // Add spaces between words
        int num_spaces = space_between_words + (extra_spaces > 0 ? 1 : 0);
        if (length == 4) {
          num_spaces--;
        }
        for (int s = 0; s < num_spaces; s++) {
          printf(" ");
        }
        extra_spaces--;  // Distribute extra spaces
      } else {
        printf("%c", text[i][letter]);
      }
    }
  }
  printf("\n");
}
