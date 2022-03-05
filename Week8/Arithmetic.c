#include <stdio.h>
#include <stdbool.h>

void swap(int idx1, int idx2, int arr[]) {
    float temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void sort(int array[], int size) {
    // implementation of selection sort
    for (int i = 0; i < size; i++) {
        int min = array[i];
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < min) {
                // Set the new minimum
                min = array[j];
                minIdx = j;
            }
        }
        swap(i, minIdx, array);
    }
}

void copy(int source[], int dest[], int start, int end) {
    // copy content of array source to array dest
    for (int i = start; i <= end; i++) {
        /* 
        
            Source doesn't start from 0, but when we copy over to dest, we
            start populating from index 0.
        
        */
        dest[i - start] = source[i];
    }
}

bool isArithmetics(int array[], int start, int end) {

    // the core algorithm, where we check if a sliced array is arithmetic
    /* Edge case. If the sliced array only has one element, then it is trivially arithmetic. */
    if (start == end) return 1;

    /* Make a copy of the array from [start, end] only. */
    int SIZE = 6;
    int arrayCopy[SIZE];
    copy(array, arrayCopy, start, end);
    sort(arrayCopy, end - start + 1);

    /* After the sliced (copy of) array is sorted, the diff between each consecutive element MUST be equal. */
    int diff = arrayCopy[0] - arrayCopy[1];
    for (int i = 0; i < end - start; i++) {
        if (arrayCopy[i] - arrayCopy[i + 1] != diff)
            return false;
    }
    return true;
}


void process(int arr[], int leftBounds[], int rightBounds[], int results[], int n) {
    // process content of array source to array dest
    for (int i = 0; i < n; i++) {
        results[i] = isArithmetics(arr, leftBounds[i], rightBounds[i]);
    }
}

void readArray(int array[], int size) {
    // reading array
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void printArray(int array[], int size) {
    // printing array
    for (int i = 0; i < size; i++) {
        printf(array[i] ? "true " : "false ");
    }
    printf("\n");
}

int main() {
    int SIZE = 6;

    /* Store original elements */
    int arr[SIZE];
    readArray(arr, SIZE);

    /* Store the queries (left bounds) */
    int left[SIZE];
    readArray(left, SIZE);

    /* Store the queries (right bounds) */
    int right[SIZE];
    readArray(right, SIZE);

    /* Get results for each query */
    int result[SIZE];
    process(arr, left, right, result, SIZE);
    
    /* Print results for each query */
    printArray(result, SIZE);
    return 0;
}