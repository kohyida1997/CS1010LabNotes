#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n)
{
    for (int i = 2; i <= floor(sqrt(n)); ++i)
    {
        // if n is divisible by i, then n is not prime
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    // do isPrime checking for the range [x, y]
    for (int i = x <= 1 ? 2 : x; i <= y; i += 1)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}