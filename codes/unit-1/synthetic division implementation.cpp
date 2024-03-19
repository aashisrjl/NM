  // Synthetic Division //
  // ******************//
#include<stdio.h>
#include<conio.h>

int main(){
                int poly[6], m, x, i, q[6];
                printf("\t\tSYNTHETIC DIVISION");
                printf("\n Enter the highest degree of the equation (max 5): ");
                scanf("%d",&m);

                for(i=0;i<=m;i++){
                    printf("\n Coefficient x[%d] = ", m-i);
                    scanf("%d",&poly[i]);
                }

                printf("\n Enter the value of constant (x) : ");
                scanf("%d",&x);
                q[0] = poly[0];
                for(i=1;i<=m;i++){
                   q[i] = (q[i-1]*x)+poly[i];
                }

                printf("\n Coefficients of quotient are: \n");
                for(i=0;i<m;i++){
                    printf("\t%d",q[i]);
                }
                printf("\n Remainder is: %d", q[m]);
                return 0;

}
