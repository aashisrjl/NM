#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) ((x)*(x)*(x) -2*(x) -5)
#define e 0.0001

int main() {
    float xo, x1, x2;
    float fo, f1, f2;
    int step = 1;
    int n;

    printf("\n Enter x1, x2:");
    scanf("%f %f", &x1,&x2);

    printf("\n Enter max Iteration");
    scanf("%d", &n);

    printf("\n step \t xo \t\t\t x1 \t\t\t x2 \t\t\t f(x1) \t\t f(x2) \n");

    do {
        fo = f(xo);
        f1 = f(x1);

        if (fo == f1) {
            printf("Mathematical error !");
            exit(1);
        }
        
        x2 = x1 - (x1 - xo) * f1 / (f1 - fo);
        f2 = f(x2);

        printf("\n %d \t %f \t\t %f \t\t %f \t\t %f \t\t %f \n", step, xo, x1, x2, f1, f2);

        xo = x1;
        fo = f1;
        x1 = x2;
        f1 = f2;
        step++;

        if (step > n) {
            printf("Not convergent");
            printf("X2 is root")
            exit(1);
        }

    } while (fabs(f2) > e);

    printf("\n Root is %f", x2);
    return 0;
}

