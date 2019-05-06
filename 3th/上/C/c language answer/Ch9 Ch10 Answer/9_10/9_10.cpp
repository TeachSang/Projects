#include <stdio.h>
#include <math.h>
float Perimeter(float a,float b,float c);
float Area(float s,float a,float b,float c);

void main(){
	float a,b,c;
	float Pe,Ara,s;
	printf("Please input three sides of a triangle:\n");
	scanf("%f%f%f",&a,&b,&c);
	Pe=Perimeter(a,b,c);
	s=(a+b+c)/2.0;
	Ara=Area(s,a,b,c);
	printf("The perimeter of this triangle is %f.\nThe Area of this triangle is %f.\n",Pe,Ara);
}//End of main

float Perimeter(float a,float b,float c){
	return (a+b+c);
}//End of Perimeter
float Area(float s,float a,float b,float c){
	float z,a1,b1,c1;
	a1=s-a;
	b1=s-b;
	c1=s-c;
	z=sqrt(a1*b1*c1);
	return z;
}//End of Area
