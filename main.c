#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Print the menu
    printf("Menu:\n");
    printf("1. Run script 1\n");
    printf("2. Exit\n");

    // Get the user's choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Run the script or exit the program
    switch (choice)
    {
        case 1:
            // Run the script
            system("./scripts/script1.c");
            break;
        case 2:
            // Exit the program
            return 0;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
