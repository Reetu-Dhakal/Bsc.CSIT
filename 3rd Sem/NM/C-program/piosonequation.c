#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void poisson_eqn(double **f, double **phi, int rows, int cols, double dx, double dy, int max_iter, double tol) {
    double **phi_new = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        phi_new[i] = (double *)malloc(cols * sizeof(double));
    }

    double dx2 = dx * dx;
    double dy2 = dy * dy;
    double denom = 2.0 * (dx2 + dy2);

    for (int iter = 0; iter < max_iter; iter++) {
        double err = 0.0;

        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                phi_new[i][j] = ((phi[i+1][j] + phi[i-1][j]) * dy2 +
                                 (phi[i][j+1] + phi[i][j-1]) * dx2 -
                                 f[i][j] * dx2 * dy2) / denom;

                err = fmax(err, fabs(phi_new[i][j] - phi[i][j]));
            }
        }

        // Check for convergence
        if (err < tol) {
            printf("Converged after %d iterations with error %.6f\n", iter + 1, err);
            break;
        }

        // Copy new solution to phi
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                phi[i][j] = phi_new[i][j];
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        free(phi_new[i]);
    }
    free(phi_new);
}

void get_user_input(double ***f, double *dx, double *dy, int *rows, int *cols) {
    printf("Enter the number of rows: ");
    scanf("%d", rows);
    printf("Enter the number of columns: ");
    scanf("%d", cols);

    printf("Enter grid spacing in x direction (dx): ");
    scanf("%lf", dx);
    printf("Enter grid spacing in y direction (dy): ");
    scanf("%lf", dy);

    *f = (double **)malloc(*rows * sizeof(double *));
    for (int i = 0; i < *rows; i++) {
        (*f)[i] = (double *)malloc(*cols * sizeof(double));
        printf("Enter values for row %d: ", i + 1);
        for (int j = 0; j < *cols; j++) {
            scanf("%lf", &(*f)[i][j]);
        }
    }
}

int main() {
    int rows, cols;
    double dx, dy;
    double **f = NULL;

    get_user_input(&f, &dx, &dy, &rows, &cols);

    // Allocate and initialize phi to 0
    double **phi = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        phi[i] = (double *)calloc(cols, sizeof(double));
    }

    poisson_eqn(f, phi, rows, cols, dx, dy, 10000, 1e-6);

    printf("\nSolution to Poisson's Equation:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.4f ", phi[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(f[i]);
        free(phi[i]);
    }
    free(f);
    free(phi);

    return 0;
}