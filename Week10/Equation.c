#include <stdio.h>
#include <stdbool.h>
#include <math.h> // for abs()
#include <ctype.h> // Need this for isalpha() and tolower() functions
#include <stdlib.h>
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
    
    */

    int length = strlen(buffer);

    char last = buffer[length - 1];
    buffer[length - 1] = last == '\n' ? '\0' : last;
    length = strlen(buffer);
    return length;

}


int main() {
    
    char equation[MAX_LEN + 1];

    int numLeftParenthesisToAdd = 0;
    int numRightParenthesisToAdd = 0;
    char leftParen = '(';
    char rightParen = ')';

    // Edge case is "1) + (2" 

    int len = readInputAndReturnLength(equation);

    for (int i = 0; i < len; i++) {
        char current = equation[i];

        if (current == leftParen) {
            numRightParenthesisToAdd++;
        }

        if (current == rightParen) {
            if (numRightParenthesisToAdd <= 0) numLeftParenthesisToAdd++;
            else numRightParenthesisToAdd--;
        }
    }
    printf("%d\n", numRightParenthesisToAdd + numLeftParenthesisToAdd);
    return 0;
}
