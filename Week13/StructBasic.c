#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
    The struct tag is used to tell the compiler that we are defining our own datatype
*/
struct IntPair {
    // Member variables
    int x;
    int y;
};


/* 
    typedef basically assigns an alias or 'nickname' to a datatype 
    Here, we defined 'Score' to be the nickname of datatype (unsigned int)
*/
typedef unsigned int Score;


/* 
    We can then use typedef and struct together. We defined a custom datatype with a tag called "Student" and
    also gave it a nickname "Student"
*/
typedef struct Student {
    // Member variables
    unsigned int id;
    Score score; // score is actually an int (we are using the nickname)
} Student;


/* 
    Using the same struct datatype defined, we can assign different nicknames to it too.
*/
typedef struct Student Alumni;

// However

/* 
    Allocates a new student in Heap memory. Returns a pointer.

    **NOTE: When dealing with pointers, we use ' -> ' operator to
    refer to the member variables.
*/
Student* getRandomStudentOnHeap() {
    Student *s = malloc(sizeof(Student));
    s->id = rand() % 999 + 1;
    (*s).score = rand() % 100 + 1; // ' -> ' is actually short-form of ' (*x) '
    return s; 
}

/* 
    Takes in (by value aka. makes a copy) of a student object

    **NOTE: When dealing with structs that are not pointers, we use ' . ' dot operator
    to refer to the member variables
*/
void printStudent(Student s) {
    printf("Address of Student in printStudent() function = %p\n", &s);
    printf("Print Student (pass by value aka. copy of student): Student[id=%d, score=%d]\n", s.id, s.score);
}

int main() {
    srand(56);

    Student *studentInHeap = getRandomStudentOnHeap();
    printf("Student allocated on the heap: Student[id=%d, score=%d]\n", studentInHeap->id, studentInHeap->score);
    free(studentInHeap);

    /* ========================================================================================================== */

    Student studentOnStack;
    studentOnStack.id = rand() % 999 + 1;
    studentOnStack.score = rand() % 100 + 1;
    printf("\nAddress of Student in main() function = %p\n", &studentOnStack);
    printStudent(studentOnStack);

    /* ========================================================================================================== */

    Alumni *alumni = getRandomStudentOnHeap(); // The underlying datatype of Alumni is a student, so we can assign a student to the Alumni nickname
    printf("\nAlumni allocated on the heap: Alumni[id=%d, score=%d]\n", alumni->id, alumni->score);
    free(alumni);

    /* ========================================================================================================== */
    // If we don't use typedef with struct, we basically are not giving a nickname to a struct.
    // As such, we need to reuse the "struct" keyword when we want to define structs.
    struct IntPair p;
    p.x = 5;
    p.y = 6;
    printf("\nIntPair allocated in the stack: IntPair[x=%d, y=%d]\n", p.x, p.y);

    // This is not allowed, as Alumni is a nickname, not a datatype
    // struct Alumni c; WILL NOT COMPILE ***
    struct Student ss; // OK, Student is both a nickname AND datatype

    /* ========================================================================================================== */

    // We can assign a variable to be another if their underlying datatypes match.
    Alumni a;
    Alumni b;
    a.id = 22; a.score = 22;
    b.id = 99; b.score = 99;

    printf("\nAlumni a initially: Alumni[id=%d, score=%d]\n", a.id, a.score);
    a = b;
    printf("Alumni a is now: Alumni[id=%d, score=%d]\n", a.id, a.score);

    // However, this is NOT allowed as the underlying datatypes do NOT match
    // a = p; DOES NOT COMPILE ***

    putchar('\n');

    /* ========================================================================================================== */

    // We can create arrays of students as well
    Student class[6];
    for (int i = 0; i < 6; i++) {
        class[i].id = rand() % 20 + 1;
        class[i].score = 100 - (rand() % 30 + 1);
        printf("Class: Student %d = [id=%d, score=%d]\n", i, class[i].id, class[i].score); 
    }

    return 0;

    /* 
    
    ** IMPORTANT **

    Please read up more about structs, naming structs, and using with typedef!
    https://stackoverflow.com/questions/17720223/c-typedef-struct-name-vs-typedef-struct-name

    */

}
