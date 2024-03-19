#include<stdio.h>
#include<math.h>

#define f(x) ((x)*(x)) 

int main(){
    float x, h;
    float Fxh, Fx;
    float fx;
    
    printf("\n Backward Difference Approximation using Taylor series: \n");

    printf("Enter initial point x: ");
    scanf("%f", &x);

    printf("Enter difference point h: ");
    scanf("%f", &h);

    // Calculate f(x) and f(x-h)
    Fx = f(x);
    Fxh = f(x - h);

    // Calculate the backward difference approximation of the derivative
    fx = (Fx - Fxh) / h;

    printf("The backward difference approximation of the derivative is: %f\n", fx);

    return 0;
}

