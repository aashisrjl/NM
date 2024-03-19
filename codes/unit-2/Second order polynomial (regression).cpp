#include<stdio.h>
#include<math.h>
#include<conio.h>
#define MAX 10

int main() {
    int i, n;
    float a0, a1, a2;
    float x[MAX], y[MAX], sumx = 0.0, sumy = 0.0, sumxy = 0.0, sumxsq = 0.0, sumxcube = 0.0, sumxquad = 0.0;

    printf("***Least square method for second-order polynomial***");
    printf("\nInput the number of data points: ");
    scanf("%d", &n);
    printf("Enter the data sets one after another:\n");
    
    for (i = 0; i < n; i++) {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
        printf("y[%d]=", i);
        scanf("%f", &y[i]);
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumxsq += x[i] * x[i];
        sumxcube += pow(x[i], 3);
        sumxquad += pow(x[i], 4);
    }

    float detA = n * sumxsq * sumxquad + 2 * sumx * sumxcube * sumx + sumx * sumx * sumxsq - sumxquad * sumxquad - n * sumx * sumx * sumxsq - sumxsq * sumxcube;
    float detA0 = sumy * sumxsq * sumxquad + sumxy * sumx * sumxcube + sumx * sumxy * sumxquad - sumy * sumx * sumxsq - sumxy * sumxquad * sumx - sumxsq * sumxcube * sumy;
    float detA1 = n * sumxy * sumxquad + sumy * sumx * sumxsq + sumxy * sumx * sumx - sumxquad * sumy - sumx * sumx * sumxy - n * sumxsq * sumxy;
    float detA2 = n * sumxsq * sumy + sumx * sumxy * sumxquad + sumx * sumx * sumxcube - sumy * sumx * sumxsq - sumxy * sumxquad * sumx - n * sumxcube * sumx;

    a0 = detA0 / detA;
    a1 = detA1 / detA;
    a2 = detA2 / detA;

    printf("\nThe equation of the second-order polynomial:\n");
    printf("\ny = %f * x^2 + %f * x + %f\n", a2, a1, a0);

    getch();
    return 0;
}

