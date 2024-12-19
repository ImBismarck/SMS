#include "spaces.h"
#include "data.h"
#include "input.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spacesMenu(SpaceManager *manager) {
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
      viewAllSpaces(manager);
      break;
    case 2:
      clearConsole();
      addNewSpace(manager);
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

void viewAllSpaces(SpaceManager *manager) {
  if (manager->numSpaces == 0) {
    puts("No spaces loaded, please load file first.");
  } else {

    puts("----------------------------------------"
         "\n          Available Spaces          \n"
         "----------------------------------------\n");

    for (int i = 0; i < manager->numSpaces; i++) {
      printf("ID      : %d\n", manager->spaces[i].id);
      printf("Name    : %s\n", manager->spaces[i].name);
      printf("Type    : %s\n", manager->spaces[i].type);
      printf("Capacity: %d\n", manager->spaces[i].capacity);
      puts("----------------------------------------\n");
    }
    puts("End of spaces list\n");
  }
}

void addNewSpace(SpaceManager *manager) {
  int newId;
  char newName[MAX_NAME_LENGTH];
  char newType[MAX_TYPE_LENGTH];
  int newCapacity;

  // If memory is empty, allocate space for the first element
  if (manager->spaces == NULL) {
    manager->spaces = malloc(sizeof(Space));
    newId = 1; // Start with ID 0 when memory is empty
  } else {
    Space *temp =
        realloc(manager->spaces, (manager->numSpaces + 1) * sizeof(Space));

    manager->spaces = temp;
    newId = manager->numSpaces;
  }

  puts("----------------------------------------"
       "\n             Add New Space            \n"
       "----------------------------------------\n");

  inputSpaceName(newName, MAX_NAME_LENGTH, "Enter space name: ");
  inputSpaceType(newType, MAX_TYPE_LENGTH, "Enter space type: ");
  newCapacity = inputSpaceCapacity("Enter space capacity: ", 1, 10000);

  // Create new space
  Space newSpace;
  newSpace.id = newId;
  strncpy(newSpace.name, newName, MAX_NAME_LENGTH - 1);
  strncpy(newSpace.type, newType, MAX_TYPE_LENGTH - 1);
  newSpace.name[MAX_NAME_LENGTH - 1] = '\0';
  newSpace.type[MAX_TYPE_LENGTH - 1] = '\0';
  newSpace.capacity = newCapacity;

  // Add to manager's array
  manager->spaces[manager->numSpaces] = newSpace;
  manager->numSpaces++;
  manager->unsavedSpaces++;

  clearConsole();
  puts("\nSpace added successfully!");
  printf("ID      : %d\n", newSpace.id);
  printf("Name    : %s\n", newSpace.name);
  printf("Type    : %s\n", newSpace.type);
  printf("Capacity: %d\n", newSpace.capacity);
}