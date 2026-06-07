#include "library.h"
#include <stdio.h>

#include <stdio.h>
#include "library.h"
#include "book.h"
#include "member.h"
#include "borrow.h"

void bookMenu(Library *lib);
void memberMenu(Library *lib);
void borrowMenu(Library *lib);

void mainMenu(Library *lib)
{
    int choice;

    do
    {
        printf("\n=================================\n");
        printf("   LIBRARY MANAGEMENT SYSTEM\n");
        printf("=================================\n");
        printf("1. Book Management\n");
        printf("2. Member Management\n");
        printf("3. Borrow Management\n");
        printf("4. Summary Report\n");
        printf("0. Exit\n");
        printf("=================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bookMenu(lib);
            break;

        case 2:
            memberMenu(lib);
            break;

        case 3:
            borrowMenu(lib);
            break;

        case 4:
            printf("\nTotal Books   : %d\n", lib->bookCount);
            printf("Total Members : %d\n", lib->memberCount);
            printf("Total Records : %d\n", lib->recordCount);
            break;

        case 0:
            printf("Proccess Ended!\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);
}
void displaySummary(Library *lib) {};
