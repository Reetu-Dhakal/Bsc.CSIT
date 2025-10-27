#include <stdio.h>

// Function to calculate factorial
float factorial(int n) {
    float fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to perform Newton's Forward Difference Interpolation
float forward_difference(float x[], float y[], int n, float xp) {
    float diff_table[n][n];

    // Initialize first column with y values
    for (int i = 0; i < n; i++)
        diff_table[i][0] = y[i];

    // Create forward difference table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            diff_table[j][i] = diff_table[j+1][i-1] - diff_table[j][i-1];
        }
    }

    // Print the forward difference table (optional)
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%8.4f ", diff_table[i][j]);
        }
        printf("\n");
    }

    float h = x[1] - x[0];
    float p = (xp - x[0]) / h;
    float result = y[0];
    float term = 1;

    for (int i = 1; i < n; i++) {
        term *= (p - (i - 1));
        result += (term * diff_table[0][i]) / factorial(i);
    }

    return result;
}

int main() {
    int n;
    float xp;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter x values: ");
    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values: ");
    for (int i = 0; i < n; i++)
        scanf("%f", &y[i]);

    printf("Enter the point to interpolate: ");
    scanf("%f", &xp);

    float yp = forward_difference(x, y, n, xp);
    printf("\nInterpolated value at %.2f is %.4f\n", xp, yp);

    return 0;
}
