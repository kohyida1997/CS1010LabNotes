#include <stdio.h>
void generateFibo(int N, int fibo[]) /* Function signature should take in fibo[] (an array) (1 mark)*/
{
    fibo[0] = 0; /* Initialize 0th item to be 0 (1 mark)*/
    fibo[1] = 1; /* Initialize 1st item to be 1 (1 mark) */
    for (int i = 2; i < N; i++) /* For loop must start from i = 2 through i = N - 1. (1 mark)*/
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2]; /* Apply the formula for computing Fibonacci numbers (1 mark) */
    }
}
void printFibo(int N, int fibo[]) /* Again, function signature needs to take in fibo[] (an integer array) (1 mark) */
{
    for (int i = N - 1; i >= 0; i--) /* Iterate from the back of the array when printing. (1 mark)*/
    {
        printf("%d ", fibo[i]);
    }
    printf("\n");
}
int main()
{
    int N;
    scanf("%d", &N);
    int fibo[40];
    generateFibo(N, fibo);
    printFibo(N, fibo);
}
