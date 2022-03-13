#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* 

    Take note: When using 2D arrays, we NEED to supply the max sizes for at least the 2nd dimension
    when declaring the function signature.

    ie.

    void printSquaryArray(int arr[][], int N) is NOT OK

    void printSquareArray(int arr[][MAXSIZE], int N) is OK

    void printSquareArray(int (*arr)[MAXSIZE], int N) is OK too

*/

void printSquareArray(int arr[][MAXSIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        putchar('\n');
    }
}

void readArray(int arr[MAXSIZE][MAXSIZE], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void transpose(int arr[MAXSIZE][MAXSIZE], int N) {
    /* Transposition is simply swapping along the diagonal */
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int* rowVal = &arr[i][j];
            int* colVal = &arr[j][i];
            swap(rowVal, colVal);
        }
    }
}

void swapColumns(int arr[MAXSIZE][MAXSIZE], int N) {
    /* We stop swapping at the middle column */
    int columnToStopAt = N / 2;

    for (int colIdx = 0; colIdx < columnToStopAt; colIdx++) {
        int toSwitchWith = (N - 1) - colIdx;
        for (int r = 0; r < N; r++) {
            swap(&arr[r][colIdx], &arr[r][toSwitchWith]);
        }
    }
}

/* Rotating the array clockwise once is the same as transposing it and then swapping columns */
void rotateArray(int arr[MAXSIZE][MAXSIZE], int N) {
    transpose(arr, N);
    swapColumns(arr, N);
}

int main() {
    int arr[MAXSIZE][MAXSIZE];
    int N;
    scanf("%d", &N);
    readArray(arr, N);
    rotateArray(arr, N);
    printSquareArray(arr, N);   
    return 0;
}
