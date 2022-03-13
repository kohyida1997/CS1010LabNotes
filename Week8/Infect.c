#include <stdio.h>


void swap(int idx1, int idx2, int arr[]) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void sortRecords(int infectionRate[], int severity[], int index[], int numRecords) {
    /* 
        Selection sort

        Intuition:
        - For each index, select the correct element to place at that index. (Imagine sorting cards in your hand)
    
    */
    for (int i = 0; i < numRecords; i++) {
        int minPtr = i;
        for (int j = i + 1; j < numRecords; j++) {
            if (severity[index[minPtr]] < severity[index[j]]) {
                minPtr = j;
            } 
            else if (severity[index[minPtr]] == severity[index[j]]) {
                if (infectionRate[index[minPtr]] < infectionRate[index[j]]) {
                    minPtr = j;
                }
                else if (infectionRate[index[minPtr]] == infectionRate[index[j]]) {
                    minPtr = index[j] < index[i] ? j : i;
                }
            }
        }
        swap(i, minPtr, index);
    }
}


void readRecords(int infectionRate[], int infectionRateCopy[], int severity[], int severityCopy[], int numRecords) {

    for (int i = 0; i < numRecords; i++) {
        scanf("%d", &infectionRate[i]);
        infectionRateCopy[i] = infectionRate[i];
    }

    for (int i = 0; i < numRecords; i++) {
        scanf("%d", &severity[i]);
        severityCopy[i] = severity[i];
    }

}

int main() {

    int numRecords = 6;
    int infectionRate[6];
    int infectionRateCopy[6];

    int severity[6];
    int severtiyCopy[6];

    int indexArr[] = {0, 1, 2, 3, 4, 5};

    readRecords(infectionRate, infectionRateCopy, severity, severtiyCopy, numRecords);

    sortRecords(infectionRateCopy, severtiyCopy, indexArr, numRecords);
    for (int i = 0; i < numRecords; i++) {
        printf("%d ", indexArr[i] + 1);
    }
    printf("\n");
    return 0;
}