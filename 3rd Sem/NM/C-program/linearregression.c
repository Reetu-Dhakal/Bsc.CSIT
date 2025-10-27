#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter x values (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter y values (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    double x_mean = 0, y_mean = 0;
    for (int i = 0; i < n; i++) {
        x_mean += x[i];
        y_mean += y[i];
    }

    x_mean /= n;
    y_mean /= n;

    double xy_sum = 0, xx_sum = 0;
    for (int i = 0; i < n; i++) {
        xy_sum += x[i] * y[i];
        xx_sum += x[i] * x[i];
    }

    double b1 = (xy_sum - n * x_mean * y_mean) / (xx_sum - n * x_mean * x_mean);
    double b0 = y_mean - b1 * x_mean;

    printf("Linear Regression Equation: y = %.6lf + %.6lfx\n", b0, b1);

    return 0;
}
