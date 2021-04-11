// io.h
// Riešenie IJC-DU2 príklad b) 11.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Hlavičkový súbor pre funkciu io.c

#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>

// return types
#define ERROR -3
#define WORD_EXCEED -2

int read_word(char *str, int max, FILE *file);

#endif // __IO_H__