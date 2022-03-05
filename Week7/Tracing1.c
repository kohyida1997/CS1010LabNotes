#include <stdio.h>
#include "Utils.h"
#define LENGTH 10


void weirdStuff(int[], int);
void arrange(int[], int);

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //arrange(numbers, LENGTH); // we actually pass in the address to the first element of the array "numbers"
    //weirdStuff(numbers + 2, LENGTH - 2); // pass in only a portion of the array
    
    printArray(numbers, LENGTH);
    return 0;
}

void arrange(int arr[], int size) { // essentially same as arrange(int *arr, int size) -> it takes in the pointer to the array
    for (int i = 2; i < size; i++) {
        /* Increase the previous elements by the arr[i] */
        arr[i - 2] += arr[i];
        arr[i - 1] += arr[i];
    }
}

void weirdStuff(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}
