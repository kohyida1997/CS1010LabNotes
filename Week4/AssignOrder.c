#include <stdio.h>
#include <string.h>

int main() {
    
    /* Malicious code that corrupts the un-assigned variable "int i" and sets it to 1337*/
    // int x = 1337;
    // void *ptr = (void *) &x;
    // memcpy(ptr + 8, ptr, 4);

    // Dangerous code, variables not initialized.
    int i;
    float f;
    double d;    

    printf("i = %d; f = %f; d = %lf\n", i, f, d);
    return 0;
}


// int badAssignment();

// int badAssignment() {

//     // Will not compile
//     int a, b, c;
//     a = b + 2 = c + 1 = 5;

//     return 0;

// }

void mixedTypes();

void mixedTypes() {
    float a;
    int b;
    double c;
    a = b = c = 12.98;

    /* 
    
        What actually gets executed:

        c = 12.98;
        b = c; // b = 12 since b is declared INT
        a = b; // a = 12.0000 since b is declared FLOAT


    */
}

