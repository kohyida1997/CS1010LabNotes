#include <stdio.h>
#include <stdbool.h>
#include <math.h> // for abs()
#include <ctype.h> // Need this for isalpha() and tolower() functions
#include <stdlib.h> // for atoi()
#include <string.h> // Need this for strlen()

int main() {

    int x = 0;
    char temp[6];
    int y = 0;

    strcpy(temp, "1234567");

    printf("x is at = %p\n", &x);
    printf("y is at = %p\n", &y);

    printf("x is %d\n", x);
    printf("y is %d\n", y);

}