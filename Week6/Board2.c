#include <stdio.h>
#include <stdbool.h>

void printHorizontalBorder(int n) {
    int numToPrint = 9 + 8 * n;
    for (int i = 0; i < numToPrint; i++) {
        putchar('#');
    }
    putchar('\n');
}

void printInternalRow(int n, bool blackFirst) {
    for (int i = 0; i < 4; i++) {
        putchar('#');
        for (int j = 0; j < n; j++) {
            putchar(blackFirst ? '*' : ' ');
        }
        putchar('#');
        for (int k = 0; k < n; k++) {
            putchar(blackFirst ? ' ' : '*');
        }
    }
    putchar('#');
    putchar('\n');
}

void printRow(int n, bool blackFirst) {
    for (int i = 0; i < n; i++) {
        printInternalRow(n, blackFirst);
    }
}

void printSetOfTwoRows(int n) {
    printHorizontalBorder(n);
    printRow(n, true);
    printHorizontalBorder(n);
    printRow(n, false);
}

void printBoard(int n) {
    for (int i = 0; i < 4; i++) {
        printSetOfTwoRows(n);
    }
    printHorizontalBorder(n);
}

int main() {
    int n;
    scanf("%d", &n);
    printBoard(n);
    return 0;
}