#include <stdio.h>

struct vector{
	int v1;
	int v2;
	int v3;
	int v4;
	int	v5;
};

void main(){
	struct vector vector1={10,20,30,40,50};
	printf("(%d,%d,%d,%d,%d)\n",vector1.v1,vector1.v2,vector1.v3,vector1.v4,vector1.v5);
	vector1.v1=20;
	printf("(%d,%d,%d,%d,%d)\n",vector1.v1,vector1.v2,vector1.v3,vector1.v4,vector1.v5);
	vector1.v1*=5;
	vector1.v2*=5;
	vector1.v3*=5;
	vector1.v4*=5;
	vector1.v5*=5;
	printf("(%d,%d,%d,%d,%d)\n",vector1.v1,vector1.v2,vector1.v3,vector1.v4,vector1.v5);

}//End of main
