#include "input.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// get integer input within a specific range
int getInt(int minValue, int maxValue, char *msg) {
  int value;
  printf("%s", msg);
  while (scanf("%d", &value) != 1 || value < minValue || value > maxValue) {
    puts(INVALID_VALUE);
    clearInputBuffer();
    printf("%s", msg);
  }
  clearInputBuffer();
  return value;
}

// get string
void readString(char *string, unsigned int size, char *msg) {
  printf("%s", msg);
  if (fgets(string, size, stdin) != NULL) {
    unsigned int last = strlen(string) - 1;
    if (string[last] == '\n') {
      string[last] = '\0'; // end a string
    } else {
      clearInputBuffer();
    }
  }
}