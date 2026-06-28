#ifndef LIBRARY_H
#define LIBRARY_H

#include "../../data/data.h"
#include <stdbool.h>

void printItemNotFound(char *str);
void initLibrary(Library *lib);
bool loadLibrary(Library *lib);
bool saveLibrary(Library *lib);
void freeLibrary(Library *lib);
void mainMenu(Library *lib);
void displaySummary(Library *lib);

#endif // !LIBRARY_H