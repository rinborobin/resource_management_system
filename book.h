#ifndef BOOK_H
#define BOOK_H

#include "data.h"

void bookMenu(Library *lib);
void addBook(Library *lib);
void searchBook(Library *lib);
void viewBooks(Library *lib);
void updateBook(Library *lib);
void removeBook(Library *lib);

#endif