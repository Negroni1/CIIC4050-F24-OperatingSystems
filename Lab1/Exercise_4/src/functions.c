#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Replace(char* src, char** dst, char find, char replacement) {
  *dst = (char*)malloc(MAX_LENGTH * sizeof(char));
  for (int i = 0; i < strlen(src); i++) {
    if (src[i] != find) {
      (*dst)[i] = src[i];
    } else {
      (*dst)[i] = replacement;
    }
  }
  (*dst)[strlen(src)] = '\0';
}

void Insert(char* src, char** dst, char find, char* ins) {
  int dst_len = 0;
  *dst = (char*)malloc(MAX_LENGTH * sizeof(char));
  for (int i = 0; i < strlen(src); i++) {
    (*dst)[i + dst_len] = src[i];
    if (src[i] == find) {
      // Insert all characters from the insert string
      for (int j = 0; j < strlen(ins); j++) {
        (*dst)[dst_len + i + j + 1] = ins[j];
      }
      dst_len += strlen(ins);
    }
  }
  (*dst)[strlen(*dst)] = '\0';
}
