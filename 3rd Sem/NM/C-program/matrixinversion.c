#include <stdio.h>

void gauss_jordan_inverse(int n, double a[n][n], double inv[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < n; i++) {
        double pivot = a[i][i];
        for (int j = 0; j < n; j++) {
            a[i][j] /= pivot;
            inv[i][j] /= pivot;
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double ratio = a[j][i];
                for (int k = 0; k < n; k++) {
                    a[j][k] -= ratio * a[i][k];
                    inv[j][k] -= ratio * inv[i][k];
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of rows/columns of the matrix: ");
    scanf("%d", &n);

    double a[n][n], inv[n][n];

    printf("Enter the matrix row-wise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    gauss_jordan_inverse(n, a, inv);

    printf("Inverse Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.6f ", inv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
