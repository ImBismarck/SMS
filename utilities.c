#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

void pressAnyKeyToGoBack()
{
    puts("\nEnter any key to go back...");
    getchar(); // clear input buffer
    getchar(); // wait for user input
    clearConsole();
}

void clearConsole()
{
    system("cls");
}