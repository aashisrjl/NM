#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000
#define EPSILON 1e-6

double picard_iteration(double t0, double y0, double h, double T) {
    double y = y0;
    double y_prev = y0;
    int iter = 0;

    while (iter < MAX_ITER) {
        y = y0;  // Initialize y for each iteration
        for (double t = t0; t < T; t += h) {
            // Define the function dy/dt = t^2 + y directly inside the loop
            double derivative = t * t + y;
            y = y0 + h * derivative;
            y0 = y;
        }

        // Check for convergence
        if (fabs(y - y_prev) < EPSILON)
            break;

        y_prev = y;
        iter++;
    }

    return y;
}

int main() {
    double t0 = 0.0;    // Initial value of t
    double y0 = 1.0;    // Initial value of y
    double h = 0.1;     // Step size
    double T = 1.0;     // Final value of t

    double result = picard_iteration(t0, y0, h, T);

    printf("The approximate value of y(%lf) is %lf\n", T, result);

    return 0;
}

