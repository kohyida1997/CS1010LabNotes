#include <stdio.h>

int cashback(int X, int A, int B, int times) {

    if (times == 1) {
        return X * A + B;
    }

    return cashback(X, A, B, times - 1) * A + B;

}


int main() {

    int S, L, A, B;

    scanf("%d %d %d %d", &A, &B, &L, &S);

    printf("%d cents\n", cashback(L, A, B, S));

    return 0;
}
