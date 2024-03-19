 // newton rapson method two equation implementation//
 /*1. start 
 2. define the function f and g 
 3. define the jacobian elements f1,f2,g1 and g2
 4. define starting points xo and yo and error
 5. evaluate f,g,f1,f2,g1,g2 at (xo,yo)
 	compute Dx,Dy and D
 	x1=xo-Dx/D;
 	y1=yo-Dy/D;
 6.test for accuracy
	if |x1-xo| < e and |y1-yo| <e then solution obtained
	goto step 8
 7.othgerwiese
 	set xo=x1
	 yo=y1
	 goto step 5
 8. print the root
 9. stop
 */  

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) 3*x - cos(x) -1
#define g(x) 3 + sin(x)

int main()
{
	 float x0, x1, f0, f1, g0, e;
	 int step = 1, N;
     /* Inputs */
	 printf("\nEnter initial guess:\n");
	 scanf("%f", &x0);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 printf("Enter maximum iteration:\n");
	 scanf("%d", &N);
	 /* Implementing Newton Raphson Method */
	 printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }

		
		  x1 = x0 - f0/g0;

		
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f0,x1,f1);
		  x0 = x1;
		  
		  step = step+1;
		
		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
		  
		  f1 = f(x1);
		  
	 }while(fabs(f1)>e);
	
	 printf("\nRoot is: %f", x1);
}
