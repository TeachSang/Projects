#include <stdio.h>
void main()
{
	int i,j;
	int p[10][10];
	for(i=0;i<10;i++){
		for(j=0;j<=i;j++){
			if(j==0)
				p[i][j]=1;
			else if(j==i)
				p[i][j]=1;
			else 
				p[i][j]=p[i-1][j-1]+p[i-1][j];
		}//End of for
	}//End of for
	for(i=0;i<10;i++){
		for(j=0;j<=i;j++)
			printf("%-3d ",p[i][j]);
		printf("\n");
	}//End of for

}//End of main