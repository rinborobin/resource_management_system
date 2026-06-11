#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "library.h"
#include "book.h"
#include "member.h"
#include "borrow.h"

void initLibrary(Library *lib)
{
    lib->book_capacity = 100;
    lib->books = malloc(lib->book_capacity * sizeof(Book));
    if (lib->books == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    lib->book_count = 0;
    lib->next_book_id = 1001;

    lib->member_capacity = 100;
    lib->members = malloc(lib->member_capacity * sizeof(Member));
    if (lib->members == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    lib->member_count = 0;
    lib->next_member_id = 2001;

    lib->record_capacity = 100;
    lib->records = malloc(lib->record_capacity * sizeof(BorrowRecord));
    if (lib->records == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    lib->record_count = 0;
    lib->next_record_id = 3001;
};
bool saveLibrary(Library *lib)
{
    FILE *file = fopen("./data/data.bin", "wb");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return false;
    }

    fwrite(&lib->book_count, sizeof(int), 1, file);
    fwrite(&lib->next_book_id, sizeof(int), 1, file);

    fwrite(lib->books, sizeof(Book), lib->book_count, file);

    fwrite(&lib->member_count, sizeof(int), 1, file);
    fwrite(&lib->next_member_id, sizeof(int), 1, file);

    fwrite(lib->members, sizeof(Member), lib->member_count, file);

    fwrite(&lib->record_count, sizeof(int), 1, file);
    fwrite(&lib->next_record_id, sizeof(int), 1, file);

    fwrite(lib->records, sizeof(BorrowRecord), lib->record_count, file);

    fclose(file);
    printf("Struct successfully written to data.bin\n");
    return 0;
}

bool loadLibrary(Library *lib)
{
    FILE *file = fopen("./data/data.bin", "rb");
    if (file == NULL)
    {
        // printf("Error opening file!\n");
        return false;
    }

    fread(&lib->book_count, sizeof(int), 1, file);
    fread(&lib->next_book_id, sizeof(int), 1, file);
    fread(lib->books, sizeof(Book), lib->book_count, file);

    printf("book_count=%d\n", lib->book_count);
    printf("next_book_id=%d\n", lib->next_book_id);

    fread(&lib->member_count, sizeof(int), 1, file);
    fread(&lib->next_member_id, sizeof(int), 1, file);
    fread(lib->members, sizeof(Member), lib->member_count, file);

    fread(&lib->record_count, sizeof(int), 1, file);
    fread(&lib->next_record_id, sizeof(int), 1, file);
    fread(lib->records, sizeof(BorrowRecord), lib->record_count, file);

    fclose(file);
    return true;
};

void freeLibrary(Library *lib)
{
    free(lib->books);
    free(lib->members);
    free(lib->records);
};

void bookMenu(Library *lib);   //
void memberMenu(Library *lib); // Ly Sievminh
void borrowMenu(Library *lib); //

void displayBookSummary(Library *lib); // Ly Sievminh

void summaryReport(Library *lib) // Ly Sievminh
{
    // displayBookSummary(lib);
    /*
    dISPLAY SUMMARY REPORT
        - Total book titles
        - Total book copies
        - Total book available
        - Total book borrowed

        - Total members
        - Total borrow records
    */
    int total_titles = lib->book_count;
    int total_copies = 0;
    int total_available = 0;
    for (int i = 0; i < lib->book_count; i++)
    {
        total_copies += lib->books[i].quantity;
        total_available += lib->books[i].available;
    }
    int total_borrowed = total_copies - total_available;
    int total_members = lib->member_count;
    int total_records = lib->record_count;
    int book_capacity = lib->book_capacity;
    int books_stored = lib->book_count;

    printf("\n=================================\n");
    printf("        SUMMARY REPORT\n");
    printf("=================================\n");
    printf(" \n");
    printf("Books");
    printf("\n-----------------------------\n");
    printf("\nTotal Book Titles   : %d\n", total_titles);
    printf("Total Book Copies   : %d\n", total_copies);
    printf("Total Available     : %d\n", total_available);
    printf("Total Borrowed      : %d\n", total_borrowed);
    printf("\n------------------------------\n");
    printf("Members");
    printf("\n------------------------------\n");
    printf("\nTotal Members       : %d\n", total_members);
    printf("Total Borrow Records: %d\n", total_records);
    printf("\n------------------------------\n");
    printf("System");
    printf("\n------------------------------\n");
    printf("\nBook Capacity       : %d\n", book_capacity);
    printf("Books Stored         : %d\n", books_stored);
    printf("\n=================================\n");
}

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
        scanf(" %d", &choice);

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
            // printf("\nTotal Books   : %d\n", lib->book_count);
            // printf("Total Members : %d\n", lib->member_count);
            // printf("Total Records : %d\n", lib->record_count);
            summaryReport(lib); // Ly Sievminh
            break;

        case 0:
            printf("Proccess Ended!\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);
}
void displaySummary(Library *lib) // Ly Sievminh
{
}
