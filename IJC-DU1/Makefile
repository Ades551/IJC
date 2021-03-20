# Makefile
# Riešenie IJC-DU1, príklad a), b), 19.3.2021
# Autor: Adam Rajko, FIT

CC = gcc
LDFLAGS = -lm
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -O0
DEPS = bitset.h error.h eratosthenes.h
PRIME_OBJECTS = primes.o error.o eratosthenes.o bitset.o                # objekty pre primes
PRIME_OBJECTS_I = primes-i.o error-i.o eratosthenes-i.o bitset-i.o      # objekty pre primes-i

all: primes primes-i

primes: $(PRIME_OBJECTS)
	$(CC) $(PRIME_OBJECTS) $(CFLAGS) $(LDFLAGS) -o primes

primes-i: $(PRIME_OBJECTS_I)
	$(CC) $(PRIME_OBJECTS_I) $(CFLAGS) $(LDFLAGS) -DUSE_INLINE -o primes-i

primes.o: primes.c $(DEPS)
	$(CC) $(CFLAGS) -c $*.c

error.o: error.c error.h
	$(CC) $(CFLAGS) -c $*.c

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h
	$(CC) $(CFLAGS) -c $*.c

bitset.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -c $*.c

primes-i.o: primes.c $(DEPS)
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o $*.o

error-i.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c -o $*.o

eratosthenes-i.o: eratosthenes.c eratosthenes.h bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o $*.o

bitset-i.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o $*.o

.PHONY: clean
clean:
	rm *.o primes primes-i

.PHONY: run
run:
	ulimit -s 75000; ./primes
	ulimit -s 75000; ./primes-i
