#include "library.h"
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include "library.h"
#include "book.h"
#include "member.h"
#include "borrow.h"

void initLibrary(Library *lib)
{
    lib->book_capacity = 10;
    lib->books = malloc(lib->book_capacity * sizeof(Book));
    lib->book_count = 0;
    lib->next_book_id = 1001;

    lib->member_capacity = 10;
    lib->member_count = 0;
    lib->next_member_id = 2001;

    lib->record_capacity = 10;
    lib->record_count = 0;
    lib->next_record_id = 3001;
};
void freeLibrary(Library *lib) {};

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
            printf("\nTotal Books   : %d\n", lib->book_count);
            printf("Total Members : %d\n", lib->member_count);
            printf("Total Records : %d\n", lib->record_count);
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
