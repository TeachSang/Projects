#include<stdio.h>
#define max 80 

int main()
{
	char s[max];
	int num[max];
	scanf_s("%s", s);
	int t = 0;
	if (s[0] == 'O')
	{
		num[0] = 1;
	}
	else
	{
		num[0] = 0;
	}
	t = t + num[0];
	for (int i = 0; i < max; i++)
	{
		if (s[i] = 'O'&&s[i - 1] != 'O')
		{
			num[i] = 1;
			t = t + num[i];
		}
		else if (s[i] = 'O' && s[i - 1] == 'O')
		{
			num[i] = num[i] + 1;
			t = t + num[i];
		}
	}
	printf("%d", t);
	return 0;
}