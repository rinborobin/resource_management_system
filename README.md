# Library Management System

A brief description of what this project does and who it's for

## Compiling

To compile the program, run the following command inside the main directory

```bash
  gcc -Wall -Wextra main.c src/*/*.c -o <program_name>
```
### Windows 

```bash
  $files = Get-ChildItem src -Recurse -Filter *.c | Select-Object -ExpandProperty FullName
gcc -Wall -Wextra main.c $files -o lib.exe
```
## Running the program

After compiling

```bash
  ./<program_name>
```

## with Makefile

Installing:

```bash
mingw32-make
```
Compiling:

```bash
  make all
```

Run:

```bash
  make run
```
