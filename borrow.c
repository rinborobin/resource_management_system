#include "borrow.h"
#include "book.h"
#include "member.h"
#include <stdio.h>

BorrowRecord inputBorrowRecord(Library *lib)
{
    getchar();
    BorrowRecord b_record;
    int book_id, member_id;
    int returned = 0;

    printf("Enter the book ID: ");
    scanf(" %d", &book_id);
    printf("Enter the member ID: ");
    scanf(" %d", &member_id);

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

void viewRecords(Library *lib) // Ly Sievminh
{
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
        printf("Enter choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the book ID: ");
            scanf(" %d", &book_id);
            printf("Enter the member ID: ");
            scanf(" %d", &member_id);
            borrowBook(lib, member_id, book_id);
            break;
        case 2:
            printf("Enter the book ID: ");
            scanf(" %d", &book_id);
            printf("Enter the member ID: ");
            scanf(" %d", &member_id);
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