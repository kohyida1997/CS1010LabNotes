#include <stdio.h>
#include <stdlib.h>

int look_and_say(int n) {
    int say = 0; /* Say was initialized wrongly (1 mark) */
    int curr = n % 100000000; // take last 8 digits
    int factor = 1;

    while (curr != 0) { // count how many times the last digit occurs
      int occurance_counter = 0; /* Initialize occurance counter (1 mark) */
      int last_digit = curr % 10; /* (% 10) not (% 100) to get last digit (1 mark) */
      
      while ((curr % 10) == last_digit) { /* While loop condition (1 mark) */
        occurance_counter++; /* Need to increase occurance counter (1 mark) */
        curr = curr / 10;
      }

      say = say + (occurance_counter * 10 + last_digit) * factor;
      factor *= 100; /* Multiply factor by 100 (1 mark) */

    }

    return say;
}

int main() {
    char line[20];
    line[19] = '\0';
    fgets(line, 20, stdin);
    
    int spaceIndex = 0;
    
    //find index of space to split input line
    for (int i = 0; i < 20; i+=1) {
        if (line[i] == ' ') { /* Use single quotes not double quotes (1 mark) */
            spaceIndex = i;
            break;
        }
    }
    
    //split the string
    char a[20];
    char b[20];
    for (int i = 0; i < spaceIndex; i+=1) {
        a[i] = line[i];
        a[i + 1] = '\0';
    }
    
    for (int i = 0; i < 20 - spaceIndex; i+=1) {
        b[i] = line[i + spaceIndex];
        b[i + 1] = '\0';
    }
    
    // convert split string to integer
    int n = atoi(a);
    int k = atoi(b);

    // loop k times to find k-th sequence
    int i = 0;
    while(i < k - 1) { /* Off by 1 error (1 mark) */
      n = look_and_say(n);
      i += 1;
    }
    printf("%d\n", n);
}
