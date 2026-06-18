
#include <stdio.h>
#include "utils.h"

int getIntInput(const char *prompt)
{
    int value;

    while (1)
    {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1)
        {
            while (getchar() != '\n')
                ;
            return value;
        }

        printf("Invalid input! Please enter a number.\n");

        while (getchar() != '\n')
            ;
    }
}
void printItemNotFound(char *str)
{
    printf("%s Not Found.\n", str);
}
