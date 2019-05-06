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
	tests = fopen_s(&tests,"t1", "r");
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
		Compare(&a, &b);
		printf(" ')'.\n");
		printf("The amounts of '[' is ");
		Compare(&c, &d);
		printf(" ']'.\n");
		printf("The amounts of '{' is ");
		Compare(&e, &f);
		printf(" '}'.\n");
		
		/*do
		{
			for (int i = 0; i <= q; i++)
			{
				str[i] = fgetc(tests);
				/*ch = fgetc(tests);
				putch(ch);
			}
		} while (str != EOF);
		
		char dest[p];
		char best[p];
		char cest[p];
		char aest[p];
		int j = 0;
		for (j; j <= q; j++)
		{
			if (str[j] == '(' || '[' || '{')
			{
				n++;
				char *z;
				char *y;
				z = str;
				y = dest;
				for (int i = 0; i <= j; i++)
				{
					dest[i] = *z++;
				}
				strcat_s(dest, p, num);
				strcat_s(dest ,p, z);
				for (int k = 0; k <= n; k++)
				{
					for (int i = 0; i <= j+1; i++)
					{
						dest[i] = *y++;
					}
					strcat_s(dest, p, mem);
					strcat_s(dest, p, y);
					strcpy_s(aest, p, dest);
				}
			}
			else if (dest[j] == ')' || ']' || '}')
			{
				char *z;
				char *y;
				z = aest;
				for (int l = 0; l < j; l++)
				{
					best[l] = *z++;
				}
				strcat_s(best, p, num);
				strcat_s(best, p, z);
				for (int l = n; l >= 0; l--)
				{
					{
						best[l] = *y++;
					}
					strcat_s(best, p, mem);
					strcat_s(best, p, y);
					strcpy_s(aest, p, dest);
				}
			}
			else
			{
				char *z;
				char *y;
				z = aest;
				for (int k = 0; k <= n; k++)
				{
					for (int i = 0; i <= j; i++)
					{
						cest[i] = *y++;
					}
					strcat_s(cest, p, mem);
					strcat_s(cest, p, y);
					strcpy_s(aest, p, dest);
				}
			}
		}
		printf("%s", aest);*/
		fclose(tests);
	}
}

void Compare(int *i, int *j)
{
	if (*i == *j)
	{
		printf("equal to");
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
