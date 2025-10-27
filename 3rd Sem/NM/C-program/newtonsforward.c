#include <stdio.h>

// Function to compute forward difference table
void forward_difference_table(int n, double y[][n]) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[i][j] = y[i - 1][j + 1] - y[i - 1][j];
        }
    }
}

// Function to perform Newton's Forward Interpolation
double forward_difference_interpolation(int n, double x[], double y[][n], double xp) {
    double result = y[0][0]; 
    double h = x[1] - x[0];  // Step size
    double p = (xp - x[0]) / h; // Compute p value
    double fact = 1.0;

    // Apply the interpolation formula
    for (int i = 1; i < n; i++) {
        fact *= (p - (i - 1)) / i;
        result += fact * y[i][0];
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n][n]; // Table for forward differences

    printf("Enter x values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter y values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[0][i]); // First row is y values
    }

    double xp;
    printf("Enter the point to interpolate: ");
    scanf("%lf", &xp);

    // Compute forward difference table
    forward_difference_table(n, y);

    // Perform interpolation
    double result = forward_difference_interpolation(n, x, y, xp);

    printf("Interpolated value: %.6lf\n", result);

    return 0;
}
