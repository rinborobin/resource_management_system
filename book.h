#ifndef BOOK_H
#define BOOK_H

#include "data.h"
#include <stdbool.h>

Book inputBook(Library *lib, bool is_update);
void bookMenu(Library *lib);
void addBook(Library *lib);
int searchBook(Library *lib, int book_id);
void viewBooks(Library *lib, int index);
void viewAllBooks(Library *lib);
void updateBook(Library *lib, int book_id);
void removeBook(Library *lib, int book_id);
void displayBookSummary(Library *lib); // Ly Sievminh

#endif