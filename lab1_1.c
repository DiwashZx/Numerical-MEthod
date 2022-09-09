#include<stdio.h>
#include<math.h>

#define f(x) x*x*x-2*x-5 

int main(){
    int count=0;
    float x0, x1, x2, y0, y1, y2, e,y3;

    printf("Enter the initial root of equation:\n");
    scanf("%f %f",&x0,&x1);

    printf("Enter error value:\n");
    scanf("%f",&e);

    y0 = f(x0);
    y1 = f(x1);

    if (y0 * y1 > 0){
        printf("Initial roots are not found\n");
    }
    else{
        while((fabs(x1-x0)/x1) > e){
            x2 = (x0+x1)/2;
            y2 = f(x2);
            count = count + 1;

            if((y0 * y2)>0){
                x0 = x2;
            }
            else{
                x1=x2;
            }
            }
            printf("Required number of iteration is: %d\n",count);
            printf("solution converse to roots:\n");
            printf("The root of given eqn is %8.2f\n",x2);

            y3 =f(x2);
            printf("Thr functional value of root is: %8.4f\n",y3);
    }
return 0;


}