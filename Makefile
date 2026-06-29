CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c src/*/*.c
TARGET = library.exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)