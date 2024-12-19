#include "spaces.h"
#include "data.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

void viewAllSpaces(SpaceManager *manager) {
  if (manager->numSpaces == 0) {
    puts("No spaces loaded, please load file first.");
  } else {

    puts("----------------------------------------");
    puts("\n          Available Spaces          \n");
    puts("----------------------------------------\n");
    printf("ID  Name                Type           Capacity\n");

    for (int i = 0; i < manager->numSpaces; i++) {
      printf("%-3d %-18s %-15s %-10d\n", manager->spaces[i].id,
             manager->spaces[i].name, manager->spaces[i].type,
             manager->spaces[i].capacity);
    }
  }
}

void spacesMenu(SpaceManager *manager) {
  int choice;

  do {
    puts("----------------------------------------");
    puts("\n          Space Management          \n");
    puts("----------------------------------------\n");
    puts("1. View All Spaces");
    puts("2. Add New Space");
    puts("3. Update Existing Space");
    puts("4. Delete Space");
    puts("5. Back to Main Menu");
    puts("----------------------------------------\n");
    puts("Please select an option 1-5:");


    if (scanf("%d", &choice) != 1) {
      clearConsole();
      puts("Invalid input, Please enter a number between 1 and 5\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    switch (choice) {
    case 1:
      clearConsole();
      viewAllSpaces(manager);
      pressAnyKeyToGoBack();
      break;
    case 2:
      // addNewSpace(manager);
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