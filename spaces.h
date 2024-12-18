#ifndef SPACES_H
#define SPACES_H

#define MAX_NAME_LENGTH 100
#define MAX_TYPE_LENGTH 100

typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int capacity;
} Space;

extern Space *spaces; // Pointer for dynamically allocated spaces
extern int numSpaces;

void viewAllSpaces(Space *spaces, int numSpaces);
void spacesMenu();

#endif
