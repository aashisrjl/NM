#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NX 100
#define NY 100
#define MAX_ITER 10000
#define TOLERANCE 1e-5

void initialize(double u[][NY], double rho[][NY], double dx, double dy) {
    // Initialize boundary conditions
    double left_bc, right_bc, top_bc, bottom_bc;
    printf("Enter the value for left boundary condition: ");
    scanf("%lf", &left_bc);
    printf("Enter the value for right boundary condition: ");
    scanf("%lf", &right_bc);
    printf("Enter the value for top boundary condition: ");
    scanf("%lf", &top_bc);
    printf("Enter the value for bottom boundary condition: ");
    scanf("%lf", &bottom_bc);

    for (int i = 0; i < NX; i++) {
        u[i][0] = bottom_bc;      // Bottom boundary
        u[i][NY - 1] = top_bc;     // Top boundary
    }
    for (int j = 0; j < NY; j++) {
        u[0][j] = left_bc;         // Left boundary
        u[NX - 1][j] = right_bc;   // Right boundary
    }

    // Initialize source term
    for (int i = 0; i < NX; i++) {
        for (int j = 0; j < NY; j++) {
            rho[i][j] = 0.0;
        }
    }

    // Add a source term (example)
    int source_x, source_y;
    printf("Enter the x-coordinate of the source term: ");
    scanf("%d", &source_x);
    printf("Enter the y-coordinate of the source term: ");
    scanf("%d", &source_y);
    rho[source_x][source_y] = 1.0 / (dx * dy);
}

void solve_poisson(double u[][NY], double rho[][NY], double dx, double dy) {
    double u_old[NX][NY];
    double error;

    // Initialize u_old
    for (int i = 0; i < NX; i++) {
        for (int j = 0; j < NY; j++) {
            u_old[i][j] = u[i][j];
        }
    }

    int iter = 0;
    do {
        // Update u using Gauss-Seidel iteration
        for (int i = 1; i < NX - 1; i++) {
            for (int j = 1; j < NY - 1; j++) {
                u[i][j] = 0.25 * (u_old[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1] - dx * dy * rho[i][j]);
            }
        }

        // Calculate error
        error = 0.0;
        for (int i = 1; i < NX - 1; i++) {
            for (int j = 1; j < NY - 1; j++) {
                error += fabs(u[i][j] - u_old[i][j]);
                u_old[i][j] = u[i][j];
            }
        }
        error /= (NX * NY);

        iter++;
    } while (iter < MAX_ITER && error > TOLERANCE);
}

int main() {
    double u[NX][NY];
    double rho[NX][NY];
    double dx = 1.0 / (NX - 1);
    double dy = 1.0 / (NY - 1);

    // Initialize
    initialize(u, rho, dx, dy);

    // Solve Poisson's equation
    solve_poisson(u, rho, dx, dy);

    // Print result
    for (int i = 0; i < NX; i++) {
        for (int j = 0; j < NY; j++) {
            printf("%f ", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}

