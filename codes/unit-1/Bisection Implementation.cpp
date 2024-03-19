#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (pow(x, 2) - 4 * x - 10)
#define e 0.0001

int main() {
    double x, x0, x1, x2;
    double f1, f2;
    
    do {
        printf("\n Enter x1 and x2: \n");
        scanf("%lf %lf", &x1, &x2);
        
        f1 = f(x1);
        f2 = f(x2);
    } while ((f1 * f2) > 0);
    
    
    do {
        x0 = (x1 + x2) / 2;
        
        if ((f1 * f(x0)) < 0) {
            x2 = x0;
        } else {
            x1 = x0;
            x = (x1 + x2) / 2;
        }
    } while (fabs(x - x0) > e);

    printf("\n Root is: %lf", x0);

    return 0;
}

