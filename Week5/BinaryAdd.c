#include <stdio.h>

/***
Thought Process:
"If you can solve it by hand, you can solve it with computer"
So, to add 2 binary number you need to add each digit and pay attention at the carry.
Carry as the name suggested will be carried forward to the next addition.
To extract each digit, we can use last week's method except we can use function
so that our code becomes neater.
Explain the power of function (modularity, code once use anywhere, easier debug).
***/

/* 

    Modularizing helps you reduce the chances of messing up!

    - Instead of risking errors from typing the same idea multiple times, abstract
      it into a single function. You are less likely to make mistakes this way!

    - In the event when something is wrong with your function, you only have a SINGLE
      function to make modifications/changes in. This will greatly help with debugging
      and fixing code.

*/

int getLastDigit(int num) {
    return num % 10;
}

int getMiddleDigit(int num) {
    return (num % 100) / 10;
}

int getFirstDigit(int num) {
    return (num % 1000) / 100;
}

int main() {

    /* 
    
    Binary (base 2) addition is similar to normal (base 10) addition you have learnt in primary/elementary school.

         349
        +535

    -> Add digit by digit, starting from the right most digits.
    -> If a sum exceeds 10, we "carry over" the excess value to the next operations
    -> How can we extract the "carry"?
    -> Take for example -> (9 + 5) = 14
    -> The carry is 1. The carry is extracted by performing (9 + 5) / 10 since we are adding in base 10.
    -> How do we extract the new digit that should be at the one's place?
    -> Take for example again -> (9 + 5) = 14
    -> The new digit is 4. The new digit is extracted by performing (9 + 5) % 10 since we are in base 10.


         101
        +111  
    
    -> Adding in binary is extremely similar to adding in base 10. Except, instead of using "10" for the operations,
       we use the "2" (since it is in binary).

    -> Add first digits:
        Carry -> (1 + 1) / 2. Carry is 1.
        New Digit -> (1 + 1) % 2. New digit is 0

    -> Add second digits:
        * Take note that we need to add in the "carry" that was due to the addition of the first digits as well.
        Carry -> (0 + 1 + 1) / 2. Carry is 1
        New Digit -> (0 + 1 + 1) % 2. New digit is 0

    ... and so on for the rest of the digits.

    
    */

    int number1, number2;

    scanf("%d%d", &number1, &number2);

    int carry = 0;
    int last = getLastDigit(number1) + getLastDigit(number2) + carry;
    carry = last / 2;
    last = last % 2;

    int middle = getMiddleDigit(number1) + getMiddleDigit(number2) + carry;
    carry = middle / 2;
    middle = middle % 2;

    int first = getFirstDigit(number1) + getFirstDigit(number2) + carry;
    carry = first / 2;
    first = first % 2;

    // Note that while we are adding 3-digit binary numbers, the final sum may be a 4-digit binary number.
    // This happens in normal decimal addition as well. Eg. 53 + 47 = 100. (From 2-digit decimal numbers to 3-digit decimal number sum)
    printf("%d%d%d%d\n", carry, first, middle, last);

    return 0;
}