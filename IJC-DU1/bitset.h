// primes.c
// Riešenie IJC-DU1 príklad a) 19.3.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Hlavičkový súbor pre makro

#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "error.h"

typedef unsigned long bitset_t[];
typedef unsigned long bitset_index_t;

#define MAX_SIZE 200000000
#define ARR_INDEX_SIZE (CHAR_BIT*sizeof(unsigned long))

// bit ? 64bit |= (1 << n) : 64bit &= ~(1 << n)
#define BITSET(name, index, value) value ? (name[(index / ARR_INDEX_SIZE) + 1] |= (1UL << (index % ARR_INDEX_SIZE))) : (name[(index / ARR_INDEX_SIZE) + 1] &= ~(1UL << (index % ARR_INDEX_SIZE)))
// (int) (64bit & (1 << n)) ? 0 : 1
#define BITGET(name, index) (int)(((name[(index / ARR_INDEX_SIZE) + 1] & (1UL << (index % ARR_INDEX_SIZE))) == 0) ? 0 : 1)

// inicializacia pola
#define bitset_create(name, size) \
    static_assert(size > 1, "chyba pri preklade"); \
    unsigned long name[(size / ARR_INDEX_SIZE) + 2] = {size, 0}

// alokacia pola
#define bitset_alloc(name, size) \
    static_assert(size > 1, "chyba pri preklade"); \
    assert(size <= MAX_SIZE); \
    unsigned long *name = calloc((size / ARR_INDEX_SIZE) + 2, sizeof(bitset_index_t)); \
    if(name != NULL) {name[0] = size;} \
    else {error_exit("chyba alokacie pamate");}

#ifndef USE_INLINE

#define bitset_setbit(name, index, value) ((index > bitset_size(name)) || (index < 0)) ? error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long) index, (unsigned long) bitset_size(name)), 0 : BITSET(name, index, value)
#define bitset_getbit(name, index) ((index > bitset_size(name)) || (index < 0)) ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long) index, (unsigned long) bitset_size(name)), 0 : BITGET(name, index)
#define bitset_free(name) free(name)
#define bitset_size(name) name[0]

#else // USE_INLINE

inline bitset_index_t bitset_size(bitset_t name)
{
    return name[0];
}

inline void bitset_setbit(bitset_t name, bitset_index_t index, u_int8_t value)
{
    if((index > bitset_size(name)) || (index < 0))
    {
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long) index, (unsigned long) bitset_size(name));
    }
    BITSET(name, index, value);
}

inline u_int8_t bitset_getbit(bitset_t name, bitset_index_t index)
{
    if((index > bitset_size(name)) || (index < 0))
    {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long) index, (unsigned long) bitset_size(name));
    }
    BITGET(name, index);
}

inline void bitset_free(bitset_t name)
{
    free(name);
}

#endif