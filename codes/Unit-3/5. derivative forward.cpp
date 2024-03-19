#include <stdio.h>

// Function to calculate the derivative using forward divided difference formula
double forwardDifference(double x[], double y[], int n, double xi) {
    double h = x[1] - x[0]; // Assuming equally spaced data points
    double yi, yi_plus_h;
    int i;

    // Find the index i such that x[i] <= xi < x[i+1]
    for (i = 0; i < n - 1; i++) {
        if (xi >= x[i] && xi <= x[i+1]) {
            break;
        }
    }

    // Calculate forward difference
    yi = y[i];
    yi_plus_h = y[i+1];
    return (yi_plus_h - yi) / h;
}

int main() {
    int n, i;
        printf("\Derivative using newton forward difference:\n");
    printf("========================\n\n");
    
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

    double xi;
    printf("Enter the value at which you want to calculate the derivative: ");
    scanf("%lf", &xi);

    double derivative = forwardDifference(x, y, n, xi);
    printf("The derivative at x = %lf is: %lf\n", xi, derivative);

    return 0;
}

