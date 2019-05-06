
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define p 1000
void Compare(int i, int j);
void insert(char str1[p], char str2[p], int i);
void formattedOutput(FILE* fp);
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
	char num[] = { '\n' };
	char mem[] = { '  ' };
	tests = fopen("t8", "r");
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
		/*printf("%d\n", a + c + e + 1);/*正括号个数*/
		/*printf("%d\n", b + d + f + 1);/*反括号个数*/

		char bh;
		int y = 0;
		int cal[80];
		int bal[80];
		int bool;
		rewind(tests);
		do {
			bh = fgetc(tests);
			if (bh == '(' || bh == '[' || bh == '{')
			{
				y++;
				cal[y] = bh;

			}
			else if (bh == ']' || bh == '}')
			{
				if ((int)(cal[y]) == ((int)bh - 2))
				{
					y--;
					bool = 1;
				}
				else if ((int)(cal[y]) != ((int)bh - 2))
				{
					bool = 0;
					break;
				}
			}
			else if (bh == ')')
			{
				if ((int)(cal[y]) == ((int)bh - 1))
				{
					y--;
					bool = 1;
				}
				else if ((int)(cal[y]) != ((int)bh - 1))
				{
					bool = 0;
					break;
				}
			}
		} while (bh != EOF);
		if (bool == 1 && y == 0)
			printf("The expression is properly nested.\n");
		else
			printf("The expression is NOT properly nested.\n");


		rewind(tests);
		char chArry[p];
		int abc = 0;
		while ((ch = fgetc(tests)) != EOF)
		{
			chArry[abc] = ch;
			abc++;
		}
		int counts = 0;									// count the number of spaces 
		for (int i = 0; i < strlen(chArry); i++)					// get a character from file pointer						
		{
			if (chArry[i] == '(' || chArry[i] == '[' || chArry[i] == '{')	// if meet the open brackets 
			{
				for (int i = 0; i < counts; i++)
				{
					printf("  ");
				}
				printf("%c", chArry[i]);
				counts++;

				/* if next character chn is a letter, a number or a space
				we should print some spaces extra */

				if (chArry[i + 1] == '\0')
					break;
				if (isalnum(chArry[i + 1]) != 0 || chArry[i + 1] == ' ')
				{
					printf("\n");
					for (int i = 0; i < counts; i++)
						printf("  ");
				}
				else
					printf("\n");

			}

			else if (chArry[i] == ')' || chArry[i] == ']' || chArry[i] == '}')	// if meet the close brackets 
			{
				counts--;
				if (counts < 0)
					counts = 0;
				for (int i = 0; i < counts; i++)
				{
					printf("  ");
				}
				printf("%c", chArry[i]);


				/* if next character chn is a letter, a number or a space
				we should print some spaces extra */
				if (chArry[i + 1] == '\0')
					break;
				if (isalnum(chArry[i + 1]) != 0 || chArry[i + 1] == ' ')
				{
					printf("\n");
					for (int i = 0; i < counts; i++)
						printf("  ");
				}
				else
					printf("\n");

			}

			else if (chArry[i] == '\n')							// if meet the '\n'
			{
				printf("\n");


				/* if next character chn is a letter, a number or a space
				we should print some spaces extra */

				if (chArry[i + 1] == '\0')
					break;
				if (isalnum(chArry[i + 1]) != 0 || chArry[i + 1] == ' ')
				{
					for (int i = 0; i < counts; i++)
						printf("  ");
				}

			}

			else if ((isalnum(chArry[i])) != 0 || chArry[i] == ' ')			// if meet a letter, a number or a spaces
			{
				printf("%c", chArry[i]);


				/* if next character chn is a bracket
				we should go to the next line */

				if (chArry[i + 1] == '\0')
					break;
				if (chArry[i + 1] == '(' || chArry[i + 1] == '[' || chArry[i + 1] == '{' || chArry[i + 1] == ')' || chArry[i + 1] == ']' || chArry[i + 1] == '}')
				{
					printf("\n");
				}

			}
		}
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


void formattedOutput(char A[1000])
{
	FILE *tests;
	char ch;
	tests = fopen("t1", "r");
	if (tests != NULL)
	{
		char chArry[p];
		int abc = 0;
		while ((ch = fgetc(tests)) != EOF)
		{
			chArry[abc] = ch;
			abc++;
		}
		formattedOutput(chArry);
	}
}