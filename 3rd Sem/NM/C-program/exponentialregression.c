#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    printf("Enter number of data points: ");
    scanf("%d", &n);

    double x[n], y[n], log_y[n], xy_sum = 0, x_square_sum = 0, x_sum = 0, log_y_sum = 0, b0, b1;

    printf("Enter x values: ");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter y values: ");
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
        log_y[i] = log(y[i]);
        xy_sum += x[i] * log_y[i];
        x_square_sum += x[i] * x[i];
        x_sum += x[i];
        log_y_sum += log_y[i];
    }

    b1 = (n * xy_sum - x_sum * log_y_sum) / (n * x_square_sum - x_sum * x_sum);
    b0 = (log_y_sum - b1 * x_sum) / n;

    printf("Exponential Regression Equation: y = e^(%.4f) * e^(%.4fx)\n", b0, b1);

    return 0;
}
