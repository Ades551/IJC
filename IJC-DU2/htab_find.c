// htab_find.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia vyhľadávania prvkov v hash tabuľke

#include "private_htab.h"
#include "htab.h"

// finds item in hash table
htab_pair_t *htab_find(htab_t *table, htab_key_t key) {
    unsigned i = htab_hash_function(key) % table->arr_size;
    if(table->arr[i] != NULL) {
        htab_item_t *tmp = table->arr[i];
        while (tmp != NULL) {
            if(strcmp(key, tmp->item.key) == 0) return &tmp->item; // returns pair of stored data if found
            tmp = tmp->next;
        }
    }

    return NULL; // if not found
}