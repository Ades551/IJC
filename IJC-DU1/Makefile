# Makefile
# Riešenie IJC-DU1, príklad a), b), 19.3.2021
# Autor: Adam Rajko, FIT

CC=gcc
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra -O2
PRIME_OBJECTS=primes.o error.o eratosthenes.o

all: primes

primes: $(PRIME_OBJECTS)
	$(CC) $(PRIME_OBJECTS) -o primes -lm
	$(CC) $(PRIME_OBJECTS) -DUSE_INLINE -o primes-i -lm
primes.o:
	$(CC) $(CFLAGS) -c $*.c
error.o:
	$(CC) -c $*.c
eratosthenes.o:
	$(CC) -c $*.c
clean:
	rm -r primes
	rm -r primes-i
	rm -r *.o
run:
	./primes
	./primes-i
