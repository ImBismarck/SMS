#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "spaces.h"
#include "data.h"

int loadFile(SpaceManager *manager)
{
    char line[256];
    FILE *file = fopen("spaces.csv", "r");
    int count = 0;
    int index = 0;

    if (file == NULL)
    {
        printf("Error: Could not open file spaces.csv\n");
        return -1;
    }

    // Count the number of lines (spaces)
    while (fgets(line, sizeof(line), file))
    {
        count++;
    }
    rewind(file);

    // Free existing memory if any
    if (manager->spaces != NULL)
    {
        free(manager->spaces);
    }

    // Allocate memory dynamically
    manager->spaces = (Space *)malloc(count * sizeof(Space));
    if (manager->spaces == NULL)
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

    manager->numSpaces = count;
    printf("Loaded %d spaces from file.\n", manager->numSpaces);
    return count;
}