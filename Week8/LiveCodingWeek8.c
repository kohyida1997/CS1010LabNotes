#include <stdio.h>
int main()
{
    int size;
    int max = 10000; /* Initialize Max (1 Mark) */
    int counter[10001]; /* Counter goes to 10001 not 10000 (1 Mark) */
    scanf("%d", &size);

    // initialise array elements to 0
    for (int i = 0; i <= max; i += 1) {
        counter[i] = 0; /* Initialize all elements inside counter (1 Mark) */
    }
    // counting
    for (int i = 0; i < size; i += 1) {
        int num;
        scanf("%d", &num); /* scanf needs to use &num not num (1 Mark) */
        if (num >= 0 && num <= max) {
            counter[num] += 1; /* Increase counter at num by 1 (1 Mark) */
        }
    }
    // output total count of each digit
    for (int i = 0; i <= max; i += 1) {
        if (counter[i] > 0) { /* Don't output if counter at that index is 0 (1 Mark) */
            printf("%d", i);
            printf(" ");
            printf("%d\n", counter[i]);
        }
    }
    // output sorted digits
    for (int i = 0; i <= max; i += 1) {
        if (counter[i] > 0) {
            for (int j = 0; j < counter[i]; j += 1) {
                printf("%d\n", i);
            }
        }
    }
}