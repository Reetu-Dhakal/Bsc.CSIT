#include <stdio.h>

double f(double x) {
    return x * x;  // Function to be integrated, x^2 in this case
}

int main() {
    int n;
    double a, b;
    
    printf("Enter multiple of 3 for subintervals: ");
    scanf("%d", &n);
    
    if (n % 3 != 0) {
        printf("Please enter a multiple of 3 for subintervals.\n");
        return 1;
    }
    
    printf("Enter lower and upper limits: ");
    scanf("%lf %lf", &a, &b);
    
    double h = (b - a) / n;
    double s = f(a) + f(b);
    
    for (int i = 1; i < n; i += 3) {
        s += 3 * f(a + i * h);
    }
    
    for (int i = 2; i < n - 1; i += 3) {
        s += 3 * f(a + i * h);
    }
    
    for (int i = 3; i < n - 2; i += 3) {
        s += 2 * f(a + i * h);
    }
    
    printf("Integral: %.6f\n", (3 * h / 8) * s);
    
    return 0;
}
