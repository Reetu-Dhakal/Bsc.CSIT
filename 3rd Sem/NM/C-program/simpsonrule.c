#include <stdio.h>

double f(double x) {
    return x * x;  
}

int main() {
    int n;
    double a, b;
    
    printf("Enter even number of subintervals: ");
    scanf("%d", &n);
    
    if (n % 2 != 0) {
        printf("Please enter an even number of subintervals.\n");
        return 1;
    }
    
    printf("Enter lower and upper limits: ");
    scanf("%lf %lf", &a, &b);
    
    double h = (b - a) / n;
    double s = f(a) + f(b);
    
    for (int i = 1; i < n; i += 2) {
        s += 4 * f(a + i * h);
    }
    
    for (int i = 2; i < n - 1; i += 2) {
        s += 2 * f(a + i * h);
    }
    
    printf("Integral: %.6f\n", (h / 3) * s);
    
    return 0;
}
