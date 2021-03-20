// bitset.c
// Riešenie IJC-DU1 príklad a) 19.3.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0

#include "bitset.h"

#ifdef USE_INLINE

extern inline bitset_index_t bitset_size(bitset_t name);
extern inline void bitset_setbit(bitset_t name, bitset_index_t index, int value);
extern inline int bitset_getbit(bitset_t name, bitset_index_t index);
extern inline void bitset_free(bitset_t name);

#endif