#include <stdio.h>

int main() {
    return 0;   
}


/* 

    The idea is to sort the integers. However, the criteria in which we sort them
    by is different from usual integer comparison.

    Example 1:
    
    [34, 5, 9] (Original Array)

    [9, 5, 34] (Sorted Array)

    Example 2:

    [34, 30, 3] (Original Array)

    [34, 3, 30] (Sorted Array)

    ============================================================================

    Sorting Rule/Comparator:

    b is "larger than" a

    If and Only If

    cat(b, a) > cat(a, b) -> ie. cat(34, 3) = 343, cat(3, 34) = 334

    ============================================================================

    Notice that when sorting, we always only use pairwise comparisons. As such,
    we simply need to implement our new sorting comparator pairwise. For more
    information, do visit the original Leetcode question here:

    https://leetcode.com/problems/largest-number/solution/

*/



