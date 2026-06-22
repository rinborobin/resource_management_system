#include "borrow.h"
#include "book.h"
#include "library.h"
#include "utils.h"
#include "member.h"
#include <stdio.h>

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

    BorrowRecord record;

    record.borrow_id = lib->next_record_id;
    lib->next_record_id++;

    lib->records[lib->record_count] = record;
    lib->record_count++;

    lib->books[book_index].available--;

    printf("Book: %d\nBorrowed By: %d", member_id, book_id);
}
void returnBook(Library *lib, int book_id, int member_id)
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
    lib->record_count--;
    lib->books[book_index].available++;
}

void printRecord(Library *lib, int rec_id)
{
    printf("\nRecord ID: %d\nMember Name: %s\nBook Title: %s\nStatus: %s\n", rec_id, lib->members[rec_id].name, lib->books[rec_id].title, lib->records[rec_id].returned == 1 ? "Returned" : "Borrowed");
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
        printf("\n=================================\n");
        printf("       BORROW MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Borrow Book\n");
        printf("2. Return Book\n");
        printf("3. View Records\n");
        printf("0. Back\n");
        printf("=================================\n");
        choice = getIntInput("Enter Choice: ");
        switch (choice)
        {
        case 1:
            book_id = getIntInput("Enter Book ID: ");
            member_id = getIntInput("Enter Member ID: ");
            borrowBook(lib, member_id, book_id);
            break;
        case 2:
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