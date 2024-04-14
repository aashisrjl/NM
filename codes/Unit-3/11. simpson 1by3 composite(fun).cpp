#include<stdio.h>
#include<math.h>

#define F(x) (1 - exp(-(x) / 2.0))

int main() {
	    printf("\n \t\t==== Composite Simpson 1/3(fun)=====\n");

    int n;
    float a, b, h, sum = 0.0, Ics;
    
    printf("Enter initial value of X: ");
    scanf("%f", &a);
    printf("Enter final value of X: ");
    scanf("%f", &b);
    printf("Enter number of segments (Even number): ");
    scanf("%d", &n);
    
    h = (b - a) / n; // Calculate the segment width
    
    // Calculate the integral using composite Simpson's 1/3 rule
    for (int i = 0; i < n; i += 2) {
        float x0 = a + i * h;
        float x1 = x0 + h;
        float x2 = x1 + h;
        
        float f0 = F(x0);
        float f1 = F(x1);
        float f2 = F(x2);
        
        sum += f0 + 4 * f1 + f2;
    }
    
    Ics = sum * h / 3.0; // Compute the integral
    
    printf("\nIntegral from %f to %f when h = %f is %f\n", a, b, h, Ics);

    return 0;
}

