#ifndef UTILITIES_H
#define UTILITIES_H

#define MAX_NAME_LENGTH 100
#define MAX_TYPE_LENGTH 100

typedef struct {
  int id;
  char name[MAX_NAME_LENGTH];
  char type[MAX_TYPE_LENGTH];
  int capacity;
} Space;

typedef struct {
  Space *spaces;
  int numSpaces;
  int unsavedSpaces;
} SpaceManager;
// move those

int inputSpaceCapacity(const char *msg, int min, int max);
void inputSpaceName(char *name, int maxLength, const char *msg);
void inputSpaceType(char *type, int maxLength, const char *msg);

#endif
