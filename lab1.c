#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
//Creating readstring function that will read what is in the file
char* readString(char* filename) {

    FILE* file =  fopen(filename,"r");//Fopen will open the file in read mode 
    if (file == NULL) {//If file is empty, then reutrn a error message
        fprintf(stderr ,"Can't find");
    }
    char* string = (char*) malloc(MAX_LINE_LENGTH *sizeof(char));//allocate space for the string
    
    if (string != NULL) {
        fgets(string,MAX_LINE_LENGTH,file);
        fclose(file);//closes the file pointer
} else {
    free(string);
}

    return string;

}


char* mysteryExplode(const char* str) {//mystery explode takes the parameter of the type string from read string function

    int len = strlen(str);
    int explodedLength = len*(len + 1)/2 +1;
    char* explodedString = (char*)malloc(explodedLength);//space is allocated for exploded string 
    
    if(explodedString == NULL){
        return NULL;
    }
    int d, s, r = 0;
    
    for (d = 0; d < len; d++) {//loop that completes the algorithm for the mysteryexplode
        for (s = 0; s <= d-1; s++) {
            explodedString[r++] = str[s];//values are appended to exploded string
        }
    }
    
    explodedString[r] = '\0';
    return explodedString;
}
    
