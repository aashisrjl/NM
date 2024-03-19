#include<stdio.h>
#define n 3

int main() {
    printf("\n\t\t\t\t=========Gauss Elimination Method\n");
    int i, j, k;
    float a[n][n], b[n], x[n];
    float pivot, value, sum;

    printf("\n Enter matrix a \n a11, a12, a13 \n a21, a22, a23 \n a31, a32, a33\n");
    for(i = 0; i < n; i++) {
    	printf("\n");
        for(j = 0; j < n; j++) {
            scanf("%f \t", &a[i][j]);
        }
    }

    printf("\n Enter matrix b \n b1, b2, b3 \n");
    for(i = 0; i < n; i++) {
        scanf("%f \t", &b[i]);
    }

    // Gaussian Elimination
    for(k = 0; k < n-1; k++) {
        pivot = a[k][k];
        if(pivot == 0) {
            printf("Pivot can't be 0 \n");
            return 1;
        }
        for(i = k+1; i < n; i++) {
            value = a[i][k] / pivot;
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

