#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../utils/utils.h"
#include "../library/library.h"
#include "../book/book.h"
#include "../member/member.h"
#include "../borrow/borrow.h"

#define MAX_BOOKS 100000
#define MAX_MEMBERS 10000
#define MAX_RECORDS 100000

void initLibrary(Library *lib)
{
    lib->book_capacity = 5;
    lib->books = malloc(lib->book_capacity * sizeof(Book));
    if (lib->books == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    lib->book_count = 0;
    lib->next_book_id = 1001;

    lib->member_capacity = 5;
    lib->members = malloc(lib->member_capacity * sizeof(Member));
    if (lib->members == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    lib->member_count = 0;
    lib->next_member_id = 2001;

    lib->record_capacity = 5;
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

    return true;
}

bool loadLibrary(Library *lib)
{
    FILE *file = fopen("./data/data.bin", "rb");
    if (file == NULL)
    {
        return false;
    }

    int book_count;
    int member_count;
    int record_count;

    if (fread(&book_count, sizeof(int), 1, file) != 1)
    {
        fclose(file);
        return false;
    }

    if (book_count < 0 || book_count > MAX_BOOKS)
    {
        fclose(file);
        return false;
    }

    if (book_count > lib->book_capacity)
    {
        Book *temp = realloc(
            lib->books,
            book_count * sizeof(Book));

        if (temp == NULL)
        {
            fclose(file);
            return false;
        }

        lib->books = temp;
        lib->book_capacity = book_count;
    }

    lib->book_count = book_count;

    if (fread(&lib->next_book_id, sizeof(int), 1, file) != 1)
    {
        fclose(file);
        return false;
    }

    if (fread(lib->books, sizeof(Book), book_count, file) != (size_t)book_count)
    {
        fclose(file);
        return false;
    }

    if (fread(&member_count, sizeof(int), 1, file) != 1)
    {
        fclose(file);
        return false;
    }

    if (member_count < 0 || member_count > MAX_MEMBERS)
    {
        fclose(file);
        return false;
    }

    if (member_count > lib->member_capacity)
    {
        Member *temp = realloc(
            lib->members,
            member_count * sizeof(Member));

        if (temp == NULL)
        {
            fclose(file);
            return false;
        }

        lib->members = temp;
        lib->member_capacity = member_count;
    }

    lib->member_count = member_count;

    if (fread(&lib->next_member_id, sizeof(int), 1, file) != 1)
    {
        fclose(file);
        return false;
    }

    if (fread(lib->members, sizeof(Member), member_count, file) != (size_t)member_count)
    {
        fclose(file);
        return false;
    }

    if (fread(&record_count, sizeof(int), 1, file) != 1)
    {
        fclose(file);
        return false;
    }

    if (record_count < 0 || record_count > MAX_RECORDS)
    {
        fclose(file);
        return false;
    }

    if (record_count > lib->record_capacity)
    {
        BorrowRecord *temp = realloc(
            lib->records,
            record_count * sizeof(BorrowRecord));

        if (temp == NULL)
        {
            fclose(file);
            return false;
        }

        lib->records = temp;
        lib->record_capacity = record_count;
    }

    lib->record_count = record_count;

    if (fread(&lib->next_record_id, sizeof(int), 1, file) != 1)
    {
        fclose(file);
        return false;
    }

    if (fread(lib->records,
              sizeof(BorrowRecord),
              record_count,
              file) != (size_t)record_count)
    {
        fclose(file);
        return false;
    }

    fclose(file);

    return true;
};

void freeLibrary(Library *lib)
{
    free(lib->books);
    free(lib->members);
    free(lib->records);
};

void summaryReport(Library *lib) // Ly Sievminh
{
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

    printf(
        "\n"
        "╔══════════════════════════════════════╗\n"
        "║            SUMMARY REPORT            ║\n"
        "╚══════════════════════════════════════╝\n"

        "\n"
        "┌──────────────────────────────────────┐\n"
        "│ BOOKS                                │\n"
        "└──────────────────────────────────────┘\n"
        "┌──────────────────────────────────────┐\n"

        "  Total Book Titles    : %d\n"
        "  Total Book Copies    : %d\n"
        "  Total Available      : %d\n"
        "  Total Borrowed       : %d\n"
        "└──────────────────────────────────────┘\n"

        "\n"
        "┌──────────────────────────────────────┐\n"
        "│ MEMBERS                              │\n"
        "└──────────────────────────────────────┘\n"
        "┌──────────────────────────────────────┐\n"

        "  Total Members        : %d\n"
        "  Total Borrow Records : %d\n"
        "└──────────────────────────────────────┘\n"

        "\n"
        "┌──────────────────────────────────────┐\n"
        "│ SYSTEM                               │\n"
        "└──────────────────────────────────────┘\n"
        "┌──────────────────────────────────────┐\n"

        "  Book Capacity        : %d\n"
        "  Books Stored         : %d\n"
        "└──────────────────────────────────────┘\n",

        total_titles,
        total_copies,
        total_available,
        total_borrowed,
        total_members,
        total_records,
        book_capacity,
        books_stored);
}

void mainMenu(Library *lib)
{
    int choice;

    do
    {
        printf("\n");
        puts("        _.--._  _.--._");
        puts("  ,-=.-\":;:;:;\\\\':;:;:;\"-._");
        puts("  \\\\\\:;:;:;:;:;\\\\:;:;:;:;:;\\\\");
        puts("   \\\\\\:;:;:;:;:;\\\\:;:;:;:;:;\\\\");
        puts("    \\\\\\:;:;:;:;:;\\\\:;:;:;:;:;\\\\");
        puts("     \\\\\\:;:;:;:;:;\\\\:;::;:;:;:\\\\");
        puts("      \\\\\\;:;::;:;:;\\\\:;:;:;::;:\\\\");
        puts("       \\\\\\;;:;:_:--:\\\\:_:--:_;:;\\\\    ");
        puts("        \\\\\\_.-\"      :       \"-._\\\\");
        puts("         \\`_..--\"\"--.;.--\"\"--.._-=>");
        puts("          \"");

        printf("╔══════════════════════════════════════╗\n"
               "║      LIBRARY MANAGEMENT SYSTEM       ║\n"
               "╠══════════════════════════════════════╣\n"
               "║ 1. Book Management                   ║\n"
               "║ 2. Member Management                 ║\n"
               "║ 3. Borrow Management                 ║\n"
               "║ 4. Summary Report                    ║\n"
               "║ 0. Exit                              ║\n"
               "╚══════════════════════════════════════╝\n");
        choice = getIntInput("\nEnter choice: ");

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
            summaryReport(lib); // Ly Sievminh
            break;

        case 0:
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }

    } while (choice != 0);
}
