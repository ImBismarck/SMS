#include "menu.h"
#include "clients.h"
#include "input.h"
#include "spaces.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

void manageClients() {}
void manageReservations() {}
void manageEquipments() {}
void generateReports() {}

void mainMenu(SpaceManager *spaceManager, ClientManager *clientManager) {
  int choice;

  do {
    choice = getInt(1, 5,
                    "----------------------------------------"
                    "\n             Main Menu              \n"
                    "----------------------------------------\n"
                    "1. SMS Menu \n"
                    "2. Load file \n"
                    "3. Save file \n"
                    "4. Exit \n"
                    "Please select an option 1-4: ");

    switch (choice) {
    case 1:
      clearConsole();
      smsMenu(spaceManager, clientManager);
      break;
    case 2:
      clearConsole();
      loadFile(spaceManager, clientManager);
      break;
    case 3:
      clearConsole();
      saveFile(spaceManager, clientManager);
      break;
    case 4:
      clearConsole();
      puts("Exiting....");
      free(spaceManager->spaces);
      free(clientManager->clients);
      return;
    default:
      clearConsole();
      puts("Invalid choice, Please try again.\n");
      break;
    }
  } while (choice != 4);
}

void smsMenu(SpaceManager *spaceManager, ClientManager *clientManager) {
  int choice;
  do {
    choice = getInt(1, 6,
                    "----------------------------------------"
                    "\n       Space Management System Menu       \n"
                    "----------------------------------------\n"
                    "1. Manage Spaces \n"
                    "2. Manage Clients \n"
                    "3. Manage Reservations \n"
                    "4. Manage Equipment \n"
                    "5. Generate Reports \n"
                    "6. Back\n"
                    "Please select an option 1-6: \n");

    switch (choice) {
    case 1:
      clearConsole();
      spacesMenu(spaceManager);
      break;
    case 2:
      clearConsole();
      clientsMenu(clientManager);
      break;
    case 3:
      manageReservations();
      break;
    case 4:
      manageEquipments();
      break;
    case 5:
      generateReports();
      break;
    case 6:
      clearConsole();
      // puts("Exiting....");
      return;
    default:
      clearConsole();
      puts("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 6);
}

void spacesMenu(SpaceManager *spaceManager) {
  int choice;

  do {
    choice = getInt(1, 5,
                    "----------------------------------------"
                    "\n          Space Management          \n"
                    "----------------------------------------\n"
                    "1. View All Spaces \n"
                    "2. Add New Space \n"
                    "3. Update Existing Space \n"
                    "4. Delete Space \n"
                    "5. Back to Main Menu \n"
                    "Please select an option 1-5: \n");

    switch (choice) {
    case 1:
      clearConsole();
      viewAllSpaces(spaceManager);
      break;
    case 2:
      clearConsole();
      addNewSpace(spaceManager);
      break;
    case 3:
      clearConsole();
      editSpace(spaceManager);
      break;
    case 4:
      clearConsole();
      deleteSpace(spaceManager);
      break;
    case 5:
      clearConsole();
      puts("Exiting Spaces Management Menu...\n");
      return;
    default:
      clearConsole();
      puts("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 5);
}

void clientsMenu(ClientManager *clientManager) {
  int choice;

  do {
    choice = getInt(1, 5,
                    "----------------------------------------"
                    "\n          Client Management          \n"
                    "----------------------------------------\n"
                    "1. View All Clients \n"
                    "2. Add New Client \n"
                    "3. Update Existing Client \n"
                    "4. Delete Client \n"
                    "5. Back to Main Menu \n"
                    "Please select an option 1-5: \n");

    switch (choice) {
    case 1:
      clearConsole();
      viewAllClients(clientManager);
      break;
    case 2:
      clearConsole();
      addNewClient(clientManager);
      break;
    case 3:
      clearConsole();
      editClients(clientManager);
      break;
    case 4:
      clearConsole();
      deleteClient(clientManager);
      break;
    case 5:
      clearConsole();
      puts("Exiting Client Management Menu...\n");
      return;
    default:
      clearConsole();
      puts("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 5);
}
