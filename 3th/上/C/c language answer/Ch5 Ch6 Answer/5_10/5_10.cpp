#include<stdio.h>
#include<math.h>
void main()
{   
    double a,b,c;
	printf("Input a b c of ax^2+bx+c=0\n");
	scanf("%lf %lf %lf",&a,&b,&c);
	{
		if (a==0.0&&b==0.0){
		printf("No solution\n");
		}
		else if (a==0.0){
		printf("There is only one root, the root is %lf\n",-c/b);
		}
		else if (b*b-4*a*c<0){
		printf("There is no real solution\n");
		}
		else
	    printf("x1=%lf  x2=%lf\n",(-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a));
	}
}