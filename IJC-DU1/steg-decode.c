// steg-decode.c
// Riešenie IJC-DU1 príklad b) 20.3.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia dešifrovania tajnej správy

#include <stdio.h>
#include <limits.h>
#include "error.h"
#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"

int main(int argc, char const *argv[])
{
    // ocakavany input iba cesta k ppm suboru
    if(argc != 2)
        error_exit("Ocakavany 1 argument!\n");

    struct ppm *image = ppm_read(argv[1]);

    // nepodarilo sa nacitat data
    if(image == NULL)
        error_exit("Nepodarilo sa nacitat data z ppm suboru!");

    unsigned long data_size = image->xsize * image->ysize * 3;

    bitset_alloc(primes, data_size); // prvocisla
    char message_char = 0;

    Eratosthenes(primes);

    int count = 0; // pomocna premmena na zistenie dalsieho charu 

    for(unsigned long i = 23; i < bitset_size(primes); i++)
    {
        if(bitset_getbit(primes, i) == 0)
        {
            // xxx1, xx01, x101, 0101
            // postupne pridavanie bitov do charu
            message_char |= (1 & image->data[i]) << count;
            count++;
            if(count == CHAR_BIT)
            {
                if(message_char == '\0')
                {
                    bitset_free(primes);
                    ppm_free(image);
                    putchar('\n');
                    break;
                }
                else
                {
                    putchar(message_char);
                }
                count = 0;
                message_char = 0;
            }
        }
    }

    return 0;
}