#include <stdio.h> // io = "input/output". Need this for scanf/printf/fgets
#include <stdbool.h>
#include <math.h> // for abs()
#include <ctype.h> // Need this for isalpha() and tolower() functions
#include <stdlib.h> // for atoi()
#include <string.h> // Need this for strlen(), strcpy() and memcpy()

int main() {

    /* 
    
        To store "apple" -> 5 characters -> need char buffer[6]
        to account for the null character as well
    
    */

    char buffer[5 + 1] = {'\0'}; // Always good practice to initialize

    strcpy(buffer, "apple"); // OK

    //char buffer2[5] = {'\0'};
    //strcpy(buffer2, "mango"); // Risky, don't do it. Triggers a WARNING, can mess up other parts of the program

    buffer[0] = 'b';

    char *myApple = "apple"; // Constant READ-ONLY memory, do not try to modify this string. Note, it is also actually null-terminated

    printf("Buffer contains = %s\n", buffer); // this might fail to print as a result of buffer2
    //printf("Buffer2 contains = %s\n", buffer2);
    printf("myApple contains = %s\n", myApple);

    printf("Buffer addr = %p\n", buffer);
    //printf("Buffer2 addr = %p\n", buffer2);

    /*

    Throws an ERROR:
    myApple[0] = 'b'

    */


}