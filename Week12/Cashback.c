#include <stdio.h>

int cashback(int L, int A, int B, int times) {

    if (times == 1) {
        return L * A + B;
    }

    return cashback(L, A, B, times - 1) * A + B;

}


int main() {

    int S, L, A, B;

    scanf("%d %d %d %d", &A, &B, &L, &S);

    printf("%d cents\n", cashback(L, A, B, S));

    return 0;
}
