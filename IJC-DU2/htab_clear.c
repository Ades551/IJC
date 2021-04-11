// htab_clear.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia čistenia hash tabuľky

#include "private_htab.h"
#include "htab.h"

// clears all hashed data
void htab_clear(htab_t *table) {
    // list hash table
    for(unsigned i = 0; i < table->arr_size; i++) {
        if(table->arr[i] != NULL) {
            htab_item_t *tmp = table->arr[i];
            // list every collision
            while(tmp != NULL) {
                htab_item_t *del = tmp;
                tmp = tmp->next;
                free((char *)del->item.key); // free key
                free(del); // free item
            }
            table->arr[i] = NULL;
        }
    }
    table->size = 0;
}