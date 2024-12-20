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
    case 4:
      clearConsole();
      deleteSpace(manager);
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
  if (!manager->fileLoaded) {
    puts("No spaces loaded, please load file first.");
    return;
  }

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

void addNewSpace(SpaceManager *manager) {
  if (!manager->fileLoaded) {
    puts("No spaces loaded, please load file first to create a new space");
    return;
  }

  int newId;
  char newName[MAX_NAME_LENGTH];
  char newType[MAX_TYPE_LENGTH];
  int newCapacity;
  Space *temp = NULL;

  // If memory is empty, allocate space for the first element
  if (manager->spaces == NULL) {
    temp = malloc(sizeof(Space));
    manager->spaces = temp;
    newId = 1;
  } else {
    Space *temp =
        realloc(manager->spaces, (manager->numSpaces + 1) * sizeof(Space));
    manager->spaces = temp;

    newId = manager->numSpaces + 1;
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

void deleteSpace(SpaceManager *manager) {
  int deleteId;
  int foundSpaceId = -1;

  if (!manager->fileLoaded || manager->numSpaces == 0 ||
      manager->spaces == NULL) {
    puts("No spaces available to delete");
    return;
  }

  puts("----------------------------------------"
       "\n            Delete Space             \n"
       "----------------------------------------\n");

  deleteId =
      getInt(1, manager->numSpaces, "Enter the ID of the space to delete: ");

  // finding the id
  for (int i = 0; i < manager->numSpaces; i++) {
    if (manager->spaces[i].id == deleteId) {
      foundSpaceId = i;
      break;
    }
  }

  if (foundSpaceId == -1) {
    puts("Space with that ID was not found");
    return;
  }

  // Shift spaces and change ID numbers to make them in order
  for (int i = foundSpaceId; i < manager->numSpaces - 1; i++) {
    manager->spaces[i] = manager->spaces[i + 1];
    manager->spaces[i].id = i + 1;
  }

  manager->numSpaces--;
  manager->unsavedSpaces++;

  if (manager->numSpaces == 0) {
    // if no spaces left
    free(manager->spaces);
    manager->spaces = NULL;
  } else {
    Space *temp = realloc(manager->spaces, manager->numSpaces * sizeof(Space));
    manager->spaces = temp;
  }

  clearConsole();
  puts("Space deleted successfully");
}