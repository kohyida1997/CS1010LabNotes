#include <stdio.h>
#include <stdlib.h>

int recurse2(int n) {
    if (n < 3) {
        printf("Base Case: Returning recurse2(%d) = %d\n", n, n + 1);
        return n + 1;
    }
    
    printf("Computing... recurse2(%d)\n", n);
    int tempRes1 = recurse2(n - 3);
    int tempRes2 = recurse2(n - 1);
    printf("Finish: Returning recurse(%d) = %d + %d = %d\n", n, tempRes1, tempRes2, tempRes1 + tempRes2);
    return tempRes1 + tempRes2;
}

int recurse2Optimized(int n, int *cache) {
    // Already computed this result before, no need to recompute
    if (cache[n] != -1) {
        printf("Already computed: recurse2(%d)\n", n);
        return cache[n];
    }
    
    if (n < 3) {
        printf("Base Case: Returning recurse2(%d) = %d\n", n, n + 1);
        cache[n] = n + 1;
        return n + 1;
    }
    
    printf("Computing... recurse2(%d)\n", n);
    int tempRes1 = recurse2Optimized(n - 3, cache);
    int tempRes2 = recurse2Optimized(n - 1, cache);
    printf("Finish: Returning recurse(%d) = %d + %d = %d\n", n, tempRes1, tempRes2, tempRes1 + tempRes2);
    cache[n] = tempRes1 + tempRes2;
    return tempRes1 + tempRes2;
}

int main() {
    printf("===== Tracing function recurse2() =====\n");
    recurse2(12);
    putchar('\n');

    printf("===== Tracing function recurse2Optimized() =====\n");
    int N = 12;
    int *cache = malloc(sizeof(int) * (N + 1));
    
    for (int i = 0; i < (N + 1); i++) cache[i] = -1;

    recurse2Optimized(N, cache);
    putchar('\n');
    free(cache);
    return 0;
}