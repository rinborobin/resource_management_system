#include "book.h"
#include <stdbool.h>
#include <stdio.h>

void addMember(Library *lib)
{
}
void viewMembers(Library *lib) // Ly Sievmiinh
{
}
void updateMember(Library *lib)
{
}
void removeMember(Library *lib)
{
}

void memberMenu(Library *lib) // Ly Sievminh
{
    int choice;
    bool is_running = true;
    do
    {
        printf("\n=================================\n");
        printf("       Member Management Menu\n");
        printf("=================================\n");
        printf("1. Add Member\n");
        printf("2. View Members\n");
        printf("3. Update Member\n");
        printf("4. Remove Member\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            addMember(lib);
            break;
        case 2:
            viewMembers(lib);
            break;
        case 3:
            updateMember(lib);
            break;
        case 4:
            removeMember(lib);
            break;
        case 0:
            printf("Returning to Main Menu...\n");
            is_running = false;
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (is_running);
}