#include <stdio.h>
#include <math.h> // MUST compile with -lm

double getTemperatureEstimate(int hour, int minutes);

int main() {

    int hour, minutes;

    printf("Please specify <hour minutes>, separated by a space:\n");
    scanf("%d %d", &hour, &minutes); // Remember the & ampersand symbol before the variable when using scanf !!!

    double estimate = getTemperatureEstimate(hour, minutes);

    printf("%.2lf\n", estimate); // Remember to leave a NEWLINE when printing output

    return 0;
}

double getTemperatureEstimate(int hour, int minutes) {
    
    double totalHours = hour + (minutes * 1.0) / 60; // This is equals to T 
    double numerator = 4 * pow(totalHours, 2);
    double denominator = totalHours + 2;

    return (numerator / denominator) - 20;
}