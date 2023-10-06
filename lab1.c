#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Method that reads line from a file 
char* readString(FILE* file) {
    char* line = NULL;
    char buffer[MAX_LINE_LENGTH];

    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Takes out the new line at the end of the file
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }

        // Mallac allotcates space for the line
        line = (char*)malloc(len + 1);
        if (line != NULL) {
            strcpy(line, buffer);
        }
    }

    return line;
}

// Methods that explodes a string
char** explodeString(const char* str, char delimiter, int* count) {
    if (str == NULL || count == NULL) {
        return NULL;
    }
    *count = 1;
    const char* ptr = str;
    while (*ptr != '\0') {
        if (*ptr == delimiter) {
            (*count)++;
        }
        ptr++;
    }

    // Mallac allocates memory into the array
    char** substrings = (char**)malloc(sizeof(char*) * (*count));
    if (substrings == NULL) {
        return NULL;
    }

    int i = 0;
    ptr = str;
    const char* start = str;

    // Goes through the string and parses it
    while (*ptr != '\0') {
        if (*ptr == delimiter || *ptr == '\0') {
            // Makes space for the string length
            size_t length = ptr - start;
            substrings[i] = (char*)malloc(length + 1);
            if (substrings[i] == NULL) {
                // Will return null if the space is not allocated
                for (int j = 0; j < i; j++) {
                    free(substrings[j]);
                }
                free(substrings);
                return NULL;
            }

            strncpy(substrings[i], start, length);
            substrings[i][length] = '\0';
            i++;

            // Iteration of the starting position of the stringS
            start = ptr + 1;
        }
        ptr++;
    }

    return substrings;
}
