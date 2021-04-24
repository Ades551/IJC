# Makefile
# Riešenie IJC-DU2, príklad a), b), 11.4.2021
# Autor: Adam Rajko, FIT

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -g
OBJ = htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_print.o \
htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_size.o

all: tail wordcount wordcount-dynamic

tail: tail.o
	$(CC) tail.o $(CFLAGS) -o tail

tail.o: tail.c
	$(CC) $(CFLAGS) -c $<

# wordcount
# -static (valgrind errors)
wordcount: wordcount.o libhtab.a io.o
	$(CC) $(CFLAGS) $^ -static -o $@

# wordcount dynamic
wordcount-dynamic: wordcount.o libhtab.so io.o
	$(CC) $(CFLAGS) $^ -L. -lhtab -o $@
# $(CC) $(CFLAGS) $^ -L. -Wl,-rpath=. -lhtab -o $@     # for rpath build

libhtab.a: $(OBJ)
	ar rcs libhtab.a $(OBJ)

libhtab.so: $(OBJ)
	$(CC) $(OBJ) -shared -o $@

wordcount.o: wordcount.c htab.h private_htab.h
	$(CC) $(CFLAGS) -c $<

io.o: io.c io.h
	$(CC) $(CFLAGS) -c io.c -o $@

%.o: %.c htab.h private_htab.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

.PHONY: clean
clean:
	rm *.o tail wordcount wordcount-dynamic libhtab.so libhtab.a

.PHONY: zip
zip:
	zip xrajko00 *.c *.h Makefile