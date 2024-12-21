#ifndef UTILITIES_H
#define UTILITIES_H

#include <time.h>

#define MAX_NAME_LENGTH 100
#define MAX_TYPE_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 320

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
  int fileLoaded;
} SpaceManager;

typedef struct {
  int id;
  char name[MAX_NAME_LENGTH];
  char phoneNumber[MAX_PHONE_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  int nif;
  struct tm registrationDate;
} Client;

typedef struct {
  Client *clients;
  int numClients;
  int unsavedClients;
  int fileLoaded;
} ClientManager;

void inputName(char *name, int maxLength, const char *msg);

// Spaces
int inputSpaceCapacity(const char *msg, int min, int max);
void inputSpaceType(char *type, int maxLength, const char *msg);

// Clients
void inputPhoneNumber(char *phoneNumber, int maxLength, const char *msg);
void inputEmail(char *email, int maxLength, const char *msg);
int inputNif(ClientManager clientManager);

#endif
