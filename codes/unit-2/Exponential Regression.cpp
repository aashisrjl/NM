#include <stdio.h>
#include <math.h>

int main() {
    int i, n;
    float b, a, loga;
    float sx = 0, sx2 = 0, s_log_y = 0, s_x_log_y = 0;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of data points. Exiting...\n");
        return 1;
    }

    float logy[n], x[n], y[n];

    printf("Enter the value of x and y respectively: \n");
    for(i = 0; i < n; i++){
        printf("x[%d]= ", i);
        scanf("%f", &x[i]);
        printf("y[%d]= ", i);
        scanf("%f", &y[i]);

        if (y[i] <= 0) {
            printf("Invalid value of y. Exiting...\n");
            return 1;
        }

        logy[i] = log(y[i]); // Calculate the natural logarithm of y[i]
    }

    for(i = 0; i < n; i++){
        sx += x[i];
        sx2 += x[i] * x[i];
        s_log_y += logy[i];
        s_x_log_y += x[i] * logy[i];
    }

    b = ((n * s_x_log_y) - (sx * s_log_y)) / ((n * sx2) - (sx * sx));
    loga = (s_log_y / n) - (b * (sx / n));
    a = exp(loga); // Calculate e^(loga)

    printf("y = %f * e^(%f * x)\n", a, b);

    return 0;
}

