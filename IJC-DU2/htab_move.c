// htab_move.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia preloženia dát do novej tabuľky a vymazania dát z predošlej

#include "private_htab.h"
#include "htab.h"

// moves previous table to new table and clears old one
htab_t *htab_move(size_t n, htab_t *from){
    htab_t *table = htab_init(n);
    for(unsigned i = 0; i < from->arr_size; i++){
        if(from->arr[i] != NULL){
            htab_item_t *tmp = from->arr[i];
            while(tmp != NULL){
                htab_pair_t *tmp_new = htab_lookup_add(table, tmp->item.key);
                tmp_new->value = tmp->item.value;
                tmp = tmp->next;
            }
        }
    }

    htab_clear(from);

    return table;
}