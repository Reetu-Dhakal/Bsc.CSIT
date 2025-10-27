#include <stdio.h>

void gauss_jordan(int n, double a[n][n], double b[n]) {
    for (int i = 0; i < n; i++) {
        double diag = a[i][i];
        for (int k = 0; k < n; k++) {
            a[i][k] /= diag;
        }
        b[i] /= diag;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double ratio = a[j][i];
                for (int k = 0; k < n; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
                b[j] -= ratio * b[i];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    double a[n][n], b[n];

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

    gauss_jordan(n, a, b);

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.6f\n", i + 1, b[i]);
    }

    return 0;
}
