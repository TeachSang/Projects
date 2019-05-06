#include <stdio.h>
typedef struct 
{
	int hour;
	int minute;
	int second;
}time_struct;
void main()
{
	time_struct t1;
	t1.hour=16;
	t1.minute=40;
	t1.second=51;
	printf("%d:%d:%d\n",t1.hour,t1.minute,t1.second);
}//End of main