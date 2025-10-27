#include <stdio.h>

double f(double x, double y) {
    return y - x*x + 1;
}

void runge_kutta(double x0, double y0, double h, int n) {
    double x = x0, y = y0, k1, k2, k3, k4;
    printf("x = %.6f, y = %.6f\n", x, y);
    for (int i = 0; i < n; i++) {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);
        y += (k1 + 2*k2 + 2*k3 + k4) / 6;
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

    runge_kutta(x0, y0, h, n);
    return 0;
}
