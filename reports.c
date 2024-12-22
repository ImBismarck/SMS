#include "reports.h"
#include <stdio.h>

void reportTotalSpaces(SpaceManager *spaceManager) {
  if (!spaceManager->fileLoaded) {
    puts("\nNo file loaded, please load a file first");
    return;
  }

  puts("----------------------------------------");
  puts("          Total Number of Spaces         ");
  puts("----------------------------------------");

  printf("Saved spaces: %d\n", spaceManager->savedSpaces);
  printf("Unsaved spaces changes: %d\n", spaceManager->unsavedSpaces);
  puts("----------------------------------------");
}
