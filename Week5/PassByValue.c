#include <stdio.h>
int confuse(int, int, int);
int main(void)
{
    int a = 6, b = 2, c = 5;
    a = confuse(c, b, a); // confuse(5, 2, 6)

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
int confuse(int b, int a, int c)
{
    a = b + c;
    c = a * b;
    return c - a + b;
}