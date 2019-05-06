#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define p 1000
void Compare(int i, int j);
void insert(char str1[p], char str2[p], int i);
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
	int m=0,n = 0;
	char str[p];
	char num[] = "\n";
	char mem[] = "  ";
	tests = fopen("t1", "r");
	if (tests != NULL)
	{
		char lineOfText[100];
		while ((ch = fgetc(tests)) != EOF)
		{
			q++;
			if (ch == '(')
			{
				a++;
			}
			if (ch == ')')
			{
				b++;
			}
			if (ch == '[')
			{
				c++;
			}
			if (ch == ']')
			{
				d++;
			}
			if (ch == '{')
			{
				e++;
			}
			if (ch == '}')
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
		Compare(a, b);
		printf(" ')'.\n");
		printf("The amounts of '[' is ");
		Compare(c, d);
		printf(" ']'.\n");
		printf("The amounts of '{' is ");
		Compare(e, f);
		printf(" '}'.\n");
		printf("%d\n", a + c + e + 1);/*正括号个数*/
		printf("%d\n", b + d + f + 1);/*反括号个数*/
		
		char bh;
		int y = 0;
		int cal[4];
		int bal[4];
		rewind(tests);
		do {
			bh = fgetc(tests);
			if (bh == '(')
			{
				cal[y] = 1;
				y++;
			}
			else if (bh == '[')
			{
				cal[y] = 2;
				y++;
			}
			else if (bh == '{')
			{
				cal[y] = 3;
				y++;
			}
			else if (bh == ')')
			{
				bal[y] = 1;
				y++;
			}
			else if (bh == ']')
			{
				bal[y] = 2;
				y++;
			}
			else if (bh == '}')
			{
				bal[y] = 3;
				y++;
			}
		} while (bh != EOF);
		strrev(bal);
		if (strcmp(cal, bal) == 0)
		{
			printf("The expression is properly nested.\n");
		}
		else
		{
			printf("The expression is not properly nested.\n");
		}

		char ah;/*读取文件内容到str中*/
		int i = 0;
		rewind(tests);
		do {
			ah = fgetc(tests);
			str[i] = ah;
			i++;
		} while (ah != EOF);
		for (int k = 0; k <= i; k++)
		{
			printf("%c", str[k]);
		}

		/*for (int j = 0; j <= q; j++)
		{
			if (str[j] == '(' || str[j] == '[' || str[j] == '{')
			{
				n++;
				insert(str, num, j);
				for (int k = 0; k <= n; k++)
				{
					insert(str, mem, j);
				}
			}
			else if (str[j] == ')' || str[j] == ']' || str[j] == '}')
				{
					insert(str, num, j);
					for (int l = n; l >= 0; l--)
					{
						insert(str, mem, j);
					}
				}
				else
				{
					insert(str, num, j);
					for (int k = 0; k <= n; k++)
					{
						insert(str, mem, j);
					}
				}
			}
		m = sizeof(str);
		for (int k = 0; k <= m; k++)
		{
			printf("%c", str[k]);
		}*/
			fclose(tests);
		}
}

void Compare(int i, int j)
{
	if (i == j)
	{
		printf("equal to");
	}
	else if (i > j)
	{
		printf("more than");
	}
	if (i < j)
	{
		printf("less than");
	}
}

void insert(char str1[p], char str2[p], int i)
{
	char str3[p];
	int m, n, k, l;
	l = strlen(str1);
	for (m = 0; m = i - 1; m++)
	{
		str3[m] = str1[m];
	}
	for (k = 0; str2[k] != '\0'; m++, k++)
	{
		str3[m] = str2[k];
	}
	for (n = l - i - 2; str1[n] != '\0'; m++, n++)
	{
		str3[m] = str1[n];
	}
	str3[m] = '\0';
}