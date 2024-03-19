//program to implement the 3/8 simpson   rule
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define max 10
#define f(x) sin(x)


int main()
{
    printf("\n\n \t\t  Simpson 3/8(fun)\n");
    printf("\t\t ====================================\n");
	float a,b,h,value;

	printf("\n Enter the initial value of x:");
	scanf("%f",&a);

   printf("\n Enter the initial value of x:");
	scanf("%f",&b);

	h=(b-a)/3;
	value=3*h*(f(a)+3*(a+h)+3*f(a+2*h)+f(b))/8;

	printf("\n Integration value:%f", value);
}
