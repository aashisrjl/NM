#include<stdio.h>
#include<math.h>

int main(){
    int n, i, j;
    double x[n], fx[n], fd[n], h, a, b, c, s1, s2, x1, x2, value;

    printf("\nMaxima and Minima:\n");
    printf("========================\n\n");

    printf("Enter number of data points:");
    scanf("%d", &n);

    printf("Enter the values of x and f(x):\n");
    for (i = 0; i < n; i++) {
        printf("x%d= ", i);
        scanf("%lf", &x[i]);
        printf("fx%d= ", i);
        scanf("%lf", &fx[i]);
        printf("\n");
    }

    // Calculate forward differences
    for(i = 0; i < n; i++){
        h = x[i] - x[0];
        fd[i] = fx[i];
    }

    printf("The value of h is = %lf \n", h);

    // Compute forward differences
    for(i = 0; i < n; i++){
        for(j = n - 1; j >= i + 1; j--){
            fd[j] = fd[j] - fd[j - 1];
        }
    }

    // Print forward differences
    printf("\nForward differences:\n");
    for(i = 0; i < n; i++){
        printf("fd%d = %lf\n", i, fd[i]);
    }

    // Compute coefficients a, b, and c
    a = fd[3] / 3;
    b = (fd[2] - fd[3]) / 2;
    c = (fd[1] - (fd[2] / 2) + (fd[3] / 3));

    // Print coefficients
    printf("\na = %lf\n", a);
    printf("b = %lf\n", b);
    printf("c = %lf\n", c);

    // Compute roots s1 and s2
    s1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    s2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    // Compute x1 and x2
    x1 = x[0] + s1 * h;
    x2 = x[0] + s2 * h;

    // Evaluate the second derivative at x1 or x2
    value = fx[2] + ((b * s2 - b) * fd[3] / b) / (h * h);

    if (value < 0) {
        printf("\nThere is a maxima at x = %lf\n", x2);
    } else {
        printf("\nThere is a minima at x = %lf\n", x1);
    }

    return 0;
}

