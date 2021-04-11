// htab_erase.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia vymazania prvku z hash tabuľky

#include "private_htab.h"
#include "htab.h"

// TODO HEAD only item

// erase stored data in table
bool htab_erase(htab_t *table, htab_key_t key) {
    unsigned i = htab_hash_function(key) % table->arr_size;

    if(table->arr[i] != NULL){
        htab_item_t *prev = table->arr[i]; // previous item
        htab_item_t *tmp = prev;

        while(tmp != NULL){
            if(strcmp(key, tmp->item.key) == 0){
                // if del item is HEAD item
                if(table->arr[i] == tmp){
                    // if HEAD item is only item
                    if(table->arr[i]->next == NULL){
                        table->arr[i] = NULL;
                        table->size--;
                    } else {
                        table->arr[i] = table->arr[i]->next;
                    }
                } else {
                    prev->next = tmp->next;
                }
                free((char *) tmp->item.key);
                free(tmp);
                return true; // removed
            }
            prev = tmp;
            tmp = tmp->next;
        }
    }

    return false; // not removed
}