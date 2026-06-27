#ifndef BORROW_H
#define BORROW_H

#include "../../data/data.h"

void borrowMenu(Library *lib);
void borrowBook(Library *lib, int member_id, int book_id);
void returnBook(Library *lib, int book_id, int member_id);
void viewRecords(Library *lib);

#endif // !BORROW_H
