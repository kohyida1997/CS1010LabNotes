#include <stdio.h>
#include <stdlib.h>

void merge(const int *l, int *ans, int n) {
    int i = 0; /* Initialize to 0. (1 mark) */

    int j = (int)n - 1;
    int k = 0;

    while (i <= j) { // compare starting from both ends
        if (l[i] < l[j]) { // fill the ans array
            ans[k] = l[i]; /* Assign (1 mark) */
            i++; /* Increment index i (1 mark) */
        }
        
        else {
            ans[k] = l[j]; /* Assign (1 mark) */
            j--; /* Decrease index j (1 mark) */
        }

        k += 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *l = calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    
    int *ans = calloc(n, sizeof(int));
    merge(l, ans, n);
    
    for (int i = 0; i < n; i += 1) {
        printf("%d", ans[i]);
        printf(" "); /* Need a space in between elements (1 mark) */
    }

    printf("\n");
}
