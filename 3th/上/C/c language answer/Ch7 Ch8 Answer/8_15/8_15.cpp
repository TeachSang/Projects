#include <stdio.h>
#include <string.h>
void main(){
	char str[]="123456789";
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5-i-1;j++)
			printf("  ");
		for(j=i;j<2*i+1;j++)
			printf("%c ",str[j]);
		for(j=2*i;j>i;j--)
			printf("%c ",str[j-1]);
		printf("\n");		
	}//End of for
}//End of main
