#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define p 1000
void Compare(int *i, int *j);
int main()
{
	FILE *tests;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int q = 0;
	int ch;
	int m = 0, n = 0;
	char str[p];
	char num = "\n";
	char mem = "	";
	tests = fopen("t1", "r");
	if (tests != NULL)
	{
		char lineOfText[100];
		while (fgets(lineOfText, 100, tests) != NULL)
		{
			q++;
			if (strstr(lineOfText, "(") != NULL)
			{
				a++;
			}
			if (strstr(lineOfText, ")") != NULL)
			{
				b++;
			}
			if (strstr(lineOfText, "[") != NULL)
			{
				c++;
			}
			if (strstr(lineOfText, "]") != NULL)
			{
				d++;
			}
			if (strstr(lineOfText, "{") != NULL)
			{
				e++;
			}
			if (strstr(lineOfText, "}") != NULL)
			{
				f++;
			}
		}
		
		printf("The '(' has appeared %d times.\n", a);
		printf("The ')' has appeared %d times.\n", b);
		printf("The '[' has appeared %d times.\n", c);
		printf("The ']' has appeared %d times.\n", d);
		printf("The '{' has appeared %d times.\n", e);
		printf("The '}' has appeared %d times.\n", f);
		printf("\n-----------------------------------------------------\n");
		printf("The amounts of '(' is ");
		Compare(&a,&b);
		printf(" ')'.\n");
		printf("The amounts of '[' is ");
		Compare(&c, &d);
		printf(" ']'.\n");
		printf("The amounts of '{' is ");
		Compare(&e, &f);
		printf(" '}'.\n");
	
		do
		{
			for(int i = 0;i <= q; i++)
			{
				str[i]= fgetc(tests);
				ch = fgetc(tests);
				putch(ch);
			}
		}while (ch != EOF);
		char dest[p];
		char best[p];
		int j = 0;
		for (j; j <= q; j++)
		{
			if (str[j] == '(' || '[' || '{')
			{
				n++;
				char *z;
				char *y;
				z = str;
				for (int i = 0; i <= j; i++)
				{
					dest[i] = *z++;
				}
				strcat(dest, num);
				strcat(dest, z);
				for (int k = 0; k <= n; k++)
				{
					for (int i = 0; i <= j; i++)
					{
						dest[i] = *y++;
					}
					strcat(dest, mem);
					strcat(dest, y);
				}
			}
			else if (str[j] == ')' || ']' || '}')
			{
				char *z;
				char *y;
				z = str;
				for (int l = 0; l < j; l++)
				{
					best[l] = *z++;
				}
				strcat(best, num);
				strcat(best, z);
				for (int l = n; l >= 0; l--)
				{
					{
						best[l] = *y++;
					}
					strcat(best, mem);
					strcat(best, y);
				}
			else
			{
				for (int l = n; l >= 0; l--)
				{
					{
						best[l] = *y++;
					}
					strcat(best, mem);
					strcat(best, y);
				}
			}
			}
		}
		strcpy(dest, best);
		printf("%s", dest);
		fclose(tests);
	}
}

void Compare(int *i, int *j)
{
	if (*i == *j)
	{
		printf( "equal to");
	}
	else if (*i > *j)
	{
		printf("more than");
	}
	if (*i < *j)
	{
		printf("less than");
	}
}
