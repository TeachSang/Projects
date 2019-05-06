#include<stdio.h>
void main()
{
	int amt,clot,m;
	double dsct;
	printf("Input the amount and cloth(mill is 0 and handloom is 1)\n");
	scanf("%d %d",&amt,&clot);
	switch((amt+99)/100)
	{
	case 0:
	case 1:
		if (clot==0)
			dsct=1;
		else 
			dsct=0.95;
		break;
	case 2:
		if (clot==0)
			dsct=0.95;
		else 
			dsct=0.925;
		break;
	case 3:
		if (clot==0)
			dsct=0.925;
		else 
			dsct=0.9;
           break;
	default:
		if (clot==0)
			dsct=0.9;
		else 
			dsct=0.85;
		break;
	}
	printf("the amount is %d\n",m=amt*dsct);
}

