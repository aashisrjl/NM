#include<stdio.h>
#include<conio.h>

int main() {
    float x[100], y[100], xp, yp = 0, p;
    int i, j, n;
    
    printf("Enter number of data: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("\n x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    
    printf("Enter interpolation points: ");
    scanf("%f", &xp);
    
    for(i = 0; i < n; i++) {
        p = 1;
        for(j = 0; j < n; j++) {
            if(i != j) {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }
    
    printf("Interpolated value at %f is %f", xp, yp);
    
    getch();
    return 0;
}

