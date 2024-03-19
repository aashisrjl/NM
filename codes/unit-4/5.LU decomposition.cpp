#include <stdio.h>

#define N 3 

void printMatrix(float matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void doolittleLU(float A[N][N], float L[N][N], float U[N][N]) {
    for (int i = 0; i < N; i++) {
        // Upper Triangular Matrix
        for (int k = i; k < N; k++) {
            // Summation of L(i, j) * U(j, k)
            int sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);

            // Evaluating U(i, k)
            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular Matrix
        for (int k = i; k < N; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else {
                // Summation of L(k, j) * U(j, i)
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);

                // Evaluating L(k, i)
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

int main() {
	
	printf("\t\t\t ===== Doolittle LU Decomposition========\n");
    float A[N][N]; // Input matrix
    float L[N][N], U[N][N]; // Lower and Upper triangular matrices

    printf("Enter the elements of the %dx%d matrix:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    doolittleLU(A, L, U);

    printf("\nLower Triangular Matrix (L):\n");
    printMatrix(L);

    printf("Upper Triangular Matrix (U):\n");
    printMatrix(U);

    return 0;
}

