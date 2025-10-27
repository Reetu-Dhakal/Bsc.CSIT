#include <stdio.h>

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

    double h = x[1] - x[0];

    double fwd_diff = (-3*y[0] + 4*y[1] - y[2]) / (2*h);
    
    double bwd_diff = (3*y[n-1] - 4*y[n-2] + y[n-3]) / (2*h);

    printf("Forward Difference: %.6f\n", fwd_diff);
    printf("Backward Difference: %.6f\n", bwd_diff);

    return 0;
}

