// htab_hash_function.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia funkcie pre hashovanie reťazca

#include "private_htab.h"
#include "htab.h"

// hash fauntion
size_t htab_hash_function(htab_key_t str) {
    uint32_t h=0;
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}