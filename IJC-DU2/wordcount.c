// wordcount.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia počítania výskytu slov pomocou hash tabuľky

#include "private_htab.h"
#include "io.h"

#include <stdbool.h> // bool
#include <string.h> // strcmp

/**
 * I decided on the basis of these rules:
 * - 1. Size of hash table should be a prime number
 * - 2. Size of hash table array should be 1.3x times maximum of number of expected keys.
 * 
 * If we assume that average file contains 1000 words
 * 
 * 1.3 * 1000 = 1300 round to first largest prime number is 1301
 **/

#define HASH_TABLE_SIZE 1301
#define MAX_WORD_LENGTH 127

int main() {
    htab_t *table = htab_init(HASH_TABLE_SIZE);

    if(table == NULL){
        fprintf(stderr, "Initialization for hash table failed!\n");
        exit(1);
    }

    char keys[MAX_WORD_LENGTH];

    bool word_exceed = false;
    int c;

    while((c = read_word(keys, MAX_WORD_LENGTH, stdin)) != EOF){
        // if max word length exceed
        if(c == WORD_EXCEED && word_exceed == false){
            fprintf(stderr, "Word exceeded max legnth of %u characters\n", MAX_WORD_LENGTH);
            word_exceed = true;
        }
        // if error occur
        else if(c == ERROR){
            exit(1);
        }

        // add key to hash table
        if(strcmp(keys, "\0") != 0){
            if(htab_lookup_add(table, keys) == NULL){
                fprintf(stderr, "wordcount_err: htab_lookup_add() failed!\n");
                exit(1);
            }
        }
    }
    
    htab_for_each(table, htab_print); // prints hash table data

    htab_free(table);

    return 0;
}