// newton forward difference interpolation
#include <math.h>
#include <stdio.h>
#include <string.h>

int fact(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

int main() {
  char name[30];
  printf("Enter name of the coder of this program: \n");
  scanf("%s", &name);

  if (strcmp(name, "aashis") != 0) {
    printf("Invalid owner name. Exiting the program.\n");
    return 1;
  }

  int n, count = 0, i, j, k;
  double xp, h, s, v = 0, p;

  printf(" ======================Newton's forward difference interpolation "
         "======================= \n");
  printf("\n Enter number of data points:\n");
  scanf("%d", &n);

  double x[n], fx[n], a[n];

  printf("\n Enter value of given xp :\n");
  scanf("%lf", &xp);

  printf("Enter the values of x and f(x):\n");
  for (i = 0; i < n; i++) {
    printf("x%d= ", count);
    scanf("%lf", &x[i]);
    printf("fx%d= ", count);
    scanf("%lf", &fx[i]);
    count++;
    printf("\n");
  }

  h = x[1] - x[0];
  s = ((xp - x[0]) / h);

  count = 0;
  printf("\n");
  for (i = 0; i < n; i++) {
    printf("x%d= \t %lf \t", count, x[i]);
    count++;
  }
  printf("\n");

  count = 0;
  for (i = 0; i < n; i++) {
    printf("fx%d= \t %lf \t", count, fx[i]);
    count++;
  }

  printf("\n//////The value of h is: %lf", h);
  printf("\n/////The value of s is: %lf", s);

  for (i = 0; i < n; i++) {
    a[i] = fx[i];
  }

// Compute divided difference coefficients using forward differences
for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {
        fx[j] = fx[j] - fx[j - 1];
    }
}

// Initialize v with the first divided difference coefficient
v = fx[0];

// Evaluate the polynomial using Newton's forward difference formula
for (i = 1; i < n; i++) {
    p = 1;
    for (k = 0; k < i; k++) {
        p = p * (s - k);
    }
    v = v + fx[i] * p / fact(i);
}


  printf("\n The value of f(%lf) is : %lf", xp, v);
}

