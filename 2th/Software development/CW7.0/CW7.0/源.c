
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define p 1000
void formattedOutput(char A[1000]);
int main()
{
	FILE *tests;
	char ch;
	tests = fopen("t3.out", "r");
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


void formattedOutput(char chArry[1000])
{
	int counts = 0;									// count the number of spaces 
													//char ch;

	for (int i = 0; i<strlen(chArry); i++)					// get a character from file pointer						
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