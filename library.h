#ifndef LIBRARY_H
#define LIBRARY_H

#include "data.h"

void initLibrary(Library *lib);
void freeLibrary(Library *lib);
void mainMenu(Library *lib);
void displaySummary(Library *lib);

#endif // !LIBRARY_H