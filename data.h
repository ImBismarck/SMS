#ifndef DATA_H
#define DATA_H

#include "spaces.h"

extern Space *spaces; // Pointer for dynamically allocated spaces
extern int numSpaces;

int loadFile(Space **spaces); // Adjust to use a pointer to the pointer

#endif
