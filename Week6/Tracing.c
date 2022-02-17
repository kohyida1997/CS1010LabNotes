#include <stdio.h>


void powersOfTwo() {

    int i, sum = 0;
    for (i = 1; i < 1000; i *= 2) {
        sum += i;
    }

    /* 
    
    1 + 2 + 4 + 8 + ...... + 512

    111 -> 7 = 2^3 - 1
    1 + 2 + 4
 
    1111 -> 15 = 2^4 - 1
    1 + 2 + 4 + 8

    1111111111 -> 1023 = 2 ^ 10 -1

    = 1023
    
    */

   printf("PowersOfTwo: Sum = %d\n", sum);

}

void whileLoop() {

    int a = 10;
    int b = 200;

    while ((a * a) < (a + b)) {
        printf("WhileLoop: a = %d, b = %d\n", a, b);
        a++;
        b += 10;
    }

    /* 
    
    Trace manually.
    
    > a = 10, b = 200. ---> (100) < (220) TRUE
    > a = 11, b = 210. ---> (121) < (221) TRUE
    > a = 12, b = 220. ---> (144) < (232) TRUE
    > a = 13, b = 230. ---> (169) < (243) TRUE
    > a = 14, b = 240. ---> (196) < (254) TRUE
    > a = 15, b = 250. ---> (225) < (265) TRUE
    > a = 16, b = 260. ---> (256) < (276) TRUE
    > a = 17, b = 270. ---> (289) < (287) FALSE

    */

}

void doubleNestedForLoop() {
    int x, y, count = 0;
    
    for (x = 1; x <= 6; x++)
        for (y = x + 1; y <= 6; y++)
            count++;

    /* 
    
    When x = 1:
        count++ executed (y=2, y=3, y=4, y=5, y=6) -> 5 times
    When x = 2:
        count++ executed (y=3, y=4, y=5, y=6) -> 4 times
    When x = 3:
        .... 3 times
    When x = 4:
        .... 2 times
    When x = 5:
        .... 1 times
    When x = 6:
        .... 0 times

    Total: 5 + 4 + 3 + 2 + 1 = 15
    
    */

    printf("DoubleNestedForLoop: Count = %d\n", count);
}

void tripleNestedForLoop() {

    int x = 0;
    int y = 0;
    int z = 0;
    int count = 0;

    for (x = 1; x <= 5; x++) {
        for (y = x; y <= 5; y++) {
            for (z = x; z <= y; z++) {
                count++;
            }
        }
    }

    printf("TripleNestedForLoop: Count = %d\n", count);

    /* 
    
    When x = 1:
        y=1, y=2, .... y=5:
            when y = 1:
                [z=1, z=1] -> 1 time
            when y = 2:
                [z=1, z=2] -> 2 time
            ...
            in total when x = 1: 1 + 2 + 3 + 4 + 5

    When x = 2:
        y=2, .... y=5:
            when y = 2:
                [z=2, z=2] -> 1 time
            when y = 3:
                [z=2, z=3] -> 2 time
            ...
            in total when x = 2: 1 + 2 + 3 + 4
    ...

    Therefore it reduces to:

    (5 + 4 + ... + 1)   +   (4 + 3 + .... + 1)   +   (3 + 2 + ... + 1)   +   (2 + 1)   +   (1)
    = 15 + 10 + 6 + 3 + 1 = 35

    */

}

int main() {

    powersOfTwo();
    whileLoop();
    doubleNestedForLoop();
    tripleNestedForLoop();
    return 0;
}