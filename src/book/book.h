#ifndef BOOK_H
#define BOOK_H

#include "../../data/data.h"
#include <stdbool.h>

Book inputBook(bool is_update);
void bookMenu(Library *lib);
int searchBookByID(Library *lib, int book_id);
void viewBooks(Library *lib, int index);
void viewAllBooks(Library *lib);
void displayBookSummary(Library *lib); // Ly Sievminh

#endif