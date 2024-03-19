#include <stdio.h>
#include <math.h>

// Function to perform Cholesky decomposition
void choleskyDecomposition(double A[][10], double L[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;

            if (j == i) {
                for (int k = 0; k < j; k++)
                    sum += pow(L[j][k], 2);
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++)
                    sum += (L[i][k] * L[j][k]);
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}


// Function to print a matrix
void printMatrix(double mat[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%0.3f ", mat[i][j]);
        printf("\n");
    }
}

int main() {
	printf("\t\t\t\t =======Cholesky Decomposition method=====\n");
    int n;

    // Input size of the matrix
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    double A[10][10], L[10][10];

    // Input elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);
    }

    // Perform Cholesky decomposition
    choleskyDecomposition(A, L, n);

    // Display the lower triangular matrix
    printf("\nLower Triangular Matrix (L):\n");
    printMatrix(L, n);

    return 0;
}

