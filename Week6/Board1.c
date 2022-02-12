/***
Thought Process:
1. Understand:
Print 8x8 chessboard with alternate sequence (blank) and (star) bordered by (hash)
2. Plan:
Calculate the borderLength, this will be the limit for the iterator on our double for loop
Create a function which checks if a given coordinate is a border, if yes print hash
Other than that print star and blank in alternate fashion
Compute
3. Solve:
Compute borderLength, to get the formula look at pattern if n =1 , n=2, n= 3, ...
Create isBorder function which checks if the current coordinate is a border, again, pattern matching
Create 2 functions that check if we should print blank or star.
Pattern matching for star in valid odd-row square:
notice that for n = 2, we shall print start when row is 1 2 4 5 7 8, same for column
n = 3, row 1 2 3 5 6 7 9 10 11, same for column
To get the sequence, 1 2 4 5 7 8, we can use modulo as this is repeated 1 to 4 to 7 (+3 which is n+1)
1 2 3 5 6 7 9 10 11, 1 to 5 to 9 (+4 which is n+1)
Similar logic applies for pattern matching when the square is valid even-row square
4. Check:
Run and check against the test cases
***/
#include <stdio.h>
#include <stdbool.h>
bool isBorder(int pos, int n)
{
    return pos % (n + 1) == 0;
}
void fill(char c, int n)
{
    for (int k = 0; k < n; k++)
    {
        printf("%c", c);
    }
}
bool isValidEvenSquare(int row, int col, int n)
{
    if (row % (n * 2 + 2) >= 1 + (n + 1) && row % (n * 2 + 2) <= n + (n + 1))
    {
        if (col % (n * 2 + 2) >= 1 + (n + 1) && col % (n * 2 + 2) <= n + (n + 1))
        {
            return true;
        }
    }
    return false;
}
bool isValidOddSquare(int row, int col, int n)
{
    if (row % (n * 2 + 2) >= 1 && row % (n * 2 + 2) <= n)
    {
        if (col % (n * 2 + 2) >= 1 && col % (n * 2 + 2) <= n)
        {
            return true;
        }
    }
    return false;
}
void printSquare(int row, int col, int n)
{
    if (isValidOddSquare(row, col, n) || isValidEvenSquare(row, col, n))
    {
        fill('*', n);
    }
    else
    {
        fill(' ', n);
    }
}
void printBoard(int n)
{
    int borderLength = 9 + 8 * n;
    for (int row = 0; row < borderLength; row++)
    {
        for (int col = 0; col < borderLength; col++)
        {
            if (!isBorder(row, n) && !isBorder(col, n))
            {
                printSquare(row, col, n);
                col += (n - 1);
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printBoard(n);
    return 0;
}