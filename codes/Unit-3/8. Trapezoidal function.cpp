#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) x*x*x+1
int main()
{
	    printf("\n\n \t\t  Trapezoidal\n");
    printf("\t\t ====================================\n");
float a,b,it,h;
printf("\n \t\t Trapezoidal\n");
printf("Please enter the limits of integration\n");
scanf("%f%f",&a,&b);
h=b-a;
it= h/2*(f(a)+f(b));
printf("The value of integration is\nIt= %f",it);

}


