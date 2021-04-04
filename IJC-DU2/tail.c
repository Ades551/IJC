#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define PRINT_LINE 10
#define LINE_LENGTH 20

int isNumber(const char* number){
    unsigned len = strlen(number);
    
    for(unsigned i = 0; i < len; i++){
        // check if first char is '+'
        if('+' == number[i] && i == 0){
            i++;
        }
        if(!(isdigit(number[i]))){
            return 0;
        }
    }

    return 1;
}

int main(int argc, const char *argv[]){
    unsigned line_print = PRINT_LINE; // default line length
    FILE *file = stdin; // default input


    if(argc > 4){
        fprintf(stderr, "Error: Too many arguments!\n");
        exit(1);
    }

    for(int i = 1; i < argc; i++){
        // check if -n is an option
        if(strcmp("-n", argv[i]) == 0){
            // check if number is positive
            if(isNumber(argv[++i])){
                // check if number is not zero
                if((line_print = atoi(argv[i])) == 0){
                    fprintf(stderr, "Error: Number is equal to zero!\n");
                    exit(1);
                }
            } else {
                fprintf(stderr, "Error: Number is NaN or less than zero!\n");
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

    arr = malloc(sizeof(char *)); // allocate array of pointers
    if(arr == NULL){
        fprintf(stderr, "Error: malloc() failed!\n");
    }
    arr[line_index] = malloc(LINE_LENGTH); // allocate max line length
    if(arr[line_index] == NULL){
        fprintf(stderr, "Error: malloc() failed!\n");
    }

    while((c = fgetc(file)) != EOF)
    {
        // dump line
        if(dump){
            while ((c = fgetc(file)) != '\n');
            next_line = true;
            dump = false;
        } else {
            if(c == '\n'){
                next_line = true;
            }
            else if(index == LINE_LENGTH){
                dump = true;
                continue;
            }
        }

        if(next_line){
            arr[line_index][index] = '\0'; // set ending char
            line_index++;
            arr = realloc(arr, (line_index + 1) * sizeof(char *)); // reallocate array
            if(arr == NULL){
                fprintf(stderr, "Error: realloc() failed!\n");
                exit(1);
            }
            arr[line_index] = malloc(LINE_LENGTH + 1);
            if(arr[line_index] == NULL){
                fprintf(stderr, "Error: malloc() failed!\n");
                exit(1);
            }
            index = 0; // reset indexing
            next_line = false;
        } else {
            arr[line_index][index] = c;
            index++;            
        }        
    }

    int print_index = (line_index + 1) - line_print; // starting index for printing

    // check if less than zero
    if(print_index < 0){
        print_index = 0; // print from first line
    }

    // print
    for(unsigned i = print_index; i <= line_index; i++){
        printf("%s\n", arr[i]);
    }

    free(arr);

    return 0;
}