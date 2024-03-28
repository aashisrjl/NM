#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum grid size

int main() {
    int nx, ny;  // Number of grid points in x and y directions
    double dx, dy;  // Grid spacing in x and y directions
    double u[MAX_SIZE][MAX_SIZE];  // Solution grid
    double f[MAX_SIZE][MAX_SIZE];  // Source term grid

    // Input grid size and spacing
    printf("Enter the number of grid points in the x direction: ");
    scanf("%d", &nx);
    printf("Enter the number of grid points in the y direction: ");
    scanf("%d", &ny);
    printf("Enter the grid spacing in the x direction: ");
    scanf("%lf", &dx);
    printf("Enter the grid spacing in the y direction: ");
    scanf("%lf", &dy);

    // Check if grid size is within limits
    if (nx > MAX_SIZE || ny > MAX_SIZE) {
        printf("Grid size exceeds the maximum limit.\n");
        return 1;
    }

    // Initialize solution grid
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            u[i][j] = 0.0;
        }
    }

    // Input source term
    printf("Enter the source term at each grid point:\n");
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            printf("f[%d][%d]: ", i, j);
            scanf("%lf", &f[i][j]);
        }
    }

    // Solve Poisson's equation using finite difference method
    double tol = 1e-6;  // Tolerance for convergence
    int max_iter = 1000;  // Maximum number of iterations
    int iter;
    for (iter = 0; iter < max_iter; iter++) {
        double max_diff = 0.0;
        for (int i = 1; i < nx - 1; i++) {
            for (int j = 1; j < ny - 1; j++) {
                double temp = u[i][j];
                u[i][j] = 0.25 * (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1] - dx * dy * f[i][j]);
                double diff = fabs(u[i][j] - temp);
                if (diff > max_diff) {
                    max_diff = diff;
                }
            }
        }
        if (max_diff < tol) {
            break;
        }
    }

    // Print the solution
    printf("\nSolution after %d iterations:\n", iter);
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            printf("%.6f ", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}

