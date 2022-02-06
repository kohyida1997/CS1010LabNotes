#include <stdio.h>

int main() {

    float num1, num2, num3;

    /* User enters to real numbers. */
    printf("Enter two real numbers: ");
    scanf("%f %f", &num1, &num2);
    num3 = 0.0;

    /* 
        Num3 = (num1/num2) * num2
        Num3 = num1

        What is the expected output? 
        (Simplify the above equation)
    
    */
   if (num2 == 0) {
       printf("BAD INPUT!!\n");
       return 1;
   }

    num3 = (num1 / num2) * num2;
    printf("num3 = %.2f\n", num3);

    /* What if num1 is 443.131? */
    // printf("num3 = %.3f\n", num3);
    return 0;
}