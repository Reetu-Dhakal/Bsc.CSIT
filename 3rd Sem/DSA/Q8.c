#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    
    // Taking user input
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Checking for negative input
    if (num < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
        printf("Factorial of %d is %d\n", num, factorial(num));
    
    return 0;
}
