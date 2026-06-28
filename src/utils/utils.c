#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

void trim(char *s)
{
    int i = 0, j = 0;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        i++;
    while (((s[j++]) = (s[i++])))
        ;
}

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
void printSuccessful(char *str)
{
    char msg[256];
    sprintf(msg, "%s SUCCESFULLY", str);

    int len = strlen(msg) + 13;

    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");

    printf("%*s%s\n", 5, "", msg);

    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");
}
void printItemNotFound(char *str)
{
    char msg[256];
    sprintf(msg, "%s NOT FOUND", str);

    int len = strlen(msg) + 13;

    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");

    printf("%*s%s\n", 5, "", msg);

    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");
}
void toLowerString(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }
}
