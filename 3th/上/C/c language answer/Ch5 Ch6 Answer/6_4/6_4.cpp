#include<stdio.h>
void main()
{
	int m,n,sum,y;
	scanf("%d",&m);
	n=0;
	sum=1;
	y=1;
	do{
		printf("%d ",sum);
		sum=sum+n;
		n=y;
		y=sum;
		m=m-1;
	}while(m>0);
	printf("\n");
}
