#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Need this for malloc/free

#define MAX_ELEMENTS 100

void read1DArray(int* arr) {
    int i = 0;
    int temp;
    while (i < MAX_ELEMENTS) {
        scanf("%d", &temp);
        if (temp == -1) break;
        arr[i] = temp;
        i++;
    }
}

void printArray(int arr[MAX_ELEMENTS][MAX_ELEMENTS], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    size_t sizeOfIntegerInBytes = sizeof(int);

    /* calloc will initialize the memory to ZERO, malloc WILL NOT. */
    int* elems = (int *) calloc(MAX_ELEMENTS, sizeOfIntegerInBytes); 
    read1DArray(elems);

    /* Read dimensions of 2D array*/
    int r, c;
    int res[100][100];
    scanf("%d %d", &r, &c);

    /* Populate */
    for (int i = 0; i < r; i++) {
        int* rowPtr = elems + (i * c);
        for (int j = 0; j < c; j++) {
            res[i][j] = rowPtr[j];
        }
    }

    /* Print */
    printArray(res, r, c);

    /* Very important to free malloc'ed or calloc'ed memory, or else there will be a memory leak. */
    free(elems);
    return 0;
}
