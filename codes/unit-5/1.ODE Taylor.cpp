#include <stdio.h>

double taylor_series(double t0, double y0, double h, double T) {
    double t = t0;
    double y = y0;

    while (t < T) {
        // Directly use the expressions for f, df/dt, and df/dy in the computation
        double f = t * t + y;          // f(t, y) = t^2 + y
        double dfdt = 2 * t;           // df/dt = 2t
        double dfdy = 1;               // df/dy = 1

        double y_next = y + h * f + (h * h / 2) * (dfdt + dfdy * f);
        t += h;
        y = y_next;
    }

    return y;
}

int main() {
    printf("\n\t\t======ODE using Taylor Series Method======\n");
    double t0, y0, h, T;

    // Asking user for input
    printf("Enter initial value of t (t0): ");
    scanf("%lf", &t0);

    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);

    printf("Enter step size (h): ");
    scanf("%lf", &h);

    printf("Enter final value of t (T): ");
    scanf("%lf", &T);

    double result = taylor_series(t0, y0, h, T);

    printf("The approximate value of y(%lf) is %lf\n", T, result);

    return 0;
}

