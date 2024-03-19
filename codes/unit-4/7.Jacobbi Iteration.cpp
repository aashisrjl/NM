#include <stdio.h>
#include <math.h>

#define N 3 

int main() {
    double A[N][N], B[N], X[N], newX[N];
    double e = 0.0001; 
    int maxIterations = 100; 
    int iterations = 0;
    int i, j;

    // Input matrix A and vector B
    printf("Enter the coefficients of the matrix A and the vector B:\n");
    for (i = 0; i < N; i++) {
        printf("Row %d (separate each coefficient by a space): ", i + 1);
        for (j = 0; j < N; j++)
            scanf("%lf", &A[i][j]);
        scanf("%lf", &B[i]);
    }

    // Initial guess for solution X
    printf("Enter initial guess for solution X:\n");
    for (i = 0; i < N; i++)
        scanf("%lf", &X[i]);

    // Jacobi iteration
    while (iterations < maxIterations) {
        for (i = 0; i < N; i++) {
            newX[i] = B[i];
            for (j = 0; j < N; j++) {
                if (j != i)
                    newX[i] -= A[i][j] * X[j];
            }
            newX[i] /= A[i][i];
        }

        // Check for convergence
        int converged = 1;
        for (i = 0; i < N; i++) {
            if (fabs(newX[i] - X[i]) > e) {
                converged = 0;
                break;
            }
        }

        // If converged, break
        if (converged)
            break;

        // Update X for the next iteration
        for (i = 0; i < N; i++)
            X[i] = newX[i];

        iterations++;
    }

    // Output the solution
    printf("\nSolution:\n");
    for (i = 0; i < N; i++)
        printf("X%d = %.6f\n", i + 1, X[i]);

    // Output the number of iterations
    printf("\nNumber of iterations: %d\n", iterations);

    return 0;
}

