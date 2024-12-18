#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "spaces.h"
#include "data.h"

int loadFile(SpaceManager *manager)
{
    char line[256];
    FILE *file = fopen("spaces.csv", "r");
    int countSpaces = 0;
    int index = 0;

    if (file == NULL)
    {
        printf("Could not open file spaces.csv\n");
        return -1;
    }

    // Count the number of lines (spaces)
    while (fgets(line, sizeof(line), file))
    {
        countSpaces++;
    }
    rewind(file); // reads file from the beginning

    // Allocate memory to ensure the correct size for Space structures
    manager->spaces = malloc(countSpaces * sizeof(*manager->spaces));

    while (fgets(line, sizeof(line), file))
    {
        char *cell;
        cell = strtok(line, ",");
        manager->spaces[index].id = atoi(cell);

        cell = strtok(NULL, ",");
        strncpy(manager->spaces[index].name, cell, MAX_NAME_LENGTH - 1);

        cell = strtok(NULL, ",");
        strncpy(manager->spaces[index].type, cell, MAX_TYPE_LENGTH - 1);

        cell = strtok(NULL, ",");
        manager->spaces[index].capacity = atoi(cell);

        index++;
    }
    fclose(file);

    manager->numSpaces = countSpaces;
    printf("Loaded %d spaces from file.\n", manager->numSpaces);
    return countSpaces;
}