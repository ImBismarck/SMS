#include <stdio.h>
#include <stdlib.h>
#include "spaces.h"
#include "data.h"
#include "utilities.h"

void viewAllSpaces(SpaceManager *manager)
{
    if (manager->numSpaces == 0)
    {
        printf("No spaces loaded. Please load file first.\n");
        return;
    }

    printf("Available Spaces:\n");
    printf("ID  Name                Type           Capacity\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < manager->numSpaces; i++)
    {
        printf("%-3d %-18s %-15s %-10d\n",
               manager->spaces[i].id,
               manager->spaces[i].name,
               manager->spaces[i].type,
               manager->spaces[i].capacity);
    }
}

void spacesMenu(SpaceManager *manager)
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
            viewAllSpaces(manager);
            pressAnyKeyToGoBack();
            break;
        case 2:
            // addNewSpace(manager);
            break;
        case 5:
            puts("Exiting Spaces Management Menu...\n");
            return;
        default:
            puts("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);
}