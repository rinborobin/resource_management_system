#include "book.h"
#include <stdio.h>

void addBook(Library *lib)
{
}

void viewBooks(Library *lib)
{
}
void searchBook(Library *lib) {};

void updateBook(Library *lib)
{
}

void removeBook(Library *lib)
{
}

void displayBookSummary(Library *lib) {};
void bookMenu(Library *lib)
{
    int choice;

    do
    {
        printf("\n=================================\n");
        printf("       BOOK MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Remove Book\n");
        printf("0. Back\n");
        printf("=================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook(lib);
            break;

        case 2:
            viewBooks(lib);
            break;

        case 3:
            searchBook(lib);
            break;

        case 4:
            updateBook(lib);
            break;

        case 5:
            removeBook(lib);
            break;

        case 0:
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);
}
