#include "data.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int saveFile(SpaceManager *spacesManager, ClientManager *clientManager) {
  if (!spacesManager->fileLoaded || !clientManager->fileLoaded) {
    puts("No file has been loaded, please load a file first");
    return -1;
  }

  if (spacesManager->unsavedSpaces == 0 && clientManager->unsavedClients == 0) {
    puts("No new spaces to save.");
    return 0;
  }

  FILE *file = fopen("data.bin", "wb");
  if (file == NULL) {
    printf("Could not open file data.bin for writing.\n");
    return -1;
  }
  // Spaces
  fwrite(&spacesManager->numSpaces, sizeof(int), 1, file);

  for (int i = 0; i < spacesManager->numSpaces; i++) {
    fwrite(&spacesManager->spaces[i].id, sizeof(int), 1, file);
    fwrite(spacesManager->spaces[i].name, sizeof(char), MAX_NAME_LENGTH, file);
    fwrite(spacesManager->spaces[i].type, sizeof(char), MAX_TYPE_LENGTH, file);
    fwrite(&spacesManager->spaces[i].capacity, sizeof(int), 1, file);
  }

  // Clients
  fwrite(&clientManager->numClients, sizeof(int), 1, file);

  for (int i = 0; i < clientManager->numClients; i++) {
    fwrite(&clientManager->clients[i].id, sizeof(int), 1, file);
    fwrite(clientManager->clients[i].name, sizeof(char), MAX_NAME_LENGTH, file);
    fwrite(clientManager->clients[i].phoneNumber, sizeof(char),
           MAX_PHONE_LENGTH, file);
    fwrite(clientManager->clients[i].email, sizeof(char), MAX_EMAIL_LENGTH,
           file);
    fwrite(&clientManager->clients[i].nif, sizeof(int), 1, file);
    fwrite(&clientManager->clients[i].registrationDate, sizeof(struct tm), 1,
           file);
  }

  fclose(file);
  puts("Successfully changes to file\n");
  clientManager->unsavedClients = 0;
  spacesManager->unsavedSpaces = 0;
  return 0;
}

int loadFile(SpaceManager *spacesManager, ClientManager *clientManager) {
  // Free existing memory if any
  if (spacesManager->spaces != NULL) {
    free(spacesManager->spaces);
    spacesManager->spaces = NULL;
    spacesManager->numSpaces = 0;
  }

  if (clientManager->clients != NULL) {
    free(clientManager->clients);
    clientManager->clients = NULL;
    clientManager->numClients = 0;
  }

  FILE *file = fopen("data.bin", "rb");
  if (file == NULL) {
    printf("Could not open file data.bin\n");
    return -1;
  }

  // Read the number of spaces
  fread(&spacesManager->numSpaces, sizeof(int), 1, file);
  spacesManager->spaces = malloc(spacesManager->numSpaces * sizeof(Space));

  // Read spaces data
  for (int index = 0; index < spacesManager->numSpaces; index++) {
    fread(&spacesManager->spaces[index].id, sizeof(int), 1, file);
    fread(spacesManager->spaces[index].name, sizeof(char), MAX_NAME_LENGTH,
          file);
    spacesManager->spaces[index].name[MAX_NAME_LENGTH - 1] =
        '\0'; // mark the end of the string

    fread(spacesManager->spaces[index].type, sizeof(char), MAX_TYPE_LENGTH,
          file);
    spacesManager->spaces[index].type[MAX_TYPE_LENGTH - 1] = '\0';

    fread(&spacesManager->spaces[index].capacity, sizeof(int), 1, file);
  }
  // Clients
  fread(&clientManager->numClients, sizeof(int), 1, file);
  clientManager->clients = malloc(clientManager->numClients * sizeof(Client));

  for (int i = 0; i < clientManager->numClients; i++) {
    fread(&clientManager->clients[i].id, sizeof(int), 1, file);
    fread(clientManager->clients[i].name, sizeof(char), MAX_NAME_LENGTH, file);
    clientManager->clients[i].name[MAX_NAME_LENGTH - 1] =
        '\0'; // Null-terminate the string

    fread(clientManager->clients[i].phoneNumber, sizeof(char), MAX_PHONE_LENGTH,
          file);
    clientManager->clients[i].phoneNumber[MAX_PHONE_LENGTH - 1] =
        '\0'; // Null-terminate the string

    fread(clientManager->clients[i].email, sizeof(char), MAX_EMAIL_LENGTH,
          file);
    clientManager->clients[i].email[MAX_EMAIL_LENGTH - 1] =
        '\0'; // Null-terminate the string

    fread(&clientManager->clients[i].nif, sizeof(int), 1, file);

    fread(&clientManager->clients[i].registrationDate, sizeof(struct tm), 1,
          file); // Load registration date
  }

  spacesManager->fileLoaded = 1;
  clientManager->fileLoaded = 1;

  spacesManager->unsavedSpaces = 0;

  fclose(file);
  puts("Loaded files");
  return 0;
}