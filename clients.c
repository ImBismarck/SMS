#include "clients.h"
#include "data.h"
#include "input.h"
#include "spaces.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void viewAllClients(ClientManager *clientManager) {
  if (!clientManager->fileLoaded) {
    puts("No clients loaded, please load file first.");
    return;
  }

  puts("----------------------------------------"
       "\n          Your Clients          \n"
       "----------------------------------------\n");

  for (int i = 0; i < clientManager->numClients; i++) {
    printf("ID: %d\n", clientManager->clients[i].id);
    printf("Name: %s\n", clientManager->clients[i].name);
    printf("Phone Number: %s\n", clientManager->clients[i].phoneNumber);
    printf("Email: %s\n", clientManager->clients[i].email);
    printf("NIF: %d\n", clientManager->clients[i].nif);

    // format and display date
    char dateBuffer[20];
    strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d %H:%M",
             &clientManager->clients[i].registrationDate);
    printf("Registration Date: %s\n", dateBuffer);

    puts("----------------------------------------\n");
  }
  puts("End of clients list\n");
}

void addNewClient(ClientManager *clientsManager) {
  if (!clientsManager->fileLoaded) {
    puts("No clients loaded, please load file first to create a new Client");
    return;
  }

  int newId;
  char newName[MAX_NAME_LENGTH];
  char newPhoneNumber[MAX_PHONE_LENGTH];
  char newEmail[MAX_EMAIL_LENGTH];
  int newNif;
  Client *temp = NULL;

  // If memory is empty, allocate Client for the first element
  if (clientsManager->clients == NULL) {
    temp = malloc(sizeof(Client));
    clientsManager->clients = temp;
    newId = 1;
  } else {
    Client *temp = realloc(clientsManager->clients,
                           (clientsManager->numClients + 1) * sizeof(Client));
    clientsManager->clients = temp;

    newId = clientsManager->numClients + 1;
  }

  puts("----------------------------------------"
       "\n             Add New Client            \n"
       "----------------------------------------\n");

  inputName(newName, MAX_NAME_LENGTH, "Enter Client name: ");
  inputPhoneNumber(newPhoneNumber, MAX_PHONE_LENGTH,
                   "Enter Client phone number: ");
  inputEmail(newEmail, MAX_EMAIL_LENGTH, "Enter Client email: ");
  newNif = inputNif(*clientsManager);

  // Get current date
  time_t t = time(NULL);
  struct tm *currentTime = localtime(&t);

  // Create new Client
  Client newClient;
  newClient.id = newId;
  strncpy(newClient.name, newName, MAX_NAME_LENGTH - 1);
  strncpy(newClient.phoneNumber, newPhoneNumber, MAX_PHONE_LENGTH - 1);
  strncpy(newClient.email, newEmail, MAX_EMAIL_LENGTH - 1);
  newClient.nif = newNif;
  newClient.name[MAX_NAME_LENGTH - 1] = '\0';
  newClient.phoneNumber[MAX_PHONE_LENGTH - 1] = '\0';
  newClient.email[MAX_EMAIL_LENGTH - 1] = '\0';
  newClient.registrationDate = *currentTime;

  // Add to manager's array
  clientsManager->clients[clientsManager->numClients] = newClient;
  clientsManager->numClients++;
  clientsManager->unsavedClients++;

  clearConsole();
  puts("\nClient added successfully!");
  printf("ID: %d\n", newClient.id);
  printf("Name: %s\n", newClient.name);
  printf("Phone Number: %s\n", newClient.phoneNumber);
  printf("Email: %s\n", newClient.email);
  printf("NIF: %d\n", newClient.nif);
  printf("Registration Date: %02d/%02d/%d %02d:%02d\n",
         newClient.registrationDate.tm_mday,
         newClient.registrationDate.tm_mon + 1,
         newClient.registrationDate.tm_year + 1900,
         newClient.registrationDate.tm_hour, newClient.registrationDate.tm_min);
}

void deleteClient(ClientManager *clientsManager) {
  int deleteId;
  int foundSpaceId = -1;

  if (!clientsManager->fileLoaded || clientsManager->numClients == 0 ||
      clientsManager->clients == NULL) {
    puts("No clients available to delete");
    return;
  }
  puts("----------------------------------------"
       "\n            Delete Client             \n"
       "----------------------------------------\n");

  deleteId = getInt(1, clientsManager->numClients,
                    "Enter the ID of the Client to delete: ");

  // finding the id
  for (int i = 0; i < clientsManager->numClients; i++) {
    if (clientsManager->clients[i].id == deleteId) {
      foundSpaceId = i;
      break;
    }
  }

  if (foundSpaceId == -1) {
    puts("Client with that ID was not found");
    return;
  }

  // Shift clients and change ID numbers to make them in order
  for (int i = foundSpaceId; i < clientsManager->numClients - 1; i++) {
    clientsManager->clients[i] = clientsManager->clients[i + 1];
    clientsManager->clients[i].id = i + 1;
  }

  clientsManager->numClients--;
  clientsManager->unsavedClients++;

  if (clientsManager->numClients == 0) {
    // if no clients left
    free(clientsManager->clients);
    clientsManager->clients = NULL;
  } else {
    Client *temp = realloc(clientsManager->clients,
                           clientsManager->numClients * sizeof(Client));
    clientsManager->clients = temp;
  }

  clearConsole();
  puts("Client deleted successfully");
}
