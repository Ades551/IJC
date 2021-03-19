// primes.c
// Riešenie IJC-DU1 príklad a) 19.3.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia hľadania prvočísel a výpisu prvočísel

#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

// limit prvocisel
#define N 200000000

// pocet vypisanych prvocisel (odzadu)
#define PRINT_MAX 10

int main(void)
{
    clock_t start = clock();

    unsigned long primes[PRINT_MAX];
    bitset_create(array, N);

    Eratosthenes(array);

    int count = 0;
    
    for(unsigned long i = N; i > 1; i--)
    {
        if(bitset_getbit(array, i) == 0)
        {
            primes[count] = i;
            count++;
            if(count == PRINT_MAX)
                break;
        }
    }
    
    // vypis prvocisel
    for (int i = PRINT_MAX - 1; i >= 0; i--)
    {
        printf("%lu\n", primes[i]);
    }
    
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}