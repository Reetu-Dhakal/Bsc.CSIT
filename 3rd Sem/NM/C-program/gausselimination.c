#include <stdio.h>

void gauss_elimination(int n, double a[n][n], double b[n], double x[n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = 0; k < n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
            b[j] -= ratio * b[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / a[i][i];
        for (int j = i - 1; j >= 0; j--) {
            b[j] -= a[j][i] * x[i];
        }
    }
}

int main() {
    int n;
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    double a[n][n], b[n], x[n];

    printf("Enter the coefficients row-wise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the constants: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    gauss_elimination(n, a, b, x);

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    return 0;
}
