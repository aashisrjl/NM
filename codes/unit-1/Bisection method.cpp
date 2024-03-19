#include<stdio.h>
#include<stdlib.h> 
#include<math.h>

#define eqn(x) ((x)*(x)*(x) - 2*(x) - 5)

// start
float f(float x) {
    return eqn(x);
}

int main() {
    // declaring variable
    float x1, x2, error = 0.0001;
    float f1, f2;
    float xo, fo;
    float root;
    char choice;

    do {
        //initial value for x1 and x2
        printf("Enter value of x1 and x2: ");
        scanf("%f %f", &x1, &x2);
        //calculating function f1 and f2 f(x1) and f(x2)
        f1 = eqn(x1);
        f2 = eqn(x2);
    } while(f1 * f2 >= 0); // this condition ensures there is a root

do{
    // computing mid value 
    xo = (x1 + x2) / 2;
    fo = eqn(xo); // function of mid point 

    // checking where the root lies between 
    if (fo * f2 < 0) {
        x1 = xo;
        f1 = fo;
    }

    // comparing with error
        root = (x1 + x2) / 2;
        printf("Root is %f\n", root);
        // exit removed here
    }while((fabs(x2 - x1) / 2) < error);
    printf("Root is %f\n", root);

    return 0;
}

