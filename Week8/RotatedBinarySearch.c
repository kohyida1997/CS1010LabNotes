#include <stdio.h>

int main() {
    return 0;
}


/* 

Binary search in a rotated array:

    [1, 2, 3, 4, 5]

    [5, 1, 2, 3, 4]

    [4, 5, 1, 2, 3]

Case 1:

    [4, 5, 1, 2, 3]

    MID = 1
    LEFT = 4
    RIGHT = 3

    RIGHT < LEFT
    MID < RIGHT
    
    -> search recursively in [LEFT, MID]

Case 2:

    [2, 3, 4, 5, 1]

    MID = 4
    LEFT = 2
    RIGHT = 1

    RIGHT < LEFT
    LEFT < MID
    -> search recursively in [MID, RIGHT]

CASE 3:

    [1, 2, 3, 4, 5]

    MID = 3
    LEFT = 1
    RIGHT = 5

    LEFT < RIGHT
    MID < RIGHT
    
    -> search recursively in [MID, RIGHT]

    For more information, do visit the original Leetcode question here:
    
    https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14425/Concise-O(log-N)-Binary-search-solution

*/