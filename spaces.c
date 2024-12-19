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
      pressAnyKeyToGoBack();
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

  puts("----------------------------------------");
  puts("\n             Add New Space            \n");
  puts("----------------------------------------\n");

  // Input for name
  printf("Enter space name: ");
  while (getchar() != '\n')
    ; // Clear input buffer
  fgets(newName, MAX_NAME_LENGTH, stdin);
  newName[strcspn(newName, "\n")] = '\0';

  if (newName[0] == '\0') {
    puts("Name cannot be empty.");
    return;
  }
  for (int i = 0; manager->spaces[i].name != "/0"; i++) {
    if (newName[0] == ' ') {
      puts("Name cannot be empty.");
      return;
    }
  }

  // Input for type
  printf("Enter space type (e.g., Auditorium, Meeting Room): ");
  fgets(newType, MAX_TYPE_LENGTH, stdin);
  newType[strcspn(newType, "\n")] = '\0';

  if (newType[0] == '\0') {
    puts("Error: Type cannot be empty.");
    return;
  }

  // Input for capacity
  printf("Enter space capacity: ");
  if (scanf("%d", &newCapacity) != 1 || newCapacity <= 0) {
    puts("Error: Capacity must be a positive integer.");
    while (getchar() != '\n')
      ; // Clear input buffer
    return;
  }

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
  manager->unsavedSpaces++; // Increment unsaved counter

  puts("\nSpace added successfully!");
  printf("ID: %d, Name: %s, Type: %s, Capacity: %d\n", newSpace.id,
         newSpace.name, newSpace.type, newSpace.capacity);
}