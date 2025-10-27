#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x;  // Function to be integrated, x^2 in this case
}

double gauss_integration(int n, double a, double b) {
    double x[2] = {-1 / sqrt(3), 1 / sqrt(3)};
    double w[2] = {1, 1};
    
    if (n != 2) {
        printf("Only n=2 is supported here\n");
        return -1;
    }
    
    double c1 = (b - a) / 2;
    double c2 = (b + a) / 2;
    double integral = 0;
    
    for (int i = 0; i < n; i++) {
        integral += w[i] * f(c1 * x[i] + c2);
    }
    
    return c1 * integral;
}

int main() {
    double a, b;
    
    printf("Enter lower and upper limits: ");
    scanf("%lf %lf", &a, &b);
    
    int n = 2;
    double result = gauss_integration(n, a, b);
    
    printf("Integral: %.6f\n", result);
    
    return 0;
}
