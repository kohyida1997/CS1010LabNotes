#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void randomizeMyNumber(int *myNumber) {
    int random = rand() % 1000;
    printf("\n  ... randomizing integer stored at: %p, it's value is now = %d\n", myNumber, random);
    *myNumber = random; // get a random number between 0 - 999
}

void doubleMyNumber(int *myNumber) {
    printf("\n  ... performing operation (x2) on integer stored at: %p\n", myNumber);
    *myNumber = *myNumber * 2;
}

void squareMyNumber(int *myNumber) {
    printf("\n  ... performing operation (^2) on integer stored at: %p\n", myNumber);
    *myNumber = *myNumber * (*myNumber);
}

void decreaseMyNumber(int *myNumber) {
    printf("\n  ... performing operation (--) on integer stored at: %p\n", myNumber);
    *myNumber = *myNumber - 1;
}

void swapMyNumber(int *myNumber, int *otherNumber) {
    printf("\n  ... swapping integers stored at: %p, %p\n", myNumber, otherNumber);
    int temp = *myNumber;
    *myNumber = *otherNumber;
    *otherNumber = temp;
}

int main() {

    time_t t;
    srand((unsigned) time(&t));

    int myOriginalNumber = 10;
    printf(">> Created myOriginalNumber at address: %p\n", &myOriginalNumber);

    printf("\n1. Initial myOriginalNumber: %d\n", myOriginalNumber);

    doubleMyNumber(&myOriginalNumber);
    printf("\n2. After doubling myOriginalNumber: %d\n", myOriginalNumber);
    
    squareMyNumber(&myOriginalNumber);
    printf("\n3. After squaring myOriginalNumber: %d\n", myOriginalNumber);

    decreaseMyNumber(&myOriginalNumber);
    printf("\n4. After decreasing myOriginalNumber: %d\n", myOriginalNumber);

    int myOtherNumber = 0;
    printf("\n>> Created myOtherNumber at address: %p\n", &myOtherNumber);
    randomizeMyNumber(&myOtherNumber);

    swapMyNumber(&myOriginalNumber, &myOtherNumber);
    printf("\n5. After swapping out myOriginalNumber: %d\n", myOriginalNumber);

    return 0;
}
