#include <stdio.h>
#include "Utils.h"
#define LENGTH 10

void process(int[], int);

int main(void) {
    int numbers[] = {5, 1, 3, 9, 7, 8, 2, 0, 6, 4};
    process(numbers, LENGTH);
    printArray(numbers, LENGTH);
    return 0;
}

void process(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        /* Increase the element at index i by the element at index arr[i]
        
            For example:

            - When i = 0
            - arr[i] = 5
            - arr[arr[i]] = arr[5] = 8
            - arr[i] is now set to 8

            [8,1,3,9,7,8,2,0,6,4]

            ========= (NEXT ITERATION) =========

            - When i = 1
            - arr[i] = 1
            - arr[arr[i]] = arr[1] = 1
            - arr[i] is now set (to the same value) to 1

            [8,1,3,9,7,8,2,0,6,4]

            ... and so on

        */
        arr[i] = arr[arr[i]];
    }
}
