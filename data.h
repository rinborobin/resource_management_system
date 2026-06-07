#ifndef DATA_H
#define DATA_H

typedef struct
{
    int bookID;
    char title[100];
    char author[100];
    int quantity;
    int available;
} Book;

typedef struct
{
    int memberID;
    char name[100];
} Member;

typedef struct
{
    int borrowID;
    int bookID;
    int memberID;
    int returned;
} BorrowRecord;

typedef struct
{
    Book books[100];
    int bookCount;

    Member members[100];
    int memberCount;

    BorrowRecord records[200];
    int recordCount;
} Library;

#endif