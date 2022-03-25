#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 100
#define LOWERCASE_A 'a'
#define UPPERCASE_A 'A'

void printMappings(char* mapLower, char* mapUpper) {
    // Print upperCase mappings first
    for (int i = 0; i < 26; i++) {
        char current = mapUpper[i];
        if (current == '\0') continue;
        printf("%c %c\n", i + UPPERCASE_A, current);
    }

    // Print lowerCase mappings first
    for (int i = 0; i < 26; i++) {
        char current = mapLower[i];
        if (current == '\0') continue;
        printf("%c %c\n", i + LOWERCASE_A, current);
    }
    
}

int readAndGetLength(char *input) {
    fgets(input, MAX_LEN + 1, stdin);
    int len = strlen(input);
    if (input[len - 1] == '\n') input[len - 1] = '\0';
    len = strlen(input);
    return len;
}


/* 
    Returns true if mappings are:

    1. Strictly 1-to-1 mapping ONLY

 */
bool strictlyOneToOneMapping(char* mapLower, char* mapUpper) {
    int seenLower[26] = {0};
    int seenUpper[26] = {0};
    char lowerStart = LOWERCASE_A;
    char upperStart = UPPERCASE_A;

    // check mapLower
    for (int i = 0; i < 26; i++) {
        char current = mapLower[i];

        if (current == '\0') continue;

        char offset = islower(current) ? lowerStart : upperStart;
        int* mapToCheck = islower(current) ? seenLower : seenUpper;
        
        if (mapToCheck[current - offset] >= 1) return false;
        mapToCheck[current - offset] += 1;
    }

    // check mapUpper
    for (int i = 0; i < 26; i++) {
        char current = mapUpper[i];

        if (current == '\0') continue;

        char offset = islower(current) ? lowerStart : upperStart;
        int* mapToCheck = islower(current) ? seenLower : seenUpper;
        
        if (mapToCheck[current - offset] >= 1) return false;

        mapToCheck[current - offset] += 1;
    }
    return true;
}

/* 
    Returns true if mappings are:

    1. 1-to-1 mapping
    2. Many-to-1 mapping

    > if true, populates the mapLower and mapUpper mappings
    > if false, mapLower and mapUpper are not to be used

 */
bool oneOrManyToOneMapping(char* mapLower, char* mapUpper, char* plainText, char* cipherText, int textLength) {

    for (int i = 0; i < textLength; i++) {
        char currentPlain = plainText[i];
        char currentCipher = cipherText[i];
        
        char* mapToCheck = islower(currentPlain) ? mapLower : mapUpper;
        char offset = islower(currentPlain) ? LOWERCASE_A : UPPERCASE_A;

        // first check if it is 1-to-1
        if (mapToCheck[currentPlain - offset] != '\0') { // There already exists a mapping
            if (mapToCheck[currentPlain - offset] != currentCipher) return false; // If the mapping isn't the same, return
        }

        mapToCheck[currentPlain - offset] = currentCipher;
    }
    return true;
}

int main() {

    const char *UNKNOWN_MAPPING = "UNKNOWN";

    // input to be shifted
    char plainText[MAX_LEN + 1] = {'\0'};
    
    // shifted output
    char cipherText[MAX_LEN + 1] = {'\0'};
    
    // Read the buffer first
    int inputLength = readAndGetLength(plainText);
    readAndGetLength(cipherText);
    
    // Mapping for lowercase characters
    char mapLower[26] = {'\0'};

    // Mapping for uppercase characters
    char mapUpper[26] = {'\0'};

    bool firstCheckisValid = oneOrManyToOneMapping(mapLower, mapUpper, plainText, cipherText, inputLength);

    if (!firstCheckisValid) {
        printf("%s\n", UNKNOWN_MAPPING);
        return 0;
    }

    bool secondCheckIsValid = strictlyOneToOneMapping(mapLower, mapUpper);

    if (!secondCheckIsValid) {
        printf("%s\n", UNKNOWN_MAPPING);
        return 0;
    }

    // If both checks are valid, just print out the mappings
    printMappings(mapLower, mapUpper);

    return 0; 
}
