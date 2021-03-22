// ppm.c
// Riešenie IJC-DU1 príklad b) 20.3.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia načítania z ppm súboru

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "error.h"
#include "ppm.h"

struct ppm *ppm_read(const char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    struct ppm *image = NULL;

    // neuspesne otvorenie suboru
    if(file == NULL)
    {
        warning_msg("warning_ppm: Failed to open file!");
        goto error_ppm;
    }

    // P6\n\0
    char line[4];

    if(fgets(line, 4, file) == NULL)
    {
        warning_msg("warning_ppm: Missing magic number!");
        goto error_ppm;
    }

    // P6\n
    if(strcmp(line, "P6\n") != 0)
    {
        warning_msg("warning_ppm: Expected P6 as magic number!");
        goto error_ppm;
    }

    unsigned x, y, rgb;

    // <cislo> <cislo>\n
    if(fscanf(file, "%u %u\n", &x, &y) == 0)
    {
        warning_msg("warning_ppm: File size not specified!");
        goto error_ppm;
    }

    // 255\n   
    if(fscanf(file, "%u\n", &rgb) == 0)
    {
        warning_msg("warning_ppm: Wrong rgb value or missing!");
        goto error_ppm;
    }

    unsigned long data_size = 3*x*y;

    // ocakavana max velkost 
    if(data_size > 3*8000*8000)
    {
        warning_msg("warning_ppm: File size exceed limit!");
        goto error_ppm;
    }
    
    // rgb ockavana hodnota 255
    if(rgb != 255)
    {
        warning_msg("warning_ppm: Expected RGB value 255!");
        goto error_ppm;
    }
    
    image = malloc(sizeof(struct ppm) + 3*x*y);

    image->xsize = x;
    image->ysize = y;

    int c;
    unsigned long i = 0;

    // nacitanie obsahu suboru
    while ((c = fgetc(file)) != EOF)
    {
        image->data[i] = c;
        i++;
    }
    
    fclose(file);

    return image;

    // skok na koniec pri chybe
    error_ppm:
        if(image)
            ppm_free(image);
        fclose(file);
        return NULL;
}

void ppm_free(struct ppm *p)
{
    free(p);
}
