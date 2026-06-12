#include "book.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

Book inputBook(bool is_update)
{

    getchar();
    Book book;
    char title[100],
        author[100];
    int quantity;

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

int searchBook(Library *lib, int book_id)
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

int compareChar(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (tolower((unsigned char)*s1) !=
            tolower((unsigned char)*s2))
        {
            return 0;
        }

        s1++;
        s2++;
    }

    return *s1 == *s2;
}

int checkDuplicateBook(Library *lib, char title[], char author[])
{
    for (int i = 0; i < lib->book_count; i++)
    {
        if (compareChar(lib->books[i].title, title) &&
            compareChar(lib->books[i].author, author))
        {
            return i;
        }
    }

    return -1;
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

    Book book = inputBook(false);

    int idx = checkDuplicateBook(
        lib,
        book.title,
        book.author);

    if (idx != -1)
    {
        lib->books[idx].quantity += book.quantity;
        lib->books[idx].available += book.quantity;

        printf("Book already exists. Quantity updated.\n");
        return;
    }

    book.available = book.quantity;

    book.book_id = lib->next_book_id;
    lib->next_book_id++;

    lib->books[lib->book_count] = book;
    lib->book_count++;

    printf("Available: %d\n", book.available);
    printf("ID: %d\n", book.book_id);

    printf("Book added successfully!\n");
}

void viewBooks(Library *lib, int index)
{
    printf("\nBook ID: %d\nBook Name: %s\nAuthor Name: %s\nQuantity: %d\nAvailable: %d\n", lib->books[index].book_id, lib->books[index].title, lib->books[index].author, lib->books[index].quantity, lib->books[index].available);
}
void viewAllBooks(Library *lib)
{
    for (int i = 0; i < lib->book_count; i++)
    {
        viewBooks(lib, i);
    }
}

void updateBook(Library *lib, int book_id)
{
    int index = searchBook(lib, book_id);

    Book book = inputBook(true);

    book.book_id = lib->books[index].book_id;
    book.quantity = lib->books[index].quantity;
    lib->books[index] = book;

    printf("Book updated successfully!\n");
}

void removeBook(Library *lib, int book_id)
{
    int index = searchBook(lib, book_id);

    for (int i = index; i < lib->book_count - 1; i++)
    {
        lib->books[i] = lib->books[i + 1];
    }
    lib->book_count--;
}

void displayBookSummary(Library *lib)
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

    printf("\n======================================================================\n");
    printf("                          BOOK SUMMARY REPORT\n");
    printf("======================================================================\n");
    printf("Total book titles: %d\n", total_titles);
    printf("Total book copies: %d\n", total_copies);
    printf("Total book available: %d\n", total_available);
    printf("Total book borrowed: %d\n", total_borrowed);

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
        printf("6. Book Summary\n");
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

        case 6:
            displayBookSummary(lib);
            break;

        case 0:
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);
}
