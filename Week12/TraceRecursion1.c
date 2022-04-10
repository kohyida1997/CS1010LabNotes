#include <stdio.h>
#include <stdlib.h>

int recurse1(int x) {
    if (x == 0) {
        printf("Base Case: Returning 0\n");
        return 0;
    }

    printf("Computing... recurse(%d)\n", x);
    int temp = recurse1(x - 1);
    int res = 2 * x + temp;
    printf("Finish: Returning recurse(%d) = 2 * %d + %d = %d\n", x, x, temp, res);
    return res;
}

int main() {
    printf("===== Tracing function recurse1() =====\n");
    recurse1(5);
    putchar('\n');

    return 0;
}
