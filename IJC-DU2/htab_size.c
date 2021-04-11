// htab_size.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia zistenia počtu miest zaplnených v tabuľke

#include "private_htab.h"
#include "htab.h"

// returns value of how many nodes are being used in hash table
size_t htab_size(const htab_t *table){
    return table->size;
}