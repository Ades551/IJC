// io.c
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia čítania slova zo vstupu

#include "io.h"

int read_word(char *str, int max, FILE *file){
    if(max <= 0){
        fprintf(stderr, "io_error: Invalid max size!\n");
        return ERROR;
    }

    if(file == NULL){
        fprintf(stderr, "io_error: Invalid input!\n");
        return ERROR;
    }

    int c;
    int i = 0;
    while((c = fgetc(file)) != EOF){
        if(c == ' ' && i == 0) continue; // space before word
        if(c == '\n' || c == ' ') break; // end of line or end of word
        if(i == (max - 1)) continue; // word exceeded max length
        
        str[i] = c;
        i++;
    }

    if(i == (max - 1)) return WORD_EXCEED;

    str[i] = '\0';
    
    if(c == EOF && i == 0) return EOF;
    return i;
}