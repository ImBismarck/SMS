#include "data.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int saveFile(SpaceManager *manager) {
  if (!manager->fileLoaded) {
    puts("No file has been loaded, please load a file first");
    return -1;
  }

  if (manager->unsavedSpaces == 0) {
    puts("No new spaces to save.");
    return 0;
  }

  FILE *file = fopen("spaces.csv", "w");
  if (file == NULL) {
    printf("Could not open file spaces.csv for writing.\n");
    return -1;
  }

  for (int i = 0; i < manager->numSpaces; i++) {
    fprintf(file, "%d,%s,%s,%d\n", manager->spaces[i].id,
            manager->spaces[i].name, manager->spaces[i].type,
            manager->spaces[i].capacity);
  }

  fclose(file);
  puts("Successfully changes to file\n");
  manager->unsavedSpaces = 0; // Reset unsaved counter after saving
  return 0;
}

// In data.c
int loadFile(SpaceManager *manager) {
  // Free existing memory if any
  if (manager->spaces != NULL) {
    free(manager->spaces);
    manager->spaces = NULL;
    manager->numSpaces = 0;
  }

  char line[256];
  FILE *file = fopen("spaces.csv", "r");
  int countSpaces = 0;

  if (file == NULL) {
    printf("Could not open file spaces.csv\n");
    return -1;
  }

  // Count the number of spaces
  while (fgets(line, sizeof(line), file)) {
    countSpaces++;
  }

  // manager->numSpaces = countSpaces;
  // manager->unsavedSpaces = 0;
  // manager->fileLoaded = 1;

  // Allocate memory for spaces
  if (countSpaces > 0) {
    manager->spaces = malloc(countSpaces * sizeof(Space));
  }

  // Reset file pointer to beginning
  rewind(file);
  int index = 0;

  // Read spaces from file
  while (fgets(line, sizeof(line), file)) {
    char *cell = strtok(line, ",");
    manager->spaces[index].id = atoi(cell);

    cell = strtok(NULL, ",");
    strncpy(manager->spaces[index].name, cell, MAX_NAME_LENGTH - 1);
    manager->spaces[index].name[MAX_NAME_LENGTH - 1] = '\0';

    cell = strtok(NULL, ",");
    strncpy(manager->spaces[index].type, cell, MAX_TYPE_LENGTH - 1);
    manager->spaces[index].type[MAX_TYPE_LENGTH - 1] = '\0';

    cell = strtok(NULL, ",");
    manager->spaces[index].capacity = atoi(cell);

    index++;
  }

  manager->numSpaces = countSpaces;
  manager->unsavedSpaces = 0; // Reset unsaved counter when loading
  manager->fileLoaded = 1;
  fclose(file);
  puts("Loaded spaces from file");
  return countSpaces;
}