#include <stdio.h>
#include <string.h>
void stringCpy(char *p1,char *p2);
int stringCmp(char *p1,char *p2);
void stringAppend(char *p1,char *p2);

void main(){
	char s1[20]="New1";
	stringCpy(s1,"NEW ");
	printf("stringCpy test result is: %s\n",s1);
	char s2[20]="DeLHI";
	char s3[20]="DELHI";
	printf("stringCmp test result is: %d\n",stringCmp(s2,s3));
	stringAppend(s1,s3);
	printf("stringAppend test result is: %s\n",s1);
}//End of main

void stringCpy(char *p1,char *p2){
	int i;
	for(i=0;p2[i]!='\0';i++){
		p1[i]=p2[i];
	}//End of for
	p1[i]='\0';

}//End of stringCpy

int stringCmp(char *p1,char *p2){
	int i=0;
	while(p1[i]!='\0'){
		if(p1[i]==p2[i]){
			i++;
		}//End of if 
		else 
			return p1[i]-p2[i];
	}//End of while
	return 0;
}//End of stringCmp

void stringAppend(char *p1,char *p2){
	int i,j;
	for(i=strlen(p1),j=0;p2[j]!='\0';j++)
	{
		p1[i+j]=p2[j];
	}//End of for
	p1[i+j]='\0';
}//End of stringAppend