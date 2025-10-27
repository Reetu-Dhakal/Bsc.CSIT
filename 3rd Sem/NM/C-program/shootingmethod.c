#include <stdio.h>

double f(double x, double y, double z) {
    return z;
}

double g(double x, double y, double z) {
    return -y - 2*z;
}

double runge_kutta(double x0, double y0, double z0, double h, double xn) {
    double x = x0, y = y0, z = z0;
    while (x < xn) {
        double k1y = h * f(x, y, z);
        double k1z = h * g(x, y, z);
        double k2y = h * f(x + h / 2, y + k1y / 2, z + k1z / 2);
        double k2z = h * g(x + h / 2, y + k1y / 2, z + k1z / 2);
        double k3y = h * f(x + h / 2, y + k2y / 2, z + k2z / 2);
        double k3z = h * g(x + h / 2, y + k2y / 2, z + k2z / 2);
        double k4y = h * f(x + h, y + k3y, z + k3z);
        double k4z = h * g(x + h, y + k3y, z + k3z);

        y += (k1y + 2 * k2y + 2 * k3y + k4y) / 6;
        z += (k1z + 2 * k2z + 2 * k3z + k4z) / 6;
        x += h;
    }
    return y;
}

int main() {
    double x0, y0, xn, yn, z0, h, res;
    printf("Enter x0 and y0: ");
    scanf("%lf %lf", &x0, &y0);
    printf("Enter xn and yn: ");
    scanf("%lf %lf", &xn, &yn);
    printf("Enter initial slope guess: ");
    scanf("%lf", &z0);
    printf("Enter step size h: ");
    scanf("%lf", &h);

    res = runge_kutta(x0, y0, z0, h, xn);
    printf("Computed y(%.2lf) = %.6lf\n", xn, res);

    return 0;
}
