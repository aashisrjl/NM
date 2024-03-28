//ODE using taylor series method
#include <stdio.h>

double f(double t, double y) {
    // Define the function dy/dt = f(t, y)
    return t * t + y;
}

double dfdt(double t, double y) {
    // Define the partial derivative of f with respect to t
    return 2 * t;
}

double dfdy(double t, double y) {
    // Define the partial derivative of f with respect to y
    return 1;
}

double taylor_series(double t0, double y0, double h, double T, double (*f)(double, double), double (*dfdt)(double, double), double (*dfdy)(double, double)) {
    double t = t0;
    double y = y0;

    while (t < T) {
        double y_next = y + h * f(t, y) + (h * h / 2) * (dfdt(t, y) + dfdy(t, y) * f(t, y));
        t += h;
        y = y_next;
    }

    return y;
}

int main() {
	printf("\n \t\t\t\t======ODE using Taylor series=====\n");
    double t0 = 0.0;    // Initial value of t
    double y0 = 1.0;    // Initial value of y
    double h = 0.1;     // Step size
    double T = 1.0;     // Final value of t

    double result = taylor_series(t0, y0, h, T, f, dfdt, dfdy);

    printf("The approximate value of y(%lf) is %lf\n", T, result);

    return 0;
}

