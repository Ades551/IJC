// htab_free.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia uvoľnenia hash tabuľky z pamäte

#include "private_htab.h"
#include "htab.h"

// free table
void htab_free(htab_t *table) {
    htab_clear(table);
    free(table->arr);
    free(table);
}