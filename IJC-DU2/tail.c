// tail.c
// Riešenie IJC-DU2 príklad a) 5.4.2021
// Autor: Adam Rajko, FIT
// Preložené: gcc 9.3.0
// Implementácia výpisu konca súboru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define PRINT_LINE 10
#define MAX_LINE_LENGTH 100

int isNumber(const char* number);

int main(int argc, const char *argv[]){
    int line_print = PRINT_LINE; // default line length
    FILE *file = stdin; // default input
    bool print_index_plus = false; // if -n arg count '+'


    if(argc > 4){
        fprintf(stderr, "Error: Too many arguments!\n");
        exit(1);
    }

    for(int i = 1; i < argc; i++){
        // check if -n is an option
        if(strcmp("-n", argv[i]) == 0){
            // check if next arg exists
            if((i + 1) == argc){
                fprintf(stderr, "-n value not found!\n");
                exit(1);
            }
            // check if number
            if(isNumber(argv[++i])){
                // check if first char is '+'
                if(argv[i][0] == '+'){
                    print_index_plus = true;
                }

                // check if number is less or equal to zero
                if((line_print = atoi(argv[i])) <= 0){
                    fprintf(stderr, "Error: Number is equal or less than zero!\n");
                    exit(1);
                }
            } else {
                fprintf(stderr, "Error: -n arg is NaN!\n");
                exit(1);
            }
        } else {
            // check if file exists or is readable
            if(!(file = fopen(argv[i], "r"))){
                fprintf(stderr, "Error: File %s not exists or cannot be opened!\n", argv[i]);
                exit(1);
            }
        }
    }
    
    int c; // char from input
    unsigned index = 0; // index for each char
    unsigned line_index = 0;
    char **arr; // 2D array --> arr[line_index][index]
    bool next_line = false;
    bool dump = false; // dump line
    bool line_exceed = false;

    arr = malloc(sizeof(char *)); // allocate array of pointers
    if(arr == NULL){
        fprintf(stderr, "Error: malloc() failed!\n");
        exit(1);
    }
    arr[line_index] = malloc(MAX_LINE_LENGTH + 1); // allocate max line length
    if(arr[line_index] == NULL){
        fprintf(stderr, "Error: malloc() failed!\n");
        exit(1);
    }

    while((c = fgetc(file)) != EOF){
        // dump line
        if(dump){
            // if new line missing
            while ((c = fgetc(file)) != EOF){
                if(c == '\n')
                    break;
            }
            next_line = true;
            dump = false;
        } else {
            if(c == '\n'){
                next_line = true;
            }
            else if(index == MAX_LINE_LENGTH){
                if(!line_exceed) {
                    line_exceed = true;
                }
                dump = true;
                continue;
            }
        }

        if(next_line){
            arr[line_index][index] = (c == '\n') ? '\n' : '\0'; // ending of line
            arr[line_index][index + 1] = '\0'; // set ending char
            // realloc only when not EOF
            if(c != EOF){
                line_index++;
                arr = realloc(arr, (line_index + 1) * sizeof(char *)); // reallocate array
                if(arr == NULL){
                    fprintf(stderr, "Error: realloc() failed!\n");
                    exit(1);
                }
                arr[line_index] = malloc(MAX_LINE_LENGTH + 1);
                if(arr[line_index] == NULL){
                    fprintf(stderr, "Error: malloc() failed!\n");
                    exit(1);
                }
            }
            index = 0; // reset indexing
            next_line = false;
        } else {
            arr[line_index][index] = c;
            index++;            
        }
    }

    int print_index; // start index for printing

    if(print_index_plus){
        print_index = line_print - 1;
    } else {
        print_index = line_index + 1 - line_print;
    }

    // check if less than zero
    if(print_index < 0){
        print_index = 0; // print from first line
    }

    // print
    for(unsigned i = print_index; i <= line_index; i++){
        if(line_exceed){
            fprintf(stderr, "Line exceeded max lenght of %u characters!\n", MAX_LINE_LENGTH);
            line_exceed = false;
        }
        printf("%s", arr[i]);
    }

    for(unsigned i = 0; i <= line_index; i++){
        free(arr[i]);
    }

    free(arr);
    fclose(file);

    return 0;
}

int isNumber(const char* number){
    unsigned len = strlen(number);
    
    for(unsigned i = 0; i < len; i++){
        // check if first char is '+' or '-'
        if( ('+' == number[i] || '-' == number[i]) && i == 0){
            i++;
        }
        if(!(isdigit(number[i]))){
            return 0;
        }
    }

    return 1;
}
