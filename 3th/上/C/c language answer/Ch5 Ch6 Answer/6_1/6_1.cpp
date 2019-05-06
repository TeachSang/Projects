#include<stdio.h>

void main()
{
	int src,dst,s;
	scanf("%d",&src);
	dst=0;
	if(src>=10)
	{
		while(src>=10)
		{
			s=src%10;
			dst=10*dst+s;
			src=src/10;
		}
		dst=dst*10+src;
		printf("%d\n",dst);
	}
	else printf("%d\n",src);
}