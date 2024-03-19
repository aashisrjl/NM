#include <stdio.h>

int main() {
	     printf("\Derivative using newton backward difference:\n");
    printf("========================\n\n");
    int n, i;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the data points in the format (x, y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }

    double xi, h;
    printf("Enter the value at which you want to calculate the derivative: ");
    scanf("%lf", &xi);

    // Calculate backward divided difference
    int index = -1;
    for (i = 0; i < n; i++) {
        if (x[i] <= xi && xi <= x[i+1]) {
            index = i;
            break;
        }
    }

    if (index == -1 || index == 0) {
        printf("Cannot calculate the derivative at this point.\n");
        return 1;
    }

    h = x[index] - x[index - 1];
    double derivative = (y[index] - y[index - 1]) / h;

    printf("The derivative at x = %lf is: %lf\n", xi, derivative);

    return 0;
}

