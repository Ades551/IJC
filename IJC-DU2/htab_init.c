// htab_init.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia inicializácie hashovacej tabuľky

#include "private_htab.h"
#include "htab.h"

// initialize hash table
htab_t *htab_init(size_t n) {
    htab_t *table = malloc(sizeof(htab_t));
    if(table == NULL) return NULL;
    
    table->arr = malloc(n * sizeof(htab_item_t));
    if(table->arr == NULL) return NULL;
    
    table->size = 0;
    table->arr_size = n;
    
    for(unsigned i = 0; i < n; i++){
        table->arr[i] = NULL;
    }
    
    return table;
}