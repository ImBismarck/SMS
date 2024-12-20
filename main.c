#include "data.h"
#include "input.h"
#include "menu.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice;
  SpaceManager manager = {NULL, 0, 0, 0};

  clearConsole();

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
      smsMenu(&manager);
      break;
    case 2:
      clearConsole();
      loadFile(&manager);
      break;
    case 3:
      clearConsole();
      saveFile(&manager);
      break;
    case 4:
      clearConsole();
      puts("Exiting....");
      free(manager.spaces);
      return 0;
    default:
      clearConsole();
      puts("Invalid choice, Please try again.\n");
      break;
    }
  } while (choice != 4);

  return 0;
}