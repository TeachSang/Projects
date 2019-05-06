#include"stdio.h"

int main()
{
	/*To declear the aribles*/
	FILE * file;
	int pascal[64];
	char tran;

	
	/*open file*/
	file = fopen("test.txt", "r");
	if (!file) {
		printf("The error.\n");
	}

	while (1) {
		tran = fgets(pascal, sizeof(pascal), file);
		if (!tran) {
			break;
		}
		printf("%s", pascal);
	}
}