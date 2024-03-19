#include<stdio.h>
#include<math.h>
#define f(x) sin(x)

int main() {
    float a, b, h, value = 0.0;
    int n;
    printf("\n\n \t\t Composite Simpson 3/8 function\n");
    printf("\t\t ====================================\n");

    printf("\nEnter the initial value of x: ");
    scanf("%f", &a);
    printf("\nEnter the final value of x: ");
    scanf("%f", &b);
    printf("\nEnter the number of segments (a multiple of 3): ");
    scanf("%d", &n);

    h = (b - a) / n; // Calculate the segment width

    // Compute the integral using composite Simpson's 3/8 rule
    for (int i = 0; i < n; i += 3) {
        float x0 = a + i * h;
        float x1 = x0 + h;
        float x2 = x1 + h;
        float x3 = x2 + h;

        float f0 = f(x0);
        float f1 = f(x1);
        float f2 = f(x2);
        float f3 = f(x3);

        value += 3 * h * (f0 + 3 * (f1 + f2) + f3) / 8;
    }

    printf("\nIntegration value: %f\n", value);

    return 0;
}

