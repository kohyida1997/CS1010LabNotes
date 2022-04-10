#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAXSIZE 10
// Scans input value to array
void scanArray(int nums[], int numsSize){
    for (int i = 0; i < numsSize; i++) {// #1
        int temp = 0;
        scanf("%d", &temp);
        nums[i] = temp;
    }
}


// Find max value of the two given input
int max(int num1, int num2){
    if(num1>num2) {// #3
        return num1;
    }
    
    return num2;
}

// Identify Player 1's score - Player 2's score after a turn
// Recursively find maximum attainable score for Player 1
// (take into aspect of taking first and last element)
int winner(int nums[], int s, int e, int turn) {
    if (s == e) {// #4
        return turn * nums[s];
    }
    int a = turn * nums[s] + winner(nums, s + 1, e, -turn);
    int b = turn * nums[e] + winner(nums, s, e - 1, -turn);// #5,6
    return turn * max(turn * a, turn * b);
}

// Return true if Player 1 wins
// Player 1 wins when output of winner function is >= 0
bool predictTheWinner(int nums[], int numsSize) {
    return winner(nums, 0, numsSize - 1, 1) > 0;
}

int main() {
    int nums[MAXSIZE];
    int size;
    
    scanf("%d",&size);
    scanArray(nums, size);
    
    if(predictTheWinner(nums,size)) {
        printf("Player 1\n");
    } else {
        printf("Player 2\n");
    }
    return 0;
}
