#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "spaces.h"
#include "data.h"

int main()
{
    int choice;
    Space *spaces = NULL;
    int numSpaces = 0;

    do
    {
        puts("\n------------------------------------------");
        puts("                 MainMenu                 ");
        puts("------------------------------------------");
        puts("1. SMS Menu");
        puts("2. Load file");
        puts("3. Save file");
        puts("4. Exit");
        puts("------------------------------------------\n");
        puts("Please select an option 1-4: ");

        if (scanf("%d", &choice) != 1)
        {
            puts("\nInvalid input, Please enter a number between 1 and 4\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
            smsMenu(&spaces, &numSpaces);
            break;
        case 2:
        {
            int loaded = loadFile(&spaces);
            if (loaded >= 0)
            {
                numSpaces = loaded;
                puts("File loaded successfully.");
            }
            break;
        }
        case 4:
            puts("Exiting....");
            free(spaces);
            return 0;
        default:
            puts("Invalid choice, Please try again.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}