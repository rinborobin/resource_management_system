#include <stdbool.h>

#ifndef DATA_H
#define DATA_H

typedef struct
{
    int book_id;
    char title[100];
    char author[100];
    char category[50];
    int quantity;
    int available;
} Book;

typedef struct
{
    int member_id;
    char name[100];
} Member;

typedef struct
{
    int borrow_id;

    int member_id;
    int book_id;

    char borrow_date[11];
    char return_date[11];

    bool returned;

} BorrowRecord;
typedef struct
{
    Book *books;
    int book_capacity;
    int book_count;
    int next_book_id;

    Member *members;
    int member_capacity;
    int member_count;
    int next_member_id;

    BorrowRecord *records;
    int record_capacity;
    int record_count;
    int next_record_id;
} Library;

#endif