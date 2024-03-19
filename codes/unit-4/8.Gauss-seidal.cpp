#include <stdio.h>
#include <math.h>

int main() {
		printf("\t\t\t ===== Gauss_seidal========\n");

    int n, maxIterations;
    double e;

    // Input size of the matrix
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    double A[n][n], b[n], x[n], x_prev[n];

    // Input elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);
    }

    // Input the right-hand side vector
    printf("Enter the elements of the right-hand side vector:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &b[i]);

    // Input maximum number of iterations and epsilon
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);
    printf("Enter the value of epsilon: ");
    scanf("%lf", &e);

    // Initial guess for the solution vector
    printf("Enter the initial guess for the solution vector:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
        x_prev[i] = x[i];
    }

    // Gauss-Seidel Iteration
    int iter = 0;
    double error;
    do {
        error = 0.0;
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum += A[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
            error += fabs(x[i] - x_prev[i]);
            x_prev[i] = x[i];
        }
        iter++;
    } while (error > e && iter < maxIterations);

    // Output the solution vector
    printf("\nSolution Vector (x):\n");
    for (int i = 0; i < n; i++)
        printf("%0.6f\n", x[i]);

    return 0;
}

