#include<stdio.h>
#include<math.h>

#define f(x) ((x)*(x)) 

int main(){
    float x, h;
    float PlusFxh, SubFxh;
    float fx;
    float add, sub;
    
    printf("\n Central Difference Approximation using Taylor series: \n");

    printf("Enter initial point x: ");
    scanf("%f", &x);

    printf("Enter difference point h: ");
    scanf("%f", &h);

    // Calculate x+h and x-h
    add = x + h;
    sub = x - h;

    // Calculate f(x+h) and f(x-h)
    PlusFxh = f(add);
    SubFxh = f(sub);

    // Calculate the central difference approximation of the derivative
    fx = (PlusFxh - SubFxh) / (2 * h);

    printf("The central difference approximation of the derivative is: %f\n", fx);

    return 0;
}

