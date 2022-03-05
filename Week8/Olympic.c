#include <stdio.h>

void readRecords(float records[], float copyOfRecords[], int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        scanf(" %f", &records[i]);
        copyOfRecords[i] = records[i];
    }
}

void swap(int idx1, int idx2, float arr[]) {
    float temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void sortCopyOfRecords(float copyOfRecords[], int numRecords) {
    /* 
        Selection sort

        Intuition:
        - For each index, select the correct element to place at that index. (Imagine sorting cards in your hand)
    
    */
    for (int i = 0; i < numRecords; i++) {
        float min = copyOfRecords[i];
        int minIdx = i;
        for (int j = i + 1; j < numRecords; j++) {
            if (copyOfRecords[j] < min) {
                // Set the new minimum
                min = copyOfRecords[j];
                minIdx = j;
            }
        }
        swap(i, minIdx, copyOfRecords);
    }
}

int findIndexOfThisRecord(float record, float sortedRecords[], int numRecords) {
    // Find the index of the record in the sorted array
    for (int i = 0; i < numRecords; i++) {
        if (record == sortedRecords[i]) return i;
    }

    return -1;

}

void printResults(float records[], float copyOfRecords[], int numRecords) {

    for (int i = 0; i < numRecords; i++) {
        int idx = findIndexOfThisRecord(records[i], copyOfRecords, numRecords);
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
    float copyOfRecords[100];

    scanf("%d", &numRecords);

    readRecords(records, copyOfRecords, numRecords);
    sortCopyOfRecords(copyOfRecords, numRecords);
    printResults(records, copyOfRecords, numRecords);

    return 0;
}
