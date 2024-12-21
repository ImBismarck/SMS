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
  mainMenu(&manager);
  return 0;
}