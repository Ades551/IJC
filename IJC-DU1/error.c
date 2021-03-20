// error.c
// Riešenie IJC-DU1 príklad a) 19.3.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia chybovýh hlásení

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "error.h"

void warning_msg(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

void error_exit(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    exit(1);
}