#include <stdio.h>

#define n 3

int main() {
    printf("\t\t\t\ ====Gauss Jordan Method for Matrix Inversion ==========\n");
    float a[n][2 * n], x[n], ratio;

    // Input the matrix
    printf("Enter the coefficients of the matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Augmenting the matrix with an identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            a[i][j] = (i == (j - n)) ? 1 : 0;
        }
    }

    // Applying Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!\n");
            return 1;
        }
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (int k = 0; k < 2 * n; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    // Extracting the inverted matrix
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            a[i][j] = a[i][j] / a[i][i];
        }
    }

    // Displaying the inverted matrix
    printf("\nInverted Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            printf("%.3f\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

