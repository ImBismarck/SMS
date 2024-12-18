#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "spaces.h"

Space *spaces = NULL; // Dynamically allocated array
int numSpaces = 0;

int loadFile(Space **spaces)
{
    char line[256];
    FILE *file = fopen("spaces.csv", "r");
    int index = 0;

    if (file == NULL)
    {
        printf("Error: Could not open file spaces.csv\n");
        return -1;
    }

    // Count the number of lines (spaces)
    while (fgets(line, sizeof(line), file))
    {
        numSpaces++;
    }
    rewind(file);

    // Allocate memory dynamically
    *spaces = (Space *)malloc(numSpaces * sizeof(Space));
    if (*spaces == NULL)
    {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return -1;
    }

    // Read and parse the file into the dynamically allocated array
    while (fgets(line, sizeof(line), file))
    {
        char *cell;
        cell = strtok(line, ",");
        (*spaces)[index].id = atoi(cell);

        cell = strtok(NULL, ",");
        strncpy((*spaces)[index].name, cell, MAX_NAME_LENGTH - 1);

        cell = strtok(NULL, ",");
        strncpy((*spaces)[index].type, cell, MAX_TYPE_LENGTH - 1);

        cell = strtok(NULL, ",");
        (*spaces)[index].capacity = atoi(cell);

        index++;
    }
    fclose(file);

    printf("Loaded %d spaces from file.\n", numSpaces);
    return 0;
}
