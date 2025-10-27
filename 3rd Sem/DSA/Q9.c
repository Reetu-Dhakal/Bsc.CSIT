#include <stdio.h>

// Recursive function to calculate Fibonacci series
int fibo(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int num, i;
    
    // Taking user input
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    
    printf("Fibonacci series: ");
    for (i = 0; i < num; i++) {
        printf("%d ", fibo(i));
    }
    
    printf("\n");
    return 0;
}
