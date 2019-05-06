#include"stdio.h"

int main() {
	/*declear the array*/
	int array[50];
	int num;
	int n = 0;
	
	/*to get number*/
	printf("Please input a list of integer number:\n");
	scanf("%d",&num);

	/*reverse number*/
	while (num) {
		array[n] = num % 10;
		num = num / 10;
		printf("%d", array[n]);
		n++;
	}
}