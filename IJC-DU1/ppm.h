// ppm.h
// Riešenie IJC-DU1 príklad b) 20.3.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Hlavičkový súbor pre ppm štruktúru

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char *filename);
void ppm_free(struct ppm *p);