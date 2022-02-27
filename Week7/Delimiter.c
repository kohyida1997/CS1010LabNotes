#include <stdio.h>
#include <stdbool.h>

/* Helper function to read space separated input (on a single line) into a fixed-length buffer. */
void readIntoBuffer(int len, int* buff) {
    int curr;
    for (int i = 0; i < len; i++) {
        scanf(" %d", &curr);
        buff[i] = curr;
    }
}

/* 

    Checks if there is a delimiter starting from index "start" in the binary string payload.

    This is done by trying to match individual bits against the given delimiter, starting from index "start".

*/
bool isDelimiterStartingHere(int stringLen, int* binaryString, int delimiterLen, int* delimiter, int start) {
    /* Index to move across the binary string payload. */
    int payloadPtr = start;

    /* Index to move across the delimiter. */
    int delimPtr = 0;
    
    /* By default, we assume there is no delimiter starting from "start". */
    bool isDelimiter = false;

    /* Make sure we don't reach beyond the end of the payload string, and also don't reach beyond the end of the delimiter. */
    while (payloadPtr < stringLen && delimPtr < delimiterLen) {

        /* If the bits don't match between the binary string and the delimiter, we break out of the while-loop (because we already know that the substring doesn't match the delimiter) */
        if (binaryString[payloadPtr] != delimiter[delimPtr]) break;
        
        /* If we didn't break in the previous steps, advance the pointers. */
        payloadPtr++;
        delimPtr++;
    }

    /* 
    
        If we exit the while loop and manage to match ALL bits, then delimPtr's value will be equal to delimLen.
        This means that the substring starting from "start" actually does match the delimiter. So we return "true".
    
    */
    if (delimPtr == delimiterLen) isDelimiter = true;

    return isDelimiter;
}

void getStartingPoints(int stringLen, int* binaryString, int delimiterLen, int* delimiter) {

    printf("%d ", 0); // Question constraints say the delimiter cannot be at the start of the payload.

    /* We already know index 0 cannot be the start of a delimiter. */
    int i = 1;

    /* Note the condition in the while loop again to ensure we don't go out of bounds. */
    while (i < stringLen) {

        /* Check if there is a delimiter starting from "i" */
        if (isDelimiterStartingHere(stringLen, binaryString, delimiterLen, delimiter, i)) {
            /* 
            
                If true, then we move pointer i to beyond the delimiter. 
                (NOTE: We are guaranteed that no two limiters can be next to each other.)
            
            */
            i += delimiterLen;

            /* If pointer i has not exceeded the length of the entire payload, then we report it as a new starting position.*/
            if (i < stringLen) printf("%d ", i);
        } else {
            /* If there is no delimited starting from i, then we just advance the pointer by 1 and go to the next iteration. */
            i++;
        }
    }
    putchar('\n');
}

int main() {
    int stringLen, delimiterLen;
    scanf("%d %d", &stringLen, &delimiterLen);

    int delimiter[10];
    int binaryString[100];

    readIntoBuffer(delimiterLen, delimiter);
    readIntoBuffer(stringLen, binaryString);
    getStartingPoints(stringLen, binaryString, delimiterLen, delimiter);
}
