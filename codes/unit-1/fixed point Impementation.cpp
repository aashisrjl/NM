#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) cos(x)-3*(x)+1
#define g(x) (1+cos(x))/3
#define e 0.0001

int main(){
	float xo,x1;
	float fo,f1,go;
	int step=1;
	int n;
	
	printf("Enter initaial value:");
	scanf("%f",&xo);
	
	printf("\nEnter Interation:");
	scanf("%d",&n);
	
	printf("\n step \t\t xo \t\t\t f(xo) \t\t x1 \t\t\t f(x1)\n");
	
	do{
		
		fo=f(xo);
		f1=f(x1);
		x1=g(xo);
		printf("\n %d \t\t %f \t\t %f \t\t %f \t\t %f\n",step,xo,fo,x1,f1);
		xo=x1;
		step++;
		if(step>n){
			printf("\nSorry you meet your Iteration !");
			exit(0);
		}
		xo=x1;
	}while(fabs(f1)>e);
	
	printf("\n ==== Rooot is ==========: %f",x1);
}
