#include "book.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// typedef struct
// {
//     int book_id;
//     char title[100];
//     char author[100];
//     int quantity;
//     int available;
// } Book;

// typedef struct
// {
//     int member_id;
//     char name[100];
// } Member;

// typedef struct
// {
//     int borrow_id;
//     int book_id;
//     int member_id;
//     int returned;
// } BorrowRecord;

// typedef struct
// {
//     Book *books;
//     int book_capacity;
//     int book_count;
//     int next_book_id;

//     Member *members;
//     int member_capacity;
//     int member_count;
//     int next_member_id;

//     BorrowRecord *records;
//     int record_capacity;
//     int record_count;
//     int next_record_id;
// } Library;

Book inputBook(Library *lib, bool is_update)
{

    getchar();
    Book book;
    char title[100],
        author[100];
    int book_id,
        quantity;

    printf("Enter the title of the book: ");
    fgets(title, sizeof(title), stdin);
    printf("Enter the author name: ");
    fgets(author, sizeof(author), stdin);

    // book.book_id = lib->next_book_id;
    // lib->next_book_id++;

    if (!is_update)
    {
        printf("Enter the quantity of book: ");
        scanf(" %d", &quantity);
        getchar();
        book.quantity = quantity;
    }

    strcpy(book.title, title);
    strcpy(book.author, author);

    return book;
}

void addBook(Library *lib)
{
    if (lib->book_count == lib->book_capacity)
    {
        int new_capacity = lib->book_capacity * 2;

        Book *temp = realloc(
            lib->books,
            new_capacity * sizeof(Book));

        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        lib->books = temp;
        lib->book_capacity = new_capacity;
    }

    Book book = inputBook(lib, false);

    book.book_id = lib->next_book_id;
    lib->next_book_id++;

    lib->books[lib->book_count] = book;
    lib->book_count++;

    printf("Book added successfully!\n");
}

void viewBooks(Library *lib, int index)
{
    printf("\nBook ID: %d\nBook Name: %sAuthor Name: %s\nQuantity: %d\n", lib->books[index].book_id, lib->books[index].title, lib->books[index].author, lib->books[index].quantity);
}
void viewAllBooks(Library *lib)
{
    for (int i = 0; i < lib->book_count; i++)
    {
        viewBooks(lib, i);
    }
}
int searchBook(Library *lib, int book_id) // Ly Sievminh
{
    for (int i = 0; i < lib->book_count; i++)
    {
        if (lib->books[i].book_id == book_id)
        {
            return i;
        }
    }
    printf("Book not found.\n");
    return -1;
}

void updateBook(Library *lib, int book_id)
{
    int index = searchBook(lib, book_id);

    Book book = inputBook(lib, true);

    book.book_id = lib->books[index].book_id;
    book.quantity = lib->books[index].quantity;
    lib->books[index] = book;

    printf("Book updated successfully!\n");
}

void removeBook(Library *lib, int book_id)
{
    int index = searchBook(lib, book_id);

    for (int i = index; i < lib->book_count; i++)
    {
        lib->books[i] = lib->books[i + 1];
    }
    lib->book_count--;
}

void displayBookSummary(Library *lib)
{
    int totalTitles = lib->book_count;
    int totalCopies = 0;
    int totalAvailable = 0;
    for (int i = 0; i < lib->book_count; i++)
    {
        totalCopies += lib->books[i].quantity;
        totalAvailable += lib->books[i].available;
    }
    int totalBorrowed = totalCopies - totalAvailable;

    printf("\n======================================================================\n");
    printf("                          LIBRARY SUMMARY REPORT\n");
    printf("======================================================================\n");
    printf("Total book titles: %d\n", totalTitles);
    printf("total book copies: %d\n", totalCopies);
    printf("total book available: %d\n", totalAvailable);
    printf("total book borrowed: %d\n", totalBorrowed);

}; // Ly Sievminh
void bookMenu(Library *lib)
{
    int choice;
    int book_id;
    do
    {
        printf("\n=================================\n");
        printf("       BOOK MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Remove Book\n");
        printf("0. Back\n");
        printf("=================================\n");
        printf("Enter choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            addBook(lib);
            break;

        case 2:
            viewAllBooks(lib);
            break;

        case 3:
            printf("Enter Book ID: ");
            scanf(" %d", &book_id);
            searchBook(lib, book_id);
            break;

        case 4:
            printf("Enter Book ID: ");
            scanf(" %d", &book_id);
            updateBook(lib, book_id);
            break;

        case 5:
            printf("Enter Book ID: ");
            scanf(" %d", &book_id);
            removeBook(lib, book_id);
            break;

        case 0:
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);
}
