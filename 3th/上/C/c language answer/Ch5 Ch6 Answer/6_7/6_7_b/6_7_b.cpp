#include<stdio.h>
void main()
{
	int row,col;
	for(row=5;row>0;row--){
		for(col=5;col>0;col--){
			if(row<col)
				printf(" ");
			else
				printf("*");
			
		}
		printf("\n");
	}
}
