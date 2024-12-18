#ifndef UTILITIES_H
#define UTILITIES_H

#define MAX_NAME_LENGTH 100
#define MAX_TYPE_LENGTH 100

typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int capacity;
} Space;

typedef struct
{
    Space *spaces;
    int numSpaces;
} SpaceManager;

void pressAnyKeyToGoBack();

#endif
