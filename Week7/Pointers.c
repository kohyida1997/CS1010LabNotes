#include <stdio.h>

void tracePointers1() {

    printf("===== TRACING POINTERS 1 =====\n");

    int i = 1; // Line 1

    int *p; // Line 2

    i += 2; // Line 3 ----> i = 1 + 2 = 3. [i = 3]

    p = &i; // Line 4 ----> p POINTS to i. (p stores the address of i)

    (*p)++; // Line 5 ----> we dereference p (go to the address), and increase the value at that address by 1. [i = 4] {same as doing i++}

    *p = *p + i; // Line 6 ----> we set the value at address pointed to by p to be equals to (*p) + 1. i = i + i = 8. [i = 8] {same as doing i = i + i}

    printf("Final value of i = %d\n", i);
}

void tracePointers2() {

    printf("===== TRACING POINTERS 2 =====\n");

    int i = 1, j = 1; // Line 1

    int *p, *q;      // Line 2

    i += 2;          // Line 3 ----> i = i + 2. [i = 3]

    p = &i;          // Line 4 ----> p points to i

    *p = *p + 3;     // Line 5 ----> p points to i, i = i + 3. [i = 6] {same as doing  i = i + 3}

    q = &i;          // Line 6 ----> q points to i

    i = *p + *q;     // Line 7 ----> both p and q point to i, i = i + i. [i = 12] {same as doing i = i + i}

    printf("At line 8: i = %d\n", i); // Line 8

    q = &j;          // Line 9 ----> q points to j now

    i = *p + *q;     // Line 10 ----> p points to i, q points to j. i = i + j = 12 + 1. [i = 13] {same as doing i = i + j}

    printf("At line 11 i = %d\n", i); // Line 11

    p = &j;          // Line 12 ----> p points to j now too.

    i = *p + *q;     // Line 13 ----> both p and q point to j. i = j + j = 1 + 1. [i = 2] {same as doing i = j + j}

    printf("Final value of i = %d\n", i); // Line 14

}

int main() {

    tracePointers1();
    tracePointers2();

    return 0;
}
