CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = stack.o brackets_checker.o
TARGET = brackets_checker

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

brackets_checker.o: brackets_checker.c stack.h
	$(CC) $(CFLAGS) -c brackets_checker.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
