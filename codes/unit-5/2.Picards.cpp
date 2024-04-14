#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000
#define EPSILON 1e-6

double picard_iteration(double t0, double y0, double h, double T) {
    double y = y0;
    double y_prev = y0;
    int iter = 0;

    while (iter < MAX_ITER) {
        y = y0; // Initialize y for the iteration
        for (double t = t0; t < T; t += h) {
            // The function dy/dt = t^2 + y, directly used in the calculation
            double derivative = t * t + y;
            y += h * derivative; // Increment y based on the derivative
        }

        // Check for convergence
        if (fabs(y - y_prev) < EPSILON) {
            break;
        }

        y_prev = y;
        iter++;
    }

    // Check if iteration stopped due to reaching the maximum number of iterations
    if (iter == MAX_ITER) {
        printf("Warning: Maximum iterations reached. Solution may not have converged.\n");
    }

    return y;
}

int main() {
    printf("Picard Iteration Method for ODE solving\n");

    double t0, y0, h, T;

    // User input for initial conditions and parameters
    printf("Enter initial value of t (t0): ");
    scanf("%lf", &t0);

    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);

    printf("Enter step size (h): ");
    scanf("%lf", &h);
    if (h <= 0) {
        printf("Error: Step size must be positive.\n");
        return 1;
    }

    printf("Enter final value of t (T): ");
    scanf("%lf", &T);
    if (T <= t0) {
        printf("Error: Final time T must be greater than initial time t0.\n");
        return 1;
    }

    double result = picard_iteration(t0, y0, h, T);

    printf("The approximate value of y(%lf) is %lf\n", T, result);

    return 0;
}

