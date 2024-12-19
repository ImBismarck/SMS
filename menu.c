#include "menu.h"
#include "input.h"
#include "spaces.h"
#include <stdio.h>
#include <stdlib.h>

void manageClients() {}
void manageReservations() {}
void manageEquipments() {}
void generateReports() {}

void smsMenu(SpaceManager *manager) {
  int choice;
  do {
    choice = getInt(1, 5,
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
      spacesMenu(manager);
      break;
    case 2:
      manageClients();
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