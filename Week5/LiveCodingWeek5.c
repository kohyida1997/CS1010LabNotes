#include<stdio.h>

// Print suffix of a given number
void print_suffix(int number) // change return type from int to void OR return some dummy int value (1 mark)
{
    printf("%d", number);
    int last_digit = number % 10; // last digit is modulo 10 not modulo 100 (1 mark)
    int penultimate_digit = (number / 10) % 10;
    // Evaluate what to print based on the last and penultimate digit
    (last_digit == 1 && penultimate_digit != 1 && printf("st")) ||
    (last_digit == 2 && penultimate_digit != 1 && printf("nd")) || // last digit == 2, "nd" (2 marks)
    (last_digit == 3 && penultimate_digit != 1 && printf("rd")) || // last digit == 3, "nd" (2 marks)
    printf("th");
    printf("\n");
}

int main()
{
    int number;
    scanf("%d", &number); // &number not number (1 mark)
    print_suffix(number);
}

/* 

Common mistakes:

1. Return value of function
    - If a function does not return anything, we should NOT use an "int" return value. Instead, we should
      use "void" return value.
    
2. Matching multiple values
    - "last_digit == 3 || 4" does not mean "if last_digit is equal to 3 OR 4"
    - Instead, it should be written as "last_digit == 3 || last_digit == 4"


*/