#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;

    // Prompt the user to enter the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float num[n]; // Declare an array to store the numbers

    // Prompt the user to enter the numbers
    printf("Enter the %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &num[i]);
        sum += num[i]; // Accumulate the sum of the numbers
    }

    // Calculate the average
    average = sum / n;

    // Display the sum and average
    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", average);

    return 0; // Exit the program successfully
}
