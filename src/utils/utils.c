
#include <stdio.h>
#include <ctype.h>

#include "../utils/utils.h"

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
void toLowerString(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}
