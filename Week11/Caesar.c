#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

/* 

    Modulo has an inherent cyclical nature to it:

    0 % 5 = 0       5 % 5 = 0 
    1 % 5 = 1       6 % 5 = 1
    2 % 5 = 2       7 % 5 = 2
    3 % 5 = 3       8 % 5 = 3
    4 % 5 = 4       9 % 5 = 4

*/

int readAndGetLength(char *input) {
    fgets(input, MAX_LEN + 1, stdin);
    int len = strlen(input);
    if (input[len - 1] == '\n') input[len - 1] = '\0';
    len = strlen(input);
    return len;
}

void shift(char* input, char* output, int key, int inputLength) {
    int shiftAmt = key % 26;
    char lowerZ = 'z';
    char upperZ = 'Z';

    char lowerA = 'a';
    char upperA = 'A';

    for (int i = 0; i < inputLength; i++) {
        char current = input[i];

        // We don't need to shift it if it isn't alphabetical
        if (!isalpha(current)) {
            output[i] = input[i];
            continue;
        }

        char bound = islower(current) ? lowerZ : upperZ;
        char start = islower(current) ? lowerA : upperA;
        char shiftedCurrent = '\0';

        // Wrap Around
        if ((current + shiftAmt) > bound) {
            shiftedCurrent = ((current + shiftAmt) % (bound + 1)) + start;
        } 
        // No Wrap Around
        else {
            shiftedCurrent = current + shiftAmt;
        }
        output[i] = shiftedCurrent;
    }

}

int main() {

    // input to be shifted
    char input[MAX_LEN + 1] = {'\0'};
    
    // shifted output
    char output[MAX_LEN + 1] = {'\0'};

    // key to shift by
    int key = -1;

    // Read the buffer first
    int inputLength = readAndGetLength(input);
    scanf("%d", &key);
    shift(input, output, (key % 26), inputLength);
    printf("%s\n", output);

   return 0; 
}
