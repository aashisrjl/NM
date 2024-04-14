#include <math.h>
#include <stdio.h>
#include <string.h>

int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int n, count = 0, i, j, k;
    double xp, h, s, v = 0, p;

    printf(" ======================Newton's backward difference interpolation "
           "======================= \n");
    printf("\n Enter number of data points:\n");
    scanf("%d", &n);

    double x[n], fx[n], a[n];

    printf("\n Enter value of given xp :\n");
    scanf("%lf", &xp);

    printf("Enter the values of x and f(x):\n");
    for (i = 0; i < n; i++) {
        printf("x%d= ", count);
        scanf("%lf", &x[i]);
        printf("fx%d= ", count);
        scanf("%lf", &fx[i]);
        count++;
        printf("\n");
    }

    h = x[1] - x[0];
    s = ((xp - x[n - 1]) / h); // Compute s based on the last data point

    count = 0;
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("x%d= \t %lf \t", count, x[i]);
        count++;
    }
    printf("\n");

    count = 0;
    for (i = 0; i < n; i++) {
        printf("fx%d= \t %lf \t", count, fx[i]);
        count++;
    }

    printf("\n//////The value of h is: %lf", h);
    printf("\n/////The value of s is: %lf", s);

    for (i = 0; i < n; i++) {
        a[i] = fx[i];
    }

    // Compute backward difference coefficients using backward differences
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            a[j] = a[j + 1] - a[j];
        }
    }

    // Initialize v with the last backward difference coefficient
    v = a[n - 1];

    // Evaluate the polynomial using Newton's backward difference formula
    for (i = 1; i < n; i++) {
        p = s;
        for (k = 0; k < i; k++) {
            p = p * (s + k);
            p = p / (k + 1); // Correct the formula
        }
        v = v + a[i] * p;
    }

    printf("\n The value of f(%lf) is : %lf", xp, v);

    return 0;
}

