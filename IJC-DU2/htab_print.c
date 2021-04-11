// htab_print.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia výpisu obsahu tabuľky

#include "private_htab.h"
#include "htab.h"

// prints item data
void htab_print(htab_pair_t *data){
    printf("%s\t%d\n", data->key, data->value);
}