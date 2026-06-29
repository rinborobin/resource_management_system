#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../borrow/borrow.h"
#include "../book/book.h"
#include "../library/library.h"
#include "../utils/utils.h"
#include "../member/member.h"

BorrowRecord inputBorrowRecord()
{
    BorrowRecord b_record;
    int book_id, member_id;

    book_id = getIntInput("Enter Book ID: ");
    member_id = getIntInput("Enter Member ID: ");

    b_record.book_id = book_id;
    b_record.member_id = member_id;

    return b_record;
}

void borrowBook(Library *lib, int member_id, int book_id)
{
    int book_index = searchBookByID(lib, book_id);
    int member_index = searchMember(lib, member_id);

    bool search_validation = book_index != -1 && member_index != -1;

    if (!search_validation)
    {
        printf("Book or member not found.\n");
        return;
    }

    if (lib->books[book_index].available <= 0)
    {
        printf("Book unavailable.\n");
        return;
    }

    if (lib->record_count == lib->record_capacity)
    {
        int new_capacity = lib->record_capacity * 2;

        BorrowRecord *temp = realloc(
            lib->records,
            new_capacity * sizeof(BorrowRecord));

        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        lib->records = temp;
        lib->record_capacity = new_capacity;
    }

    BorrowRecord record = {0};

    record.borrow_id = lib->next_record_id++;
    record.book_id = book_id;
    record.member_id = member_id;

    getCurrentDate(record.borrow_date);

    record.returned = false;

    lib->records[lib->record_count++] = record;

    printf("\nDEBUG AFTER BORROW\n");
    printf("Record Count : %d\n", lib->record_count);
    printf("Borrow ID    : %d\n", lib->records[lib->record_count - 1].borrow_id);
    printf("Book ID      : %d\n", lib->records[lib->record_count - 1].book_id);
    printf("Member ID    : %d\n", lib->records[lib->record_count - 1].member_id);

    lib->books[book_index].available--;

    printf(
        "\n"
        "╔══════════════════════════════════════╗\n"
        "║      BOOK BORROWED SUCCESSFULLY      ║\n"
        "╚══════════════════════════════════════╝\n"
        " Book Title : %s\n"
        " Book ID    : %d\n"
        " Member ID  : %d\n",
        lib->books[book_index].title,
        book_id,
        member_id);
}
void returnBook(Library *lib, int book_id, int member_id)
{
    int book_index = searchBookByID(lib, book_id);
    int member_index = searchMember(lib, member_id);

    if (book_index == -1 || member_index == -1)
    {
        printf("Book or member not found.\n");
        return;
    }

    int record_index = -1;

    for (int i = 0; i < lib->record_count; i++)
    {
        if (lib->records[i].book_id == book_id &&
            lib->records[i].member_id == member_id &&
            !lib->records[i].returned)
        {
            record_index = i;
            break;
        }
    }

    if (record_index == -1)
    {
        printf("No active borrow record found.\n");
        return;
    }
    getCurrentDate(
        lib->records[record_index].return_date);

    lib->records[record_index].returned = true;
    lib->books[book_index].available++;

    printf(
        "\n"
        "╔══════════════════════════════════════╗\n"
        "║      BOOK RETURNED SUCCESSFULLY      ║\n"
        "╚══════════════════════════════════════╝\n"
        " Record ID : %d\n"
        " Book ID   : %d\n"
        " Member ID : %d\n",
        lib->records[record_index].borrow_id,
        book_id,
        member_id);
}

void printRecord(Library *lib, int rec_id)
{
    int book_index = searchBookByID(
        lib,
        lib->records[rec_id].book_id);

    int member_index = searchMember(
        lib,
        lib->records[rec_id].member_id);

    if (book_index == -1 || member_index == -1)
    {
        printf("Invalid borrow record.\n");
        return;
    }

    printf(
        "╔══════════════════════════════════════╗\n"
        "║          BOOK BORROW RECORD          ║\n"
        "╚══════════════════════════════════════╝\n"
        " Record ID        : %d\n"
        " Book Title (ID)  : %s (%d)\n"
        " Member Name (ID) : %s (%d)\n"
        " Status           : %s\n"
        " Borrowed Date    : %s\n"
        " Returned Date    : %s\n",

        lib->records[rec_id].borrow_id,
        lib->books[book_index].title,
        lib->books[book_index].book_id,
        lib->members[member_index].name,
        lib->members[member_index].member_id,
        lib->records[rec_id].returned ? "Returned" : "Borrowed",
        lib->records[rec_id].borrow_date,
        strlen(lib->records[rec_id].return_date) == 0
            ? "N/A"
            : lib->records[rec_id].return_date);
}

void viewRecords(Library *lib)
{
    if (lib->record_count == 0)
    {
        printItemNotFound("Record");
        return;
    }
    for (int i = 0; i < lib->record_count; i++)
    {
        printRecord(lib, i);
    }
}
void borrowMenu(Library *lib) // Ly Sievminh
{
    int choice, member_id, book_id;
    do
    {
        printf("\n");
        printf("╔══════════════════════════════════════╗\n"
               "║          BORROW MANAGEMENT           ║\n"
               "╠══════════════════════════════════════╣\n"
               "║ 1. Borrow Book                       ║\n"
               "║ 2. Return Book                       ║\n"
               "║ 3. View Records                      ║\n"
               "║ 0. Exit                              ║\n"
               "╚══════════════════════════════════════╝\n");
        printf("\n");
        choice = getIntInput("Enter Choice: ");
        switch (choice)
        {
        case 1:
            printf("\n");
            printf(
                "\n"
                "╔══════════════════════════════════════╗\n"
                "║             BORROW BOOK              ║\n"
                "╚══════════════════════════════════════╝\n");
            printf("\n");

            book_id = getIntInput("Book ID: ");
            member_id = getIntInput("Member ID: ");
            borrowBook(lib, member_id, book_id);
            break;
        case 2:
            printf("\n");
            printf(
                "\n"
                "╔══════════════════════════════════════╗\n"
                "║             RETURN BOOK              ║\n"
                "╚══════════════════════════════════════╝\n");
            printf("\n");
            book_id = getIntInput("Enter Book ID: ");
            member_id = getIntInput("Enter Member ID: ");
            returnBook(lib, book_id, member_id);
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