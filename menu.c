#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "spaces.h"

void manageClients() {}
void manageReservations() {}
void manageEquipments() {}
void generateReports() {}

void smsMenu()
{
    int choice;
    do
    {
        puts("----------------------------------------");
        puts("\n       Space Management System Menu       \n");
        puts("------------------------------------------\n");
        puts("1. Manage Spaces\n");
        puts("2. Manage Clients\n");
        puts("3. Manage Reservations\n");
        puts("4. Manage Equipment\n");
        puts("5. Generate Reports\n");
        puts("6. Exit\n");
        puts("----------------------------------------");
        puts("Please select an option (1-6): ");

        if (scanf("%d", &choice) != 1)
        {

            puts("\nInvalid input, Please enter a number between 1 and 6\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
            spacesMenu();
            break;
        case 2:
            manageClients();
            break;
        case 3:
            manageReservations();
            break;
        case 4:
            manageEquipments();
            break;
        case 5:
            generateReports();
            break;
        case 6:
            puts("Exiting....");
            return;
        default:
            puts("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 6);
}