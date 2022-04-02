#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printCombinations(bool *arr, int X, int start, int arrSize) {
    if (X == 0) {
        for (int i = 0; i < arrSize; i++) {
            if (arr[i]) printf("%d ", i + 1);
        }
        printf("\n");
        return;
    }
    
    for (int i = start; i < arrSize; i++) {
        if (!arr[i]) {
            arr[i] = true;
            printCombinations(arr, X - 1, i + 1, arrSize);
            arr[i] = false;
        }
    }
}


int main() {
    
    int N, K;
    scanf("%d %d", &N, &K);
    
    
    bool *arr = malloc(sizeof(bool) * N);
    for (int i = 0; i < N; i++) arr[i] = false;
    printCombinations(arr, K, 0, N);

    free(arr);

    return 0;

}