#include "borrow.h"
#include <stdio.h>
void borrowBook(Library *lib)
{
}
void returnBook(Library *lib)
{
}

void viewRecords(Library *lib) // Ly Sievminh
{
}
void borrowMenu(Library *lib) // Ly Sievminh
{
    int choice;
    do
    {
        printf("\n=================================\n");
        printf("       BORROW MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Borrow Book\n");
        printf("2. Return Book\n");
        printf("3. View Records\n");
        printf("0. Back\n");
        printf("=================================\n");
        printf("Enter choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            borrowBook(lib);
            break;
        case 2:
            returnBook(lib);
            break;
        case 3:
            viewRecords(lib);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 0);
}