#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#include "utils.h"

void getCurrentDate(char *date)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    strftime(date, 11, "%Y-%m-%d", tm);
}

void trim(char *s)
{
    int i = 0, j = 0;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        i++;
    while (((s[j++]) = (s[i++])))
        ;
}
bool getInput(char *prompt, char *buffer, int size)
{
    while (1)
    {
        printf("%s", prompt);

        if (fgets(buffer, size, stdin) == NULL)
        {
            return false;
        }
        if (strchr(buffer, '\n') == NULL)
        {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            printf("Input is too long. Maximum %d characters allowed.\n",
                   size - 1);
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        trim(buffer);

        if (strcmp(buffer, "cancel") == 0)
        {
            return false;
        }

        return true;
    }
}

bool getRequiredInput(char *prompt,
                      char *buffer,
                      int size,
                      char *field_name)
{
    while (1)
    {
        if (!getInput(prompt, buffer, size))
        {
            return false;
        }

        trim(buffer);

        if (strlen(buffer) == 0)
        {
            printf("%s cannot be empty.\n", field_name);
            continue;
        }

        return true;
    }
}

int getIntInput(const char *prompt)
{
    int value;
    int result;
    int ch;

    while (1)
    {
        printf("%s", prompt);

        result = scanf("%d", &value);

        if (result == 1)
        {
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            return value;
        }

        if (result == EOF)
        {
            printf("\nProgram terminated. EXIT(0)\n");
            exit(0);
        }

        printf("Invalid input! Please enter a number.\n");

        while ((ch = getchar()) != '\n' && ch != EOF)
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
