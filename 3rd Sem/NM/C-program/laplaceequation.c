#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void laplace(int n, double tol) {
    // Dynamically allocate 2D array
    double **u = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        u[i] = (double *)malloc(n * sizeof(double));
    }

    // Initialize grid with boundary conditions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                u[i][j] = 100.0;
            else
                u[i][j] = 0.0;
        }
    }

    double err = tol + 1;
    int iter = 0;

    // Iterative solver (Jacobi method)
    while (err > tol) {
        err = 0.0;
        iter++;

        // Copy current grid to temp array
        double **u_new = (double **)malloc(n * sizeof(double *));
        for (int i = 0; i < n; i++) {
            u_new[i] = (double *)malloc(n * sizeof(double));
            for (int j = 0; j < n; j++) {
                u_new[i][j] = u[i][j];
            }
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                u_new[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]);
                err = fmax(err, fabs(u_new[i][j] - u[i][j]));
            }
        }

        // Swap pointers or copy back
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                u[i][j] = u_new[i][j];
            }
            free(u_new[i]);
        }
        free(u_new);
    }

    printf("\nConverged after %d iterations (error = %.6f)\n", iter, err);
    printf("Solution:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2f ", u[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(u[i]);
    }
    free(u);
}

int main() {
    int n;
    double tol;

    printf("Enter grid size: ");
    scanf("%d", &n);
    printf("Enter tolerance: ");
    scanf("%lf", &tol);

    laplace(n, tol);

    return 0;
}
