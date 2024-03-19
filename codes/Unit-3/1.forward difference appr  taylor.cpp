// Forward Difference Approximation using Taylor series
#include<stdio.h>
#include<math.h>

#define f(x) ((x)*(x)) 

int main(){
    float x, h;
    float Fxh, Fx;
    float fx;
    printf("\n Forward Difference Approximation using Taylor series: \n");

    printf("Enter initial point x: ");
    scanf("%f", &x);

    printf("Enter difference point h: ");
    scanf("%f", &h);

    // Calculate f(x) and f(x+h)
    Fx = f(x);
    Fxh = f(x + h);

    // Calculate the forward difference approximation of the derivative
    fx = (Fxh - Fx) / h;

    printf("The forward difference approximation of the derivative is: %f\n", fx);

    return 0;
}

