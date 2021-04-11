// htab_lookup_add.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia vyhľadania a pridania prvku do tabuľky

#include "private_htab.h"
#include "htab.h"

// add key to the table
htab_pair_t *htab_lookup_add(htab_t *table, htab_key_t key){
    unsigned i = htab_hash_function(key) % table->arr_size;
    if(table->arr[i] != NULL) {
        htab_item_t *tmp = table->arr[i];
        htab_item_t *prev;
        // list through each collision
        while (tmp != NULL) {
            // if already in table
            if(strcmp(key, tmp->item.key) == 0){
                tmp->item.value++; // increase value of key value
                return &tmp->item;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        // if not found in table
        prev->next = malloc(sizeof(htab_item_t));
        if(prev->next == NULL) return NULL;
        
        prev->next->item.key = malloc(strlen(key) + 1);
        if(prev->next->item.key == NULL) return NULL;
        
        strcpy((char *) prev->next->item.key, key);
        
        prev->next->item.value = 1;
        prev->next->next = NULL;
        return &prev->next->item;
    } else {
        // if table arr not initialized
        table->arr[i] = malloc(sizeof(htab_item_t));
        if(table->arr[i] == NULL) return NULL;
        
        table->arr[i]->item.key = malloc(strlen(key) + 1);
        if(table->arr[i]->item.key == NULL) return NULL;
        
        strcpy((char *) table->arr[i]->item.key, key);
        
        table->arr[i]->item.value = 1;
        table->arr[i]->next = NULL;
        table->size++;
        return &table->arr[i]->item;
    }
}