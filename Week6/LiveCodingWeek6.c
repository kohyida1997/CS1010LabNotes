#include <stdio.h>
void createReport(int numStudent)
{
    int mark;
    int sum = 0; // Initialize sum (1 mark)
    int min = 100; // Initialize min (1 mark)
    int max = 0; // Move max outside of for loop (1 mark)
    for (int i = 0; i < numStudent; i++) // termination condition for numStudent should be "i < numStudent" not "i <= numStudent" (1 mark)
    {
        scanf("%d", &mark);
        sum += mark;
        if (mark > max)
        {
            max = mark; // Set current mark to be max if it is larger than current max (1 mark)
        }
        if (mark < min) // Conditional to set min (1 mark)
        {
            min = mark; // Set current mark to be min if it is smaller than current min (1 mark)
        }
    }
    float avg = sum / (float)numStudent;
    printf("%.2f %d %d\n", avg, max, min);
}
int main()
{
    int numStudent;
    scanf("%d", &numStudent);
    createReport(numStudent);
}

/* 

Common mistakes:

1. Termination condition of for-loop
    - Be very careful with the starting/ending index of for loops:
      > "for (int i = 0; i <= 3; i++)" <- this loop runs FOUR TIMES, i=0 ... i=3
      > "for (int i = 0; i < 3; i++)" <- this loop runs THREE times, i=0 ... i=2
      > "for (int i = 1; i <=3; i++)" <- this loops runs THREE times, i=1 ... i=3

2. Initialization of variables is very important.
    - If we want to find the MAX across all variables, we should initialize MAX to be a small number first!
    - If we want to find the MIN across all variables, we should initialize MIN to be a large number first!

3. Declaration location of variables
    - Many students re-declared the variables within the for-loops. This shouldn't be the case! Declaring
      variables within in the loop restricts the variable to each iteration of the loop.
      > Eg.
        for (int i = 0; i < numStudent; i++) {
            int sum = 0; // THIS SUM IS A DIFFERENT VARIABLE IN EACH iteration (i=0, i=1, i=2 ....)
        }

*/