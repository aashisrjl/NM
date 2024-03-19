#include<stdio.h>
#define n 3

int main() {
    printf("\n\t\t\t\t=========Gauss Elimination With Pivoting\n");
    int i, j, k;
    float a[n][n], b[n], x[n];
    float pivot, value, sum;

    printf("\n Enter matrix a \n a11, a12, a13 \n a21, a22, a23 \n a31, a32, a33\n");
    for(i = 0; i < n; i++) {
        printf("\n");
        for(j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("\n Enter matrix b \n b1, b2, b3 \n");
    for(i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    // Gaussian Elimination with Partial Pivoting
    for(k = 0; k < n-1; k++) {
        // Partial Pivoting
        pivot = a[k][k];
        int max_row = k;
        for (i = k + 1; i < n; i++) {
            if (a[i][k] > pivot) {
                pivot = a[i][k];
                max_row = i;
            }
        }
        // Swap rows
        if (max_row != k) {
            for (j = k; j < n; j++) {
                float temp = a[k][j];
                a[k][j] = a[max_row][j];
                a[max_row][j] = temp;
            }
            float temp = b[k];
            b[k] = b[max_row];
            b[max_row] = temp;
        }

        for(i = k+1; i < n; i++) {
            value = a[i][k] / a[k][k];
            for(j = k; j < n; j++) {
                a[i][j] = a[i][j] - value * a[k][j];
            }
            b[i] = b[i] - value * b[k];
        }
    }

    // Back Substitution
    x[n-1] = b[n-1] / a[n-1][n-1];
    for(i = n-2; i >= 0; i--) {
        sum = 0;
        for(j = i+1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }

    // Output the result
    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i+1, x[i]);
    }

    return 0;
}

