#include <stdio.h>

void readRecords(float records[], int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        scanf(" %f", &records[i]);
    }
}

void swap(int idx1, int idx2, int arr[]) {
    float temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void sortIndex(int index[], float records[], int ranks[], int numRecords) {
    /* 
        Selection sort

        Intuition:
        - For each index, select the correct element to place at that index. (Imagine sorting cards in your hand)
    
    */
    for (int i = 0; i < numRecords; i++) {
        int indexOfMinPtr = i;
        int minPtr = index[indexOfMinPtr];
        for (int j = i + 1; j < numRecords; j++) {
            if (records[minPtr] > records[index[j]]) {
                // Set the new minimum
                indexOfMinPtr = j;
                minPtr = index[indexOfMinPtr];
            }
        }
        swap(i, indexOfMinPtr, index);
        ranks[minPtr] = i;
    }
}

void printResults(float records[], float copyOfRecords[], int ranks[], int numRecords) {

    for (int i = 0; i < numRecords; i++) {
        int idx = ranks[i];
        if (idx == 0) {
            printf("Gold ");
        }
        else if (idx == 1) {
            printf("Silver ");
        }
        else if (idx == 2) {
            printf("Bronze ");
        }
        else {
            printf("%d ", idx + 1);
        }
    }
    printf("\n");

}

int main() {

    int numRecords;
    float records[100];
    int index[100];
    int ranks[100];

    for (int i = 0; i < 100; i++)
        index[i] = i;

    scanf("%d", &numRecords);

    readRecords(records, numRecords);
    sortIndex(index, records, ranks, numRecords);
    printResults(records, records, ranks, numRecords);

    return 0;
}

/* 

Sorting the indices instead of sorting the actual elements. Small example:


Original Elements:
    [5, 4, 7, 2]

Original Indices:
    [0, 1, 2, 3]

------------------

Sorted Elements:
    [2, 4, 5, 7]

Sorted (based on the elements) Indices:
    [3, 1, 0, 2]


When sorting the indexes instead of the original elements,
the idea is to not mutate the ORIGINAL ELEMENTS. We also don't
need to make a copy of the ORIGINAL ELEMENTS, and should 
directly mutate the ORIGINAL INDICES array.

*/
