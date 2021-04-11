// htab_for_each.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia volania funkcie pre každý prvok funkcie

#include "private_htab.h"
#include "htab.h"

// list through each key in hash table and call some function
void htab_for_each(const htab_t *table, void (*function)(htab_pair_t *data)){
    for(unsigned i = 0; i < table->arr_size; i++){
        if(table->arr[i] != NULL){
            htab_item_t *tmp = table->arr[i];
            while(tmp != NULL){
                function(&tmp->item);
                tmp = tmp->next;
            }
        }
    }
}