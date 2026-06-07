#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    bool isRunning = true;
    printf("\n == Library Management System ==\n");
    while (isRunning)
    {
        int choice;
        printf("1. Book Management\n");
        printf("2. Member Management\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Book Management
            break;
        case 2:
            // Member Management
            break;
        case 3:
            // Borrow Book
            break;
        case 4:
            // Return Book
            break;
        case 5:
            // Report
            break;
        case 6:
            isRunning = false;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}