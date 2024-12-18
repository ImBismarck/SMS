#include <stdio.h>
#include <stdlib.h>
#include "spaces.h"
#include "data.h"

void pressAnyKeyToGoBack()
{
    puts("\nEnter any key to go back...");
    getchar(); // clear input buffer
    getchar(); // wait for user input
}

void viewAllSpaces(Space *spaces, int numSpaces)
{
    if (numSpaces == 0)
    {
        printf("No spaces loaded. Please load file first.\n");
        return;
    }

    printf("Available Spaces:\n");
    printf("ID  Name                Type           Capacity\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < numSpaces; i++)
    {
        printf("%-3d %-18s %-15s %-10d\n",
               spaces[i].id,
               spaces[i].name,
               spaces[i].type,
               spaces[i].capacity);
    }
}

void spacesMenu()
{
    int choice;

    do
    {
        puts("Spaces Management");
        puts("------------------\n");
        puts("1. View All Spaces\n");
        puts("2. Add New Space\n");
        puts("3. Update Existing Space\n");
        puts("4. Delete Space\n");
        puts("5. Back to Main Menu\n");
        puts("------------------\n");
        puts("Please select an option 1-5: ");

        if (scanf("%d", &choice) != 1)
        {
            puts("\nInvalid input, Please enter a number between 1 and 5\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
            // Use global variables directly
            viewAllSpaces(spaces, numSpaces);
            pressAnyKeyToGoBack();
            break;
        case 2:
            // addNewSpace(spaces, &numSpaces);
            break;
        // case 3:
        //     updateExistingSpace();
        //     break;
        // case 4:
        //     deleteSpace();
        //     break;
        case 5:
            puts("Exiting Spaces Management Menu...\n");
            return;
        default:
            puts("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);
}