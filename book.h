#ifndef BOOK_H
#define BOOK_H

#include "data.h"

Book inputBook(Library *lib);
void bookMenu(Library *lib);
void addBook(Library *lib);
void searchBook(Library *lib);
void viewBooks(Library *lib, int index);
void updateBook(Library *lib);
void removeBook(Library *lib);
void displayBookSummary(Library *lib); // Ly Sievminh

#endif