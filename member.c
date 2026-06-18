#include "book.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include <stdio.h>
#include <ctype.h>
Member inputMember(Library *lib, bool is_update)
{
    getchar();
    Member member;

    char name[100];

    int member_id;

    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);

    strcpy(member.name, name);

    return member;
}

void addMember(Library *lib)
{
    if (lib->member_count == lib->member_capacity)
    {
        int new_capacity = lib->member_capacity * 2;

        Member *temp = realloc(
            lib->members,
            new_capacity * sizeof(Member));

        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        lib->members = temp;
        lib->member_capacity = new_capacity;
    }

    Member member = inputMember(lib, false);

    member.member_id = lib->next_member_id;
    lib->next_member_id++;

    lib->members[lib->member_count] = member;
    lib->member_count++;

    printf("Member added successfully!\n");
}

int searchMember(Library *lib, int member_id)
{
    for (int i = 0; i < lib->member_count; i++)
    {
        if (lib->members[i].member_id == member_id)
        {
            return i;
        }
    }
    return -1;
}

void viewMembers(Library *lib, int index) // Ly Sievminh
{
    printf("ID: %d, Name: %s\n", lib->members[index].member_id, lib->members[index].name);
}
void searchByName(Library *lib, char name[])
{
    char member_name[100];
    char search_name[100];

    strcpy(search_name, name);

    for (int i = 0; i < lib->member_count; i++)
    {
        strcpy(member_name, lib->members[i].name);

        toLowerString(member_name);
        toLowerString(search_name);

        if (strstr(member_name, search_name) != NULL)
        {

            viewMembers(lib, i);
        }
    }
}

void viewAllMembers(Library *lib)
{
    if (lib->member_count == 0)
    {
        printItemNotFound("Member");
        return;
    }
    for (int i = 0; i < lib->member_count; i++)
    {
        viewMembers(lib, i);
    }
}
void updateMember(Library *lib)
{
    int member_id;
    member_id = getIntInput("Enter Member ID to Update: ");

    int index = searchMember(lib, member_id);
    if (index == -1)
    {
        printf("Member not found.\n");
        return;
    }
    Member updated = inputMember(lib, true);
    updated.member_id = lib->members[index].member_id;
    lib->members[index] = updated;
    printf("Member updated successfully!\n");
}
void removeMember(Library *lib)
{
    int member_id;
    member_id = getIntInput("Enter Member ID to Remove: ");

    int index = searchMember(lib, member_id);
    if (index == -1)
    {
        printf("Member not found.\n");
        return;
    }
    for (int i = index; i < lib->member_count - 1; i++)
    {
        lib->members[i] = lib->members[i + 1];
    }
    lib->member_count--;
}

void memberMenu(Library *lib) // Ly Sievminh
{
    int choice;
    int member_id;
    bool is_running = true;
    do
    {
        printf("\n=================================\n");
        printf("       Member Management Menu\n");
        printf("=================================\n");
        printf("1. Add Member\n");
        printf("2. View Members\n");
        printf("3. search Member\n");
        printf("4. Update Member\n");
        printf("5. Remove Member\n");

        printf("0. Back to Main Menu\n");
        choice = getIntInput("Enter Choice: ");
        switch (choice)
        {
        case 1:
            addMember(lib);
            break;
        case 2:
            viewAllMembers(lib);
            break;
        case 3:
            int search_menu_choice;
            char name[100];

            do
            {
                printf("\nSearch Member By:\n");
                printf("1. ID\n");
                printf("2. Name\n");
                printf("0. Back\n");
                search_menu_choice = getIntInput("Enter Choice: ");
                switch (search_menu_choice)
                {
                case 1:
                    member_id = getIntInput("Enter Member ID to Search: ");
                    searchMember(lib, member_id);
                    break;
                case 2:
                    printf("Enter the member name to search: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';
                    searchByName(lib, name);
                    break;
                case 0:
                    printf("Returning to Member Menu...\n");
                    break;
                default:
                    printf("Invalid choice! Please try again.\n");
                }
            } while (search_menu_choice != 0);
            break;
        case 4:

            updateMember(lib);
            break;
        case 5:

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