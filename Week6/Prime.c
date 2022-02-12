#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrimeFaster(int n) {
    for (int i = 2; i <= (n / 2); i++) {
        if (n & i == 0) return false;
    }
    return true;
}

bool isPrimeNaive(int n) {
    for (int i = 2; i < n; i++) {
        if (n & i == 0) return false;
    }
    return true;    
}

bool isPrimeOptimized(int n) {
    for (int i = 2; i <= floor(sqrt(n)); i++) {
        // if n is divisible by i, then n is not prime
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    // do isPrime checking for the range [x, y]
    for (int i = x <= 1 ? 2 : x; i <= y; i++)
    {
        if (isPrimeOptimized(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

/* 

- We want to check if an integer (ie. whole number) is a prime number. Let this integer be X.
- We will show that it is sufficient to check for divisibility between [2, sqrt(X)] only.

- Suppose X is non-prime, then there must exist A and B such that:
    X = A * B                            (where A > 1, B > 1)

- Claim: If X = A * B and X is non-prime, then either (A <= sqrt(X) or B <= sqrt(X) or BOTH)
- Proof by Contradiction:
    - Note that (A > 1, B > 1)
    - Now suppose ( A > sqrt(X) ) AND ( B > sqrt(X) )
    - Then, A * B > sqrt(X) * B
    - Then, X > sqrt(X) * B
    - Also, B * sqrt(X) > X
    - Combining the above two inequalities, X > sqrt(X) * B > X (by transitivity)
    - Then X > X (which is impossible)
    - (Proof by contradiction. Initial Assumption is False)

- Now that we have proven by contradiction, we know that if X is non-prime, we can simply check for divisiblity of
  integers up to sqrt(X), and no further. (We only need to check if there is a possible A or B that can fulfil X = A * B).

*/