#include <stdio.h>
#include <stdbool.h>

void noShortCircuit();
void shortCircuit();

int main() {

    noShortCircuit();
    putchar('\n');
    shortCircuit();
    return 0;

}

void noShortCircuit() {

    printf("======== No Short Circuit ========\n");

    /* 
        1 Represents TRUE in C 
        So testTrue represents TRUE.    
    */
    int testTrue = 1; 

    int var = testTrue && printf("True. I am printed and assigned to \"var\"\n");

    testTrue && printf("True. I am printed but not assigned\n");

    printf("\"var\" is True and equals to %d\n", var);

}

void shortCircuit() {

    printf("======== Short Circuit ========\n");

    /* 
        1 Represents TRUE in C. 
        So !testTrue represents FALSE, testTrue represents TRUE.
        
    */
    int testTrue = 1; // !testTrue = 0

    /* 

        Notice that the printf() statement is not executed.
        This is because !testTrue is already false and thus, the entire statement is false. 
        As such, the program avoids evaluating the printf() as it does not change the result of
        the entire statement.

        Remember:
        False && False => False AND False  equals to FALSE
        False && True => False AND True  equals to FALSE
        
        0 && 0 => False AND False  equals to FALSE
        0 && 1 => False AND True equals to FALSE
    
    */    
    int foo = !testTrue && printf("False. I am not printed and assigned to \"foo\"\n");

    !testTrue && printf("False. I am not printed and assigned to \"foo\"\n");

    printf("\"foo\" is False and equals to %d\n", foo);

}