#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of data points: ");
    scanf("%d", &n);

    double *x = (double *)malloc(n * sizeof(double));
    double **y = (double **)malloc(n * sizeof(double *));
    
    printf("Enter x values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter y values:\n");
    for (int i = 0; i < n; i++) {
        y[i] = (double *)malloc(n * sizeof(double));
        printf("For x[%d]: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &y[i][j]);
        }
    }

    double h = x[1] - x[0];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    double u1 = y[0][1] / h;
    double u2 = (y[0][1] + (y[0][2] / 2)) / h;

    printf("First Derivative: %.6f\n", u1);
    printf("Second Derivative: %.6f\n", u2);

    for (int i = 0; i < n; i++) {
        free(y[i]);
    }
    free(y);
    free(x);

    return 0;
}
