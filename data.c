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

  FILE *file = fopen("spaces.bin", "wb");
  if (file == NULL) {
    printf("Could not open file spaces.bin for writing.\n");
    return -1;
  }

  fwrite(&manager->numSpaces, sizeof(int), 1, file);

  for (int i = 0; i < manager->numSpaces; i++) {
    fwrite(&manager->spaces[i].id, sizeof(int), 1, file);
    fwrite(manager->spaces[i].name, sizeof(char), MAX_NAME_LENGTH, file);
    fwrite(manager->spaces[i].type, sizeof(char), MAX_TYPE_LENGTH, file);
    fwrite(&manager->spaces[i].capacity, sizeof(int), 1, file);
  }

  fclose(file);
  puts("Successfully changes to file\n");
  manager->unsavedSpaces = 0; // Reset unsaved counter after saving
  return 0;
}

int loadFile(SpaceManager *manager) {
  // Free existing memory if any
  if (manager->spaces != NULL) {
    free(manager->spaces);
    manager->spaces = NULL;
    manager->numSpaces = 0;
  }

  char line[256];
  int countSpaces = 0;

  FILE *file = fopen("spaces.bin", "rb");
  if (file == NULL) {
    printf("Could not open file spaces.bin\n");
    return -1;
  }

  // Read the number of spaces
  fread(&manager->numSpaces, sizeof(int), 1, file);
  manager->spaces = malloc(manager->numSpaces * sizeof(Space));

  // Read spaces data
  for (int index = 0; index < manager->numSpaces; index++) {
    fread(&manager->spaces[index].id, sizeof(int), 1, file);
    fread(manager->spaces[index].name, sizeof(char), MAX_NAME_LENGTH, file);
    manager->spaces[index].name[MAX_NAME_LENGTH - 1] =
        '\0'; // mark the end of the string

    fread(manager->spaces[index].type, sizeof(char), MAX_TYPE_LENGTH, file);
    manager->spaces[index].type[MAX_TYPE_LENGTH - 1] = '\0';

    fread(&manager->spaces[index].capacity, sizeof(int), 1, file);
  }

  manager->fileLoaded = 1;
  fclose(file);
  puts("Loaded spaces from file");
  return manager->numSpaces;
}