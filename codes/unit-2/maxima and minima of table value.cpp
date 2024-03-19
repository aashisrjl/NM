//WAP to implement maxima and minima of tabulated function.
#include <stdio.h>

#define MAX_DATA_POINTS 100

int main() {
    int n, i;
    float x[MAX_DATA_POINTS], y[MAX_DATA_POINTS];

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input the data points
    printf("Enter the data points (x, y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Check for maxima and minima
    printf("Maxima and Minima:\n");
    for (i = 1; i < n - 1; i++) {
        if (y[i] > y[i - 1] && y[i] > y[i + 1]) {
            printf("Maxima at (x[%d] = %f, y[%d] = %f)\n", i, x[i], i, y[i]);
        }
        if (y[i] < y[i - 1] && y[i] < y[i + 1]) {
            printf("Minima at (x[%d] = %f, y[%d] = %f)\n", i, x[i], i, y[i]);
        }
    }

    return 0;
}
 
