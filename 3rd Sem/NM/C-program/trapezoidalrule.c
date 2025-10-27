#include <stdio.h>

double f(double x) {
    return x * x;
}

int main() {
    int n;
    double a, b;
    
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    
    printf("Enter lower and upper limit: ");
    scanf("%lf %lf", &a, &b);
    
    double h = (b - a) / n;
    double s = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        s += 2 * f(a + i * h);
    }
    
    printf("Integral: %.6f\n", (h / 2) * s);
    
    return 0;
}
