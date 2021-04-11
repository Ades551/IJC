// private_htab.h
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Hlavičkový súbor pre privátne dátové štruktúry

#ifndef __P_HTAB_H__
#define __P_HTAB_H__

#include "htab.h"

// linked list of items
typedef struct htab_item {
    htab_pair_t item;
    struct htab_item *next;
} htab_item_t;

struct htab {
    size_t size; // number of items in hash table
    size_t arr_size; // hash table size
    struct htab_item **arr; // pointer to hash table array of items
};

#endif // __P_HTAB_H__