CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c book.c member.c borrow.c library.c utils.c
TARGET = lib

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)