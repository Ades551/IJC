// bitset.h
// Riešenie IJC-DU1 príklad a) 19.3.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Hlavičkový súbor pre makra a inline funkcie

#ifndef BITSET_H
#define BITSET_H

#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "error.h"

typedef unsigned long bitset_t[];
typedef unsigned long bitset_index_t;

#define MAX_SIZE 20000000

// velkost indexu bitoveho pola
#define ARR_INDEX_SIZE (CHAR_BIT*sizeof(unsigned long))

// vyuzite aj pre inline funkcie
// bit ? 64bit |= (1 << n) : 64bit &= ~(1 << n)
#define BITSET(name, index, value) value ? (name[(index / ARR_INDEX_SIZE) + 1] |= (1UL << (index % ARR_INDEX_SIZE))) : (name[(index / ARR_INDEX_SIZE) + 1] &= ~(1UL << (index % ARR_INDEX_SIZE)))

// vyuzite aj pre inline funkcie
// (int) (64bit & (1 << n)) ? 0 : 1
#define BITGET(name, index) (int)(((name[(index / ARR_INDEX_SIZE) + 1] & (1UL << (index % ARR_INDEX_SIZE))) == 0) ? 0 : 1)

// staticke pole
// pred prekladom potrebne zvacsit velkost zasobnka (ulimit -s 50000)
#define bitset_create(name, size) \
    static_assert(size > 1, "chyba pri preklade"); \
    unsigned long name[(size / ARR_INDEX_SIZE) + 2] = {size, 0}

// dynamicka alokacia
#define bitset_alloc(name, size) \
    static_assert(size > 1, "chyba pri preklade"); \
    assert(size <= MAX_SIZE); \
    unsigned long *name = calloc((size / ARR_INDEX_SIZE) + 2, sizeof(bitset_index_t)); \
    (name != NULL) ? (name[0] = size) : (error_exit("chyba alokacie pamate"))

#ifndef USE_INLINE

// koli varovaniu pri preklade je odstranena podmienka (index < 0)
#define bitset_setbit(name, index, value) (index > bitset_size(name)) ? error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long) index, (unsigned long) bitset_size(name)), 0 : BITSET(name, index, value)
#define bitset_getbit(name, index) (index > bitset_size(name)) ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long) index, (unsigned long) bitset_size(name)), 0 : BITGET(name, index)

#define bitset_free(name) free(name)
#define bitset_size(name) name[0]

#else // USE_INLINE

inline bitset_index_t bitset_size(bitset_t name)
{
    return name[0];
}

inline void bitset_setbit(bitset_t name, bitset_index_t index, int value)
{
    if(index > bitset_size(name))
    {
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long) index, (unsigned long) bitset_size(name));
    }
    BITSET(name, index, value);
    
}

inline int bitset_getbit(bitset_t name, bitset_index_t index)
{
    if(index > bitset_size(name))
    {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long) index, (unsigned long) bitset_size(name));
    }
    return BITGET(name, index);
}

inline void bitset_free(bitset_t name)
{
    free(name);
}

#endif
#endif