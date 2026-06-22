#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "data.h"
#include "book.h"
#include "utils.h"
#include "library.h"

Library lib = {0};

// void initMockData(Library *lib)
// {
//     // Add mock books
//     Book book1 = {1001, "The C Programming Language", "Kernighan & Ritchie", 5, 5};
//     lib->books[lib->book_count++] = book1;

//     Book book2 = {1002, "Clean Code", "Robert C. Martin", 3, 2};
//     lib->books[lib->book_count++] = book2;

//     Book book3 = {1003, "Design Patterns", "Gang of Four", 2, 1};
//     lib->books[lib->book_count++] = book3;

//     lib->next_book_id = 1004;

//     // Add mock members
//     Member member1 = {2001, "Alice Johnson"};
//     lib->members[lib->member_count++] = member1;

//     Member member2 = {2002, "Bob Smith"};
//     lib->members[lib->member_count++] = member2;

//     lib->next_member_id = 2003;

//     // Add mock borrow records
//     BorrowRecord rec1 = {3001, 1002, 2001, 0};
//     lib->records[lib->record_count++] = rec1;

//     BorrowRecord rec2 = {3002, 1003, 2002, 0};
//     lib->records[lib->record_count++] = rec2;

//     lib->next_record_id = 3003;
// }

int main()
{
    initLibrary(&lib);
    // initMockData(&lib);
    loadLibrary(&lib);

    mainMenu(&lib);

    printf("\n");
    printf("┌──── Confirm & Exit ──────┐\n");
    printf("├──────────────────────────┤\n");
    printf("| 1. Save & Exit           |\n");
    printf("├──────────────────────────┤\n");
    printf("| 0. Exit Without Saving   |\n");
    printf("└──────────────────────────┘\n");

    int choice = getIntInput("Enter your choice: ");

    if (choice == 1)
    {
        saveLibrary(&lib);
    }
    else if (choice == 0)
    {
        printf("┌─────────────────────────┐\n");
        printf("|  Exited Without Saving  |\n");
        printf("└─────────────────────────┘\n");
    }

    freeLibrary(&lib);

    return 0;
}