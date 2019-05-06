#include "stdio.h"
#include "math.h"

int main()
{
	/*To declear variables*/
	float a, b, c;
	float x1;
	float x2;
	float ans;

	/*To get a,b,c*/
	printf("Please input 'a','b','c'\n");
	scanf("%f %f %f", &a, &b, &c);

	/*Judge abc*/
	if (a == 0 && b == 0) {
		printf("No answer.");
	}
	else if (a == 0) {
		ans = -c / b;
		printf("The answer is %f", ans);
	}
	else if ((b*b - 4 * a*c) < 0) {
		printf("No real root.");
	}
	else {
		x1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
		x2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
		printf("The answer is %f and %f", x1, x2);
	}
}
