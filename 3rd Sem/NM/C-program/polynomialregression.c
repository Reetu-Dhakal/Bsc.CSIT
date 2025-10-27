#include <stdio.h>
#include <math.h>

void mat_mult(int r1, int c1, int c2, double A[r1][c1], double B[c1][c2], double result[r1][c2]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transpose(int r, int c, double M[r][c], double Mt[c][r]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            Mt[j][i] = M[i][j];
        }
    }
}

void inverse(int n, double M[n][n], double Inv[n][n]) {
    double Aug[n][2 * n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Aug[i][j] = M[i][j];
            Aug[i][j + n] = (i == j) ? 1 : 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (Aug[i][i] == 0) {
            for (int j = i + 1; j < n; j++) {
                if (Aug[j][i] != 0) {
                    for (int k = 0; k < 2 * n; k++) {
                        double temp = Aug[i][k];
                        Aug[i][k] = Aug[j][k];
                        Aug[j][k] = temp;
                    }
                    break;
                }
            }
        }

        double diag = Aug[i][i];
        for (int j = 0; j < 2 * n; j++) {
            Aug[i][j] /= diag;
        }

        for (int j = 0; j < n; j++) {
            if (j != i) {
                double factor = Aug[j][i];
                for (int k = 0; k < 2 * n; k++) {
                    Aug[j][k] -= Aug[i][k] * factor;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Inv[i][j] = Aug[i][j + n];
        }
    }
}

void poly_regression(int n, double x[], double y[], int degree, double coeff[]) {
    double X[n][degree + 1], Xt[degree + 1][n], XtX[degree + 1][degree + 1];
    double XtX_inv[degree + 1][degree + 1], XtY[degree + 1][1], B[degree + 1][1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= degree; j++) {
            X[i][j] = pow(x[i], j);
        }
    }

    transpose(n, degree + 1, X, Xt);
    mat_mult(degree + 1, n, degree + 1, Xt, X, XtX);
    inverse(degree + 1, XtX, XtX_inv);

    for (int i = 0; i <= degree; i++) {
        XtY[i][0] = 0;
        for (int j = 0; j < n; j++) {
            XtY[i][0] += Xt[i][j] * y[j];
        }
    }

    mat_mult(degree + 1, degree + 1, 1, XtX_inv, XtY, B);

    for (int i = 0; i <= degree; i++) {
        coeff[i] = B[i][0];
    }
}

int main() {
    int degree, n;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n], coeff[degree + 1];

    printf("Enter the x values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter the y values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    poly_regression(n, x, y, degree, coeff);

    printf("Polynomial Regression Equation: ");
    for (int i = 0; i <= degree; i++) {
        if (i == 0) {
            printf("%.6f", coeff[i]);
        } else {
            printf(" + %.6fx^%d", coeff[i], i);
        }
    }
    printf("\n");

    return 0;
}
