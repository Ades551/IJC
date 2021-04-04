CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -g

all: tail

tail: tail.o
	$(CC) tail.o $(CFLAGS) -o tail
tail.o: tail.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm *.o tail
