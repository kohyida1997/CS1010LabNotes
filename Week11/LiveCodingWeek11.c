#include <stdio.h>
#include <stdbool.h>

#define PUZZLE_SIZE 4

bool check(const int guess[], const int answer[]) {
    int marked[PUZZLE_SIZE];

    // make a copy of the array
    for (int i = 0; i < PUZZLE_SIZE; i += 1) {
        marked[i] = answer[i];
    }
    int same_color_same_pos = 0;
    int same_color_diff_pos = 0;
    // count number of pegs in correct position and correct color
    for (int i = 0; i < PUZZLE_SIZE; i += 1) {
        if (guess[i] == marked[i]) {
            same_color_same_pos += 1;
            marked[i] = 0;
        }
    }
    // count number of pegs in wrong position but correct color
    for (int i = 0; i < PUZZLE_SIZE; i += 1) { // go through each item in guess
        bool found = false;
        for (int j = 0; j < PUZZLE_SIZE; j += 1) { // try to match it
            if (guess[i] != answer[i] && guess[i] == marked[j]) {
                same_color_diff_pos += 1;
                marked[j] = 0;
                break;
            }
        }
    }
    printf("%d", same_color_same_pos);
    printf(" ");
    printf("%d\n", same_color_diff_pos);

    if (same_color_same_pos == PUZZLE_SIZE) {
        return true;
    }

    return false;
}
int main()
{
    int answer[PUZZLE_SIZE];
    for (int i = 0; i < PUZZLE_SIZE; i += 1) {
        scanf("%d", &answer[i]);
    }

    bool correct = false;
    // repeat until correct guess by codebreaker
    do {
        int guess[PUZZLE_SIZE];
        
        for (int i = 0; i < PUZZLE_SIZE; i += 1) {
            scanf("%d", &guess[i]);
        }

        correct = check(guess, answer);

    } while (!correct);

    return 0;
}
