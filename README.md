## 📚 Library Management System

A console-based Library Management System developed in C as a final project for the C Programming Fundamentals course. The application demonstrates the use of dynamic memory allocation, structures, modular programming, file handling, and basic data management.

The system allows librarians to manage books, members, and borrowing records through an interactive terminal interface. All data is stored in binary files, enabling persistent storage between program executions.

## Compiling

To compile the program, run the following command inside the main directory

```bash
  gcc -Wall -Wextra main.c src/*/*.c -o library.exe
```

### PowerShell

```bash
  $files = Get-ChildItem src -Recurse -Filter *.c | Select-Object -ExpandProperty FullName
  gcc -Wall -Wextra main.c $files -o library.exe
```

## Running the program

After compiling

```bash
  ./library.exe
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

### Features

- 📖 Book Management
  - Add, view, search, update, and remove books
  - Automatic duplicate detection
  - Sort books by title, author, or category
  - Book summary statistics

- 👤 Member Management
  - Add, view, search, update, and remove members

- 🔄 Borrow Management
  - Borrow and return books
  - Track book availability
  - Borrow history with borrow and return dates
  - View all borrowing records

- 💾 Data Persistence
  - Save and load data using binary files
  - Dynamic memory allocation with automatic capacity expansion using `realloc()`

### Technologies

- C Programming Language
- Dynamic Memory Allocation (`malloc`, `realloc`, `free`)
- Structures (`struct`)
- Modular Programming
- File Handling (`fread`, `fwrite`)
- ANSI Terminal Interface
