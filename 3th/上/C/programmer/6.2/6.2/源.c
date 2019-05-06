#include"stdio.h"

int main()
{
	/*declear variables*/
	int array[100];
	int m;
	int n = 2;

	/*to get the m*/
	printf("Please input the m:\n");
	scanf("%d", &m);

	array[0] = 1;
	array[1] = 1;

	/*The calculate progress*/
	do
	{
		array[n] = array[n-1] + array[n-2];
		n++;
	} while (n < m);

	printf("The m is: %d", array[m - 1]);
}