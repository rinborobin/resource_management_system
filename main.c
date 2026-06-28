#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "./data/data.h"
#include "./src/book/book.h"
#include "./src/utils/utils.h"
#include "./src/library/library.h"

#ifdef _WIN32
#include <windows.h>
#endif

Library lib;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    initLibrary(&lib);
    // initMockData(&lib);
    loadLibrary(&lib);

    mainMenu(&lib);

    printf("\n");
    printf("┌────────── Confirm & Exit ────────────┐\n");
    printf("├──────────────────────────────────────┤\n");
    printf("│ 1. Save & Exit                       │\n");
    printf("│ 0. Exit Without Saving               │\n");
    printf("└──────────────────────────────────────┘\n");

    int choice = getIntInput("Enter your choice: ");

    if (choice == 1)
    {

        if (saveLibrary(&lib))
        {
            printf("┌──────────────────────────────────────┐\n");
            printf("│          Successfully Saved          │\n");
            printf("└──────────────────────────────────────┘\n");
        }
        else
        {
            printf("┌──────────────────────────────────────┐\n");
            printf("│          Error Saving File!          │\n");
            printf("└──────────────────────────────────────┘\n");
        }
    }
    else if (choice == 0)
    {
        printf("┌──────────────────────────────────────┐\n");
        printf("│         Exited Without Saving        │\n");
        printf("└──────────────────────────────────────┘\n");
    }

    freeLibrary(&lib);

    return 0;
}