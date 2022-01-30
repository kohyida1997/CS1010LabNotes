#include <stdio.h>

int main() {

    /* 
    
        Context:
            - When we receive messages, they are in binary format
            - The first 4 bits are actual data.
            - The last bit is a parity bit
            - There are rules that dictate what the parity bit should be
            - We want to check if the message received follows these rules
            - This is actually used in practice
            - Sometimes when messages get sent over a network, things get corrupted.
            - Checking whether the parity bit is correct helps us know whether a message is corrupted, and should be dropped.

        Even parity: 
            - if first 4 digits have EVEN number of ones, parity bit should be 0
            - if first 4 digits have ODD number of ones, parity bit should be 1

        XOR (^): Commutative and Associative
            1 ^ 1 = 0
            1 ^ 0 = 1
            0 ^ 1 = 1
            0 ^ 0 = 0

    */

    int input;

    scanf("%d", &input);
 
    int digitOne, digitTwo, digitThree, digitFour, givenParityBit;

    givenParityBit = input % 10;
    input /= 10;

    digitFour = input % 10;
    input /= 10;

    digitThree = input % 10;
    input /= 10;

    digitTwo = input % 10;
    input /= 10;

    digitOne = input % 10;

    int numberOfOnes = digitOne + digitTwo + digitThree + digitFour;
    int expectedParityBit = numberOfOnes % 2; // if even -> 0, if odd -> 1

    int parityBitsMatch = expectedParityBit ^ givenParityBit; // if they MATCH -> 0, if they DON'T MATCH -> 1
    int isValid = 1 ^ parityBitsMatch; 
    printf("%d\n", isValid);

    return 0;
}

// int main() {
//     int input;
//     scanf("%d", &input);
//     int digitOne, digitTwo, digitThree, digitFour, digitFive;
//     digitFour = input % 10;
//     input /= 10;
//     digitThree = input % 10;
//     input /= 10;
//     digitTwo = input % 10;
//     input /= 10;
//     digitOne = input % 10;
//     input /= 10;
//     digitFive = input % 10;
//     int parityBit = digitFour ^ digitThree ^ digitTwo ^ digitOne;
//     int isValid = parityBit ^ digitFive ^ 1;
//     printf("%d\n", isValid);
// }