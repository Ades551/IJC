// eratosthenes.c
// Riešenie IJC-DU1 príklad a) 19.3.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia Eratostenovho sita

#include <math.h>
#include "eratosthenes.h"
#include "bitset.h"

void Eratosthenes(bitset_t pole)
{
    unsigned long size = bitset_size(pole); // velkost pola

    BITSET(pole, 0, 1);
    BITSET(pole, 1, 1);

    // Eratostenovo sito
    for(unsigned long i = 2; i < sqrt(size); i++)
    {
        if(bitset_getbit(pole, i) == 0)
        {
            for(unsigned long j = 2*i; j <= size; j+=i)
            {
                bitset_setbit(pole, j, 1);
            }
        }
    }
}