CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c book.c member.c borrow.c library.c
TARGET = library

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)