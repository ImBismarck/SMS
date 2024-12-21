#include "data.h"
#include "input.h"
#include "menu.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice;
  SpaceManager spaceManger = {NULL, 0, 0, 0};
  ClientManager clientManager = {NULL, 0, 0, 0};
  clearConsole();
  mainMenu(&spaceManger, &clientManager);
  return 0;
}