// htab.h
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Hlavičkový súbor pre hash tabuľku a operácie na nej

#ifndef __HTAB_H__
#define __HTAB_H__

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct htab;
typedef struct htab htab_t;

typedef const char *htab_key_t;
typedef int htab_value_t;

typedef struct htab_pair {
    htab_key_t key;
    htab_value_t value;
    struct htab_pair *next;
} htab_pair_t;

size_t htab_hash_function(htab_key_t str);

htab_t *htab_init(size_t n);
htab_t *htab_move(size_t n, htab_t *from);

size_t htab_size(const htab_t *t);
size_t htab_bucket_count(const htab_t *t);

htab_pair_t *htab_find(htab_t *t, htab_key_t key);
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key);

bool htab_erase(htab_t *t, htab_key_t key);

void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data));
void htab_clear(htab_t *t);
void htab_free(htab_t *t);

// MY HTAB FUNC

void htab_print(htab_pair_t *data);

#endif // __HTAB_H__