#include <stdio.h>

void divided_difference(int n, double x[], double y[]) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j] = (y[j] - y[j - 1]) / (x[j] - x[j - i]);
        }
    }
}

double newton_interpolation(int n, double x[], double y[], double xp) {
    double result = y[0];
    
    for (int i = 1; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < i; j++) {
            term *= (xp - x[j]);
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    
    printf("Enter x values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter y values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    double xp;
    printf("Enter the point to interpolate: ");
    scanf("%lf", &xp);

    divided_difference(n, x, y);
    
    double result = newton_interpolation(n, x, y, xp);
    
    printf("Interpolated value: %.6lf\n", result);

    return 0;
}
