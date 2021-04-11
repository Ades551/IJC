// htab_bucket_count.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia zistenia veľkosti hash tabuľky

#include "private_htab.h"
#include "htab.h"

// returns size of an array
size_t htab_bucket_count(const htab_t *table){
    return table->arr_size;
}