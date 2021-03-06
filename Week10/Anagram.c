#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> // Need this for isalpha() and tolower() functions
#include <stdlib.h> // for atoi()
#include <string.h> // Need this for strlen()

#define MAX_LEN 100


/* 

    Reads a SINGLE LINE of input, and returns the length of the input read after changing terminating character to '\0' if necessary.

    Take note:

    - Takes in a char* buffer to read into
    - Assumes that the input line is not longer than the size allocated to the char* buffer
    - Need to define the MAX_LEN macro before using this function

*/
int readInputAndReturnLength(char *buffer) { 

    // Take note we must use (MAX_LEN + 1) to account for null-character
    fgets(buffer, MAX_LEN + 1, stdin);

    /* 
    
    fgets(BUFFER, n, INPUT_STREAM) documentation:

    It reads a line from the specified stream and stores it into the string pointed to by str.
    It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes first.
    
    Note: it will actually also read the newline if the buffer is large enough.
    
    */

    int length = strlen(buffer);

    buffer[length - 1] = buffer[length - 1] == '\n' ? '\0' : buffer[length - 1];

    length = strlen(buffer);

    return length;

}


int main() {
    
    // Always good to initialize with nulls
    char string1[MAX_LEN + 1] = {'\0'};
    char string2[MAX_LEN + 1] = {'\0'};

    int str1Length = readInputAndReturnLength(string1);
    int str2Length = readInputAndReturnLength(string2);

    int table[26] = {0};
    char lowerCaseLetterA = 'a';

    /* Go through first string and populate table. */
    for (int i = 0; i < str1Length; i++) {
        char current = string1[i];
        if (isalpha(current)) {
            table[tolower(current) - lowerCaseLetterA]++;
        }
    }

    /* Go through second string and subtract from each index in table. */
    for (int i = 0; i < str2Length; i++) {
        char current = string2[i];
        if (isalpha(current)) {
            table[tolower(current) - lowerCaseLetterA]--;
        }
    }

    /* Now check if everything is back to zero. */
    for (int i = 0; i < 26; i++) {
        if (table[i] != 0) {
            printf("0\n");
            return 0;
        }
    }

    printf("1\n");
    return 0;
}
