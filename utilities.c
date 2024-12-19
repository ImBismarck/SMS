#include "utilities.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputSpaceName(char *name, int maxLength, const char *msg) {
  do {
    readString(name, maxLength, msg);
    if (strlen(name) == 0) {
      puts("Name cannot be empty. Please try again.");
    } else {
      capitalizeWords(name);
    }
  } while (strlen(name) == 0);
}

void inputSpaceType(char *type, int maxLength, const char *msg) {
  do {
    readString(type, maxLength, msg);
    if (strlen(type) == 0) {
      puts("Type cannot be empty. Please try again.");
    } else {
      capitalizeWords(type);
    }
  } while (strlen(type) == 0);
}

int inputSpaceCapacity(const char *msg, int min, int max) {
  return getInt(min, max, msg);
}