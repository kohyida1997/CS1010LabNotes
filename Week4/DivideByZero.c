#include <stdio.h>

int main() {

    float num1, num2, num3;

    /* User enters to real numbers. */
    printf("Enter two real numbers: ");
    scanf("%f %f", &num1, &num2);
    num3 = 0.0;

    /* 
        Num3 = (num1/num2) * num2

        What is the expected output? 
        (Simplify the above equation)
    
    */
    num3 = (num1 / num2) * num2;
    printf("num3 = %f\n", num3);

    /* What if num1 is 443.131? */
    // printf("num3 = %.3f\n", num3);
    return 0;
}