#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    int score;
} Student;

void swap(int i, int j, Student* arr) {

    Student temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {

    Student students[6];
    srand(time(NULL)); // don't worry about this, just initializing some randomness

    for (int i = 0; i < 6; i++) {
        students[i].id = i;
        students[i].score = 100 - rand() % 100; // assign a random score to this student.
    }

    printf("== Unsorted Students ==\n");
    for (int i = 0; i < 6; i++) {
        printf("Student %d = [id=%d, score=%d]\n", i, students[i].id, students[i].score);
    }

    /* Sort students in ascending order by score */
    for (int i = 0; i < 6; i++) {
        int minIdx = i;
        for (int j = i + 1; j < 6; j++) {
            if (students[j].score < students[minIdx].score) { // compare the students by their score. you can compare by other things too!
                minIdx = j;
            }
        }
        swap(i, minIdx, students);
    }

    printf("== Sorted Students ==\n");
    for (int i = 0; i < 6; i++) {
        printf("Student %d = [id=%d, score=%d]\n", i, students[i].id, students[i].score);
    }

    return 0;
}

