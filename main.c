#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "data.h"
#include "library.h"

Library lib = {0};

int main()
{
    initLibrary(&lib);
    mainMenu(&lib);

    return 0;
}