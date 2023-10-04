/*
 * Implement your solution in this file
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a single line from a file and return it as a dynamically allocated string.
char *read_file(char *filename){
    FILE *file;
    file = fopen(filename, "r"); //read mode open the file
    if (file==NULL) return NULL;
    fseek(file, 0 , SEEK_END); //pointer is going to the end of the file
    int length = ftell(file); // finds out how many strings are in the file
    fseek(file, 0 , SEEK_SET); //pointer is going to the beginning of the file

    char *string = malloc(sizeof(char) * (length+1)); //allocating space for the string we create

    char c;
    int i = 0;
    while ( (c=fgetc(file)) != EOF) { // loops around the file
        string[i] = c; //sets c = to whichever value i is currently placed
        i++;
    }

    string [i] = '\0';
    fclose(file);
    return string;
}

