#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void multiplyMatrices(const int A[3][4], const int B[4][3], int res[3][3]) {

    /* 
    
        Given A[i][j] and B[j][k]

        res[i][k] = Sum from [0 ... j] (A[i][j] * B[j][k])

    */

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            res[i][k] = 0;
            for (int j = 0; j < 4; j++) {
                res[i][k] += A[i][j] * B[j][k];
            }
        }
    }

}


int main() {

    int matrixA[3][4] = {
        {0, 2, 4, 8},
        {10, 12, 14, 16},
        {18, 20, 22, 24}
    };

    int matrixB[4][3] = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17},
        {19, 21, 23}
    };

    /* Multiplying 3x4 matrix with 4x3 matrix results in a 3x3 matrix*/
    int product[3][3] = {{0}};

    multiplyMatrices(matrixA, matrixB, product);


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

}
