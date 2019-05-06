#include"stdio.h"

void main()
{
	/*declear the valuables*/
	char str[] = "123456789";
	int num = 0;
	int t = 0;

	/*transform it*/
	num = sizeof(str)-1;
	printf("The size of string is: %d\n", num);
	t = num / 2;

	for (int i=0; i<=t; i++)
	{
		for (int j = 1; j<=t-i; j++) {
			printf(" ");
		}
		for (int k = 0; k <= i; k++) {
			printf("%c", str[k+i]);
		}
		for (int k = i; k>0; k--) {
			printf("%c", str[k + i-1]);
		}
		printf("\n");
	}
}