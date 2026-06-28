#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "../book/book.h"
#include "../library/library.h"
#include "../utils/utils.h"

typedef enum
{
    SORT_BY_TITLE,
    SORT_BY_CATEGORY
} SortType;

Book inputBook(bool is_update)
{
    Book book;
    char title[100],
        author[100],
        category[50];
    int quantity;

    printf("\n");
    printf(
        "\n"
        "╔══════════════════════════════════════╗\n"
        "║               ADD BOOK               ║\n"
        "╚══════════════════════════════════════╝\n");
    printf("\n");

    printf("\n(Type 'cancel' at any time to return)\n");

    if (!getRequiredInput(
            is_update ? "New Title    : " : "Title        : ",
            title,
            sizeof(title),
            "Title"))
    {
        book.book_id = -1;
        return book;
    }

    if (!getRequiredInput(
            is_update ? "New Author   : " : "Author       : ",
            author,
            sizeof(author),
            "Author"))
    {
        book.book_id = -1;
        return book;
    }

    if (!getRequiredInput(
            is_update ? "New Category : " : "Category     : ",
            category,
            sizeof(category),
            "Category"))
    {
        book.book_id = -1;
        return book;
    }

    while (1)
    {
        if (!is_update)
        {
            quantity = getIntInput("Quantity  : ");

            if (quantity <= 0)
            {
                printf("Quantity must be greater than 0.\n");
                continue;
            }

            book.quantity = quantity;
            break;
        }
    }

    strcpy(book.title, title);
    strcpy(book.author, author);
    strcpy(book.category, category);

    return book;
}

void viewBooks(Library *lib, int index)
{
    Book *book = &lib->books[index];

    book->title[strcspn(book->title, "\n")] = '\0';
    book->author[strcspn(book->author, "\n")] = '\0';
    book->category[strcspn(book->category, "\n")] = '\0';

    printf("┌──────────────────────────────────────────────────┐\n");

    printf("  Book ID   : %d\n", book->book_id);
    printf("  Title     : %s\n", book->title);
    printf("  Author    : %s\n", book->author);
    printf("  Category  : %s\n", book->category);
    printf("  Quantity  : %d\n", book->quantity);
    printf("  Available : %d\n", book->available);

    printf("└──────────────────────────────────────────────────┘\n");
}
void viewAllBooks(Library *lib)
{
    if (lib->book_count == 0)
    {
        printItemNotFound("Book");
        return;
    }
    for (int i = 0; i < lib->book_count; i++)
    {
        viewBooks(lib, i);
    }
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

int searchBookByID(Library *lib, int book_id)
{
    for (int i = 0; i < lib->book_count; i++)
    {
        if (lib->books[i].book_id == book_id)
        {
            return i;
        }
    }

    return -1;
}

void searchByTitle(Library *lib, char *title)
{
    int is_found = 0;
    char book_title[100];
    char search_title[100];

    strcpy(search_title, title);

    for (int i = 0; i < lib->book_count; i++)
    {
        strcpy(book_title, lib->books[i].title);

        toLowerString(book_title);
        toLowerString(search_title);

        if (strstr(book_title, search_title) != NULL)
        {
            viewBooks(lib, i);
            is_found = 1;
        }
    }

    if (!is_found)
        printItemNotFound("BOOK");
}

void searchByCategory(Library *lib, char *category)
{
    int is_found = 0;
    char book_category[50];
    char search_category[50];

    strcpy(search_category, category);

    for (int i = 0; i < lib->book_count; i++)
    {
        strcpy(book_category, lib->books[i].category);

        toLowerString(book_category);
        toLowerString(search_category);

        if (strstr(book_category, search_category) != NULL)
        {
            viewBooks(lib, i);
            is_found = 1;
        }
    }

    if (!is_found)
        printItemNotFound("BOOK");
}
void viewBooksSorted(Library *lib, SortType sortType)
{
    if (lib->book_count == 0)
    {
        printItemNotFound("Book");
        return;
    }

    int *indices = malloc(lib->book_count * sizeof(int));

    if (indices == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < lib->book_count; i++)
    {
        indices[i] = i;
    }

    for (int i = 0; i < lib->book_count - 1; i++)
    {
        for (int j = 0; j < lib->book_count - i - 1; j++)
        {
            char *left;
            char *right;

            if (sortType == SORT_BY_TITLE)
            {
                left = lib->books[indices[j]].title;
                right = lib->books[indices[j + 1]].title;
            }
            else
            {
                left = lib->books[indices[j]].author;
                right = lib->books[indices[j + 1]].author;
            }

            if (strcmp(left, right) > 0)
            {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < lib->book_count; i++)
    {
        viewBooks(lib, indices[i]);
    }

    free(indices);
}
void searchByAuthor(Library *lib, char *author)
{
    int is_found = 0;
    char book_author[100];
    char search_author[100];

    strcpy(search_author, author);

    for (int i = 0; i < lib->book_count; i++)
    {
        strcpy(book_author, lib->books[i].author);

        toLowerString(book_author);
        toLowerString(search_author);

        if (strstr(book_author, search_author) != NULL)
        {
            viewBooks(lib, i);
            is_found = 1;
        }
    }

    if (!is_found)
        printItemNotFound("BOOK");
}
void viewBooksSortedByTitle(Library *lib)
{

    viewBooksSorted(lib, SORT_BY_TITLE);
}

void viewBooksSortedByAuthor(Library *lib)
{

    viewBooksSorted(lib, SORT_BY_CATEGORY);
}

int displayUniqueCat(Library *lib)
{
    if (lib->book_count == 0)
    {
        return -1;
    }
    int cat_count = 0;
    for (int i = 0; i < lib->book_count; i++)
    {
        int found = 0;

        for (int j = 0; j < i; j++)
        {
            char cat1[100];
            char cat2[100];

            strcpy(cat1, lib->books[i].category);
            strcpy(cat2, lib->books[j].category);

            toLowerString(cat1);
            toLowerString(cat2);

            if (strcmp(cat1, cat2) == 0)
            {
                found = 1;
                cat_count++;
                break;
            }
        }

        if (!found)
        {
            printf("  %s\n", lib->books[i].category);
        }
    }

    return cat_count;
}

void displaySearchResult(Library *lib, int idx)
{
    if (idx != -1)
    {
        viewBooks(lib, idx);
    }
    else
    {
        printItemNotFound("BOOK");
    }
}

int checkDuplicateBook(Library *lib, char *title, char *author)
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

    if (book.book_id == -1)
        return;

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

    printf(
        "\n"
        "╔══════════════════════════════════════╗\n"
        "║        BOOK ADDED SUCCESSFULLY       ║\n"
        "╚══════════════════════════════════════╝\n"
        " ID       : %d\n"
        " Title    : %s\n"
        " Author   : %s\n"
        " Category : %s\n"
        " Quantity : %d\n",
        book.book_id,
        book.title,
        book.author,
        book.category,
        book.quantity);
}

void updateBook(Library *lib, int book_id)
{
    int index = searchBookByID(lib, book_id);
    if (index == -1)
    {
        printItemNotFound("BOOK");
        return;
    }

    Book book = inputBook(true);

    if (book.book_id == -1)
        return;

    book.book_id = lib->books[index].book_id;
    book.quantity = lib->books[index].quantity;
    book.available = lib->books[index].available;
    lib->books[index] = book;

    printSuccessful("BOOK UPDATED");
}

void removeBook(Library *lib, int book_id)
{
    int index = searchBookByID(lib, book_id);

    if (index == -1)
    {
        printItemNotFound("BOOK");
        return;
    }

    for (int i = index; i < lib->book_count - 1; i++)
    {
        lib->books[i] = lib->books[i + 1];
    }
    lib->book_count--;
    printSuccessful("BOOK REMOVED");
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

    printf(
        "\n"
        "╔══════════════════════════════════════╗\n"
        "║         BOOK SUMMARY REPORT          ║\n"
        "╠══════════════════════════════════════╣\n"
        "║ %-22s : %-11d ║\n"
        "║ %-22s : %-11d ║\n"
        "║ %-22s : %-11d ║\n"
        "║ %-22s : %-11d ║\n"
        "╚══════════════════════════════════════╝\n",
        "Total Book Titles", total_titles,
        "Total Book Copies", total_copies,
        "Total Available", total_available,
        "Total Borrowed", total_borrowed);

}; // Ly Sievminh
void bookMenu(Library *lib)
{
    int choice;
    int book_id;

    do
    {
        printf("\n");

        printf(
            "╔══════════════════════════════════════╗\n"
            "║            BOOK MANAGEMENT           ║\n"
            "╠══════════════════════════════════════╣\n"
            "║ 1. Add Book                          ║\n"
            "║ 2. View All Books                    ║\n"
            "║ 3. Search Book                       ║\n"
            "║ 4. Update Book                       ║\n"
            "║ 5. Remove Book                       ║\n"
            "║ 6. Book Summary                      ║\n"
            "║ 0. Back                              ║\n"
            "╚══════════════════════════════════════╝\n");
        printf("\n");
        choice = getIntInput("Enter choice: ");

        switch (choice)
        {
        case 1:
            addBook(lib);
            break;

        case 2:
            int view_book_choice = 0;
            viewAllBooks(lib);
            do
            {
                printf(
                    "╔══════════════════════════════════════╗\n"
                    "║               Sort Book              ║\n"
                    "╠══════════════════════════════════════╣\n"
                    "║ 1. Sort by Book Title                ║\n"
                    "║ 2. Sort by Book Author               ║\n"
                    "║ 0. Exit                              ║\n"
                    "╚══════════════════════════════════════╝\n");

                view_book_choice = getIntInput("Enter choice: ");

                switch (view_book_choice)
                {
                case 1:
                    printf("┌──────────────────────────────────────────────────┐\n");
                    printf("│                  Sorted by Title                 │\n");
                    printf("└──────────────────────────────────────────────────┘\n");
                    viewBooksSortedByTitle(lib);
                    break;
                case 2:
                    printf("┌──────────────────────────────────────────────────┐\n");
                    printf("│                  Sorted by Author                │\n");
                    printf("└──────────────────────────────────────────────────┘\n");
                    viewBooksSortedByAuthor(lib);
                case 0:
                    break;
                default:
                    printf("Invalid choice!\n");
                }
            } while (view_book_choice != 0);

            break;

        case 3:

            int search_menu_choice;

            char title[100];
            char author[100];
            char category[50];

            do
            {
                printf(
                    "╔══════════════════════════════════════╗\n"
                    "║           SEARCH BOOK MENU           ║\n"
                    "╠══════════════════════════════════════╣\n"
                    "║ 1. Search by ID                      ║\n"
                    "║ 2. Search by Title                   ║\n"
                    "║ 3. Search by Author                  ║\n"
                    "║ 4. Search by Category                ║\n"
                    "║ 0. Back                              ║\n"
                    "╚══════════════════════════════════════╝\n");
                printf("\n");

                search_menu_choice = getIntInput("Enter choice: ");

                switch (search_menu_choice)
                {
                case 1:
                    book_id = getIntInput("┌───────────────────────────────┐\n"
                                          "│         Search by ID          │\n"
                                          "└───────────────────────────────┘\n"
                                          " ID: ");
                    int id_idx = searchBookByID(lib, book_id);
                    if (id_idx == -1)
                    {
                        printItemNotFound("BOOK");
                        break;
                    }
                    displaySearchResult(lib, id_idx);
                    break;
                case 2:
                    while (1)
                    {
                        printf("┌───────────────────────────────┐\n"
                               "│        Search by Title        │\n"
                               "└───────────────────────────────┘\n"
                               "Search Title: ");
                        fgets(title, sizeof(title), stdin);
                        title[strcspn(title, "\n")] = '\0';

                        if (strlen(title) == 0)
                        {
                            printf("Title cannot be empty.\n");
                            continue;
                        }

                        break;
                    }

                    searchByTitle(lib, title);
                    break;
                case 3:
                    while (1)
                    {
                        printf("┌───────────────────────────────┐\n"
                               "│       Search by Author        │\n"
                               "└───────────────────────────────┘\n"
                               " Author: ");
                        fgets(author, sizeof(author), stdin);
                        author[strcspn(author, "\n")] = '\0';

                        if (strlen(author) == 0)
                        {
                            printf("Author cannot be empty.\n");
                            continue;
                        }

                        break;
                    }
                    searchByAuthor(lib, author);
                    break;
                case 4:
                    printf(
                        "\n"
                        "┌───────────────────────────────┐\n"
                        "│       Search by Category      │\n"
                        "└───────────────────────────────┘\n");

                    if (displayUniqueCat(lib) == -1)
                    {
                        printItemNotFound("CATEGORY");
                    }
                    else
                    {
                        printf("┌───────────────────────────────┐\n");

                        displayUniqueCat(lib);

                        printf("└───────────────────────────────┘\n");
                        printf("Enter Book Category: ");
                        fgets(category, sizeof(category), stdin);
                        category[strcspn(category, "\n")] = '\0';
                        searchByCategory(lib, category);
                        break;
                    }

                    break;
                case 0:
                    break;
                default:
                    printf("Invalid choice!\n");
                }
            } while (search_menu_choice != 0);

            break;

        case 4:
            book_id = getIntInput("┌───────────────────────────────┐\n"
                                  "│         Enter Book ID         │\n"
                                  "└───────────────────────────────┘\n"
                                  "  ID: ");
            updateBook(lib, book_id);
            break;

        case 5:
            book_id = getIntInput("┌───────────────────────────────┐\n"
                                  "│         Enter Book ID         │\n"
                                  "└───────────────────────────────┘\n"
                                  "  ID: ");
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
