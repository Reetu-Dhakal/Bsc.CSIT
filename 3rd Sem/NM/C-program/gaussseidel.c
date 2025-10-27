#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    printf("Enter matrix size: ");
    scanf("%d", &n);

    double **a = (double **)malloc(n * sizeof(double *));
    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));
    double *x_new = (double *)malloc(n * sizeof(double));
    double tol = 1e-6;

    for (int i = 0; i < n; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter matrix row-wise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter RHS values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        x[i] = 0; // Initial guess for solution
    }

    while (1) {
        for (int i = 0; i < n; i++) {
            double s = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    s += a[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - s) / a[i][i];
        }

        int converged = 1;
        for (int i = 0; i < n; i++) {
            if (fabs(x_new[i] - x[i]) >= tol) {
                converged = 0;
                break;
            }
        }

        if (converged) {
            break;
        }

        for (int i = 0; i < n; i++) {
            x[i] = x_new[i];
        }
    }

    printf("Solution: ");
    for (int i = 0; i < n; i++) {
        printf("%.6f ", x[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(b);
    free(x);
    free(x_new);

    return 0;
}
