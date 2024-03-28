#include <stdio.h>

#define N 1000  // Maximum number of steps
#define h 0.01  // Step size

// Define the ordinary differential equation (ODE)
double f(double x, double y, double z) {
    return z;  // dy/dx = z
}

double g(double x, double y, double z) {
    return x + y;  // dz/dx = x + y
}

// Euler's method for solving ODEs
void euler(double x0, double y0, double z0, double xn, double *y, double *z) {
    double x = x0, y_ = y0, z_ = z0;
    while (x < xn) {
        double dydx = f(x, y_, z_);
        double dzdx = g(x, y_, z_);
        y_ += h * dydx;
        z_ += h * dzdx;
        x += h;
    }
    *y = y_;
    *z = z_;
}

// Shooting method to find boundary value
double shoot(double x0, double y0, double zlow, double zhigh, double xn, double yd) {
    double y1, z1, y2, z2;
    euler(x0, y0, zlow, xn, &y1, &z1);
    euler(x0, y0, zhigh, xn, &y2, &z2);
    // Perform linear interpolation to estimate the correct initial z value
    double z = zlow + (zhigh - zlow) * (yd - y1) / (y2 - y1);
    return z;
}

int main() {
    double x0, y0, xn, yd;

    // Input initial conditions, boundary conditions, and desired boundary value
    printf("Enter the initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y (boundary condition y(x0)): ");
    scanf("%lf", &y0);
    printf("Enter the final value of x: ");
    scanf("%lf", &xn);
    printf("Enter the desired boundary value y(xn): ");
    scanf("%lf", &yd);

    // Initial guess for zlow and zhigh
    double zlow = 0.0;
    double zhigh = 1.0;

    // Tolerance for convergence
    double tol = 1e-6;

    double z = 0.0;  // Initial guess for z
    double y = 0.0;

    // Iterate until convergence
    while (1) {
        z = shoot(x0, y0, zlow, zhigh, xn, yd);
        euler(x0, y0, z, xn, &y, &z);

        if (y - yd > tol) {
            zhigh = z;
        } else if (yd - y > tol) {
            zlow = z;
        } else {
            break;  // Convergence achieved
        }
    }

    printf("The value of z at x=0 is: %lf\n", z);
    printf("The value of y at x=1 is: %lf\n", y);

    return 0;
}

