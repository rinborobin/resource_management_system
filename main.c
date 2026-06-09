#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "data.h"
#include "library.h"

Library lib = {0};

void initMockData(Library *lib)
{
    // Add mock books
    Book book1 = {1001, "The C Programming Language", "Kernighan & Ritchie", 5, 5};
    lib->books[lib->book_count++] = book1;

    Book book2 = {1002, "Clean Code", "Robert C. Martin", 3, 2};
    lib->books[lib->book_count++] = book2;

    Book book3 = {1003, "Design Patterns", "Gang of Four", 2, 1};
    lib->books[lib->book_count++] = book3;

    lib->next_book_id = 1004;

    // Add mock members
    Member member1 = {2001, "Alice Johnson"};
    lib->members[lib->member_count++] = member1;

    Member member2 = {2002, "Bob Smith"};
    lib->members[lib->member_count++] = member2;

    lib->next_member_id = 2003;

    // Add mock borrow records
    BorrowRecord rec1 = {3001, 1002, 2001, 0};
    lib->records[lib->record_count++] = rec1;

    BorrowRecord rec2 = {3002, 1003, 2002, 0};
    lib->records[lib->record_count++] = rec2;

    lib->next_record_id = 3003;
}

// bool createBook()
// {
//     FILE *file = fopen("./data/data.bin", "wb");

//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return 1;
//     }
//     fwrite(&lib.books, sizeof(Book), 1, file);

//     fclose(file);
//     printf("Struct successfully written to data.bin\n");
//     return 0;
// }

// bool openBook()
// {
//     FILE *file = fopen("./data/data.bin", "rb");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return 1;
//     }

//     if (fread(&lib.books, sizeof(Book), 1, file) == 1)
//     {
//         printf("Data read successfully:\n");
//         printf("ID: %d\n", lib.books[0].book_id);
//         printf("Name: %s\n", lib.books[0].title);
//     }
//     else
//     {
//         printf("Error reading from file!\n");
//     }

//     fclose(file);
//     return 0;
// }

int main()
{
    initLibrary(&lib);
    initMockData(&lib);
    createBook();
    openBook();
    mainMenu(&lib);
    freeLibrary(&lib);

    return 0;
}