#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    /* 
        The common term of both roots is:

        sqrt(b^2 - 4ac)

        As such, we can use a single variable to represent this value
        and reuse the variable when computing both roots. This saves
        you some typing, and reduces the chance of error.

    
    */
    float temp = sqrt(b * b - 4 * a * c);

    float root1 = (-b + temp) / (2 * a);
    float root2 = (-b - temp) / (2 * a);

    printf("%.4f\n", root1 + root2);
}