#include <stdio.h>

#define n 3  // dimension rows
#define m 3  // dimension columns

float gx(float x, float y) {
    return -4;
}

int main() {
    int i, j, k;
    float a[10][10], g[10][10], h, xl, xh, yl, x;

    printf("Enter xl: ");
    scanf("%f", &xl);
    printf("Enter xh: ");
    scanf("%f", &xh);
    printf("Enter yl: ");
    scanf("%f", &yl);

    h = (xh - xl) / (n - 1);

    // Calculate g(x, y)
    for (i = 1; i <= n; i++) {
        x = xl;
        for (j = 1; j <= m; j++) {
            g[i][j] = gx(x, yl);
            x += h;
        }
        yl += h;
    }

    // Input boundary conditions
    printf("Enter boundary conditions:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (i == 1 || i == n || j == 1 || j == m) {
                printf("a[%d,%d] = ", i, j);
                scanf("%f", &a[i][j]);
            }
        }
    }

    // Set boundary values
    for (i = 2; i < n; i++)
        for (j = 2; j < m; j++)
            a[i][j] = a[n][j];

    // Gauss-Seidel Iteration
    for (k = 0; k < 100; k++) {
        for (i = 2; i < n; i++) {
            for (j = 2; j < m; j++) {
                a[i][j] = (a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1] - (h * h * g[i][j])) / 4;
            }
        }
    }

    // Print the solution
    printf("Solution:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

