# Library Management System

A brief description of what this project does and who it's for

## Compiling

To compile the program, run the following command inside the main directory

```bash
  gcc -Wall -Wextra main.c src/*/*.c -o <program_name.exe>
```

### Windows

```bash
gcc -Wall -Wextra main.c (Get-ChildItem src -Recurse *.c).FullName -o lib.exe
```

## Running the program

After compiling

```bash
  ./<program_name>
```

## with Makefile

Compiling:

```bash
  make all
```

Run:

```bash
  make run
```
