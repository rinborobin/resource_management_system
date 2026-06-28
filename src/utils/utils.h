#ifndef UTILS_H
#define UTILS_H

void getCurrentDate(char *date);
void trim(char *str);
bool getInput(char *prompt, char *buffer, int size);
bool getRequiredInput(char *prompt,
                      char *buffer,
                      int size,
                      char *field_name);
int getIntInput(const char *prompt);
void printSuccessful(char *str);
void printItemNotFound(char *str);
void toLowerString(char str[]);

#endif