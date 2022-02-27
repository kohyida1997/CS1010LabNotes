#include <stdio.h>


/* 
    Using ASCII representation, letters of the same CASE correspond to consecutive numbers.

    'A' - 'A' = 0
    'B' - 'A' = 1
    'C' - 'A' = 2
    'D' - 'A' = 3
    'E' - 'A' = 4
    'F' - 'A' = 5
*/
int resolveIndexForChar(char c) { /* Helper function */
    return c - 'A';
}

void processGrades(int numGrades, int *gradeCount) { /* using "int *gradeCount" is the same as using "int gradeCount[]" as argument */

    char currGrade = 0;
    for (int i = 0; i < numGrades; i++) {
        scanf(" %c", &currGrade); /* Notice the space in front of the %c format specifier */
        gradeCount[resolveIndexForChar(currGrade)] += 1;
    }

}

void printGrades(int *gradeCount) { /* using "int *gradeCount" is the same as using "int gradeCount[]" as argument */
    char gradeLetters[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < 6; i++) {
        printf("%c %d ", gradeLetters[i], gradeCount[i]);
    }
    putchar('\n');
}

int main() {
    int numGrades;
    int gradeCount[6] = {0};
    scanf("%d", &numGrades);
    processGrades(numGrades, gradeCount);
    printGrades(gradeCount);
}
