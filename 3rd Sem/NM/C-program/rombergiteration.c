#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x;  // Function to integrate: f(x) = x^2
}

double romberg_integration(double a, double b, double tol) {
    double R[20][20];  // Romberg table
    int k = 0;         // Row index
    int n = 1;         // Number of intervals

    // First trapezoidal approximation
    R[0][0] = 0.5 * (b - a) * (f(a) + f(b));

    while (1) {
        k++;
        n *= 2;
        double h = (b - a) / n;
        double sum = 0.0;

        // Compute trapezoidal rule by adding midpoints
        for (int i = 1; i < n; i += 2) {
            sum += f(a + i * h);
        }

        R[k][0] = 0.5 * R[k - 1][0] + h * sum;

        // Richardson extrapolation
        for (int j = 1; j <= k; j++) {
            R[k][j] = (pow(4, j) * R[k][j - 1] - R[k - 1][j - 1]) / (pow(4, j) - 1);
        }

        // Check convergence
        if (fabs(R[k][k] - R[k - 1][k - 1]) < tol) {
            return R[k][k];
        }
    }
}

int main() {
    double a, b;
    printf("Enter lower and upper limits: ");
    scanf("%lf %lf", &a, &b);

    double tol = 1e-6;
    double result = romberg_integration(a, b, tol);

    printf("Integral: %.6f\n", result);
    return 0;
}
