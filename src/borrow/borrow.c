#include <stdio.h>
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
    record.returned = false;

    lib->records[lib->record_count++] = record;

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
    printf("\nRecord ID: %d\nMember Name: %s\nBook Title: %s\nStatus: %s\n", lib->records[rec_id].borrow_id, lib->members[rec_id].name, lib->books[rec_id].title, lib->records[rec_id].returned == 1 ? "Returned" : "Borrowed");
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