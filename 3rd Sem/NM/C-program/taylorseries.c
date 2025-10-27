#include <stdio.h>

double f(double x, double y) {
    return y - x * x + 1;  // Function f(x, y) = y - x^2 + 1
}

void taylor_series_method(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;
    printf("x = %.6f, y = %.6f\n", x, y);

    for (int i = 1; i <= n; i++) {
        double y_prime = f(x, y);
        double y_double_prime = f(x + h, y + h * y_prime);
        y += h * y_prime + (h * h / 2) * y_double_prime;
        x += h;
        printf("x = %.6f, y = %.6f\n", x, y);
    }
}

int main() {
    double x0, y0, h;
    int n;

    printf("Enter initial values x0 and y0: ");
    scanf("%lf %lf", &x0, &y0);

    printf("Enter step size h: ");
    scanf("%lf", &h);

    printf("Enter number of steps: ");
    scanf("%d", &n);

    taylor_series_method(x0, y0, h, n);

    return 0;
}
