#include <stdio.h>

double u_cal(double u, int n) {
    double temp = u;
    for (int i = 1; i < n; i++) {
        temp = temp * (u - i);
    }
    return temp;
}

long long fact(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    int n = 4;
    double x[] = {45, 50, 55, 60};
    double y[4][4] = {0};

    y[0][0] = 0.7071;
    y[1][0] = 0.7660;
    y[2][0] = 0.8192;
    y[3][0] = 0.8660;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    printf("x\t");
    for (int i = 0; i < n; i++) {
        printf("y[%d][0]\t", i);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("%.4f\t", y[i][j]);
        }
        printf("\n");
    }

    double value = 52;
    double sum = y[0][0];
    double u = (value - x[0]) / (x[1] - x[0]);

    for (int i = 1; i < n; i++) {
        sum += (u_cal(u, i) * y[0][i]) / fact(i);
    }

    printf("\nValue at %.2f is %.6f\n", value, sum);

    return 0;
}
