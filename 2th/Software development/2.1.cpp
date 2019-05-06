#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main()
{
	FILE *FP;
	FP = fopen("t3", "r");
	if (FP == NULL)
	{
		printf_s("Can not open the file!\n");
		return 0;
	}

	int spaceCount = 0;
	char read;
	int flag = 0;
	while (!feof(FP))
	{
		read = fgetc(FP);
		if ((read == '(') || (read == '[') || (read == '{'))
		{
			if (flag == 1)
			{
				printf_s("\n");
			}
			for (int i = 0; i < spaceCount; i++)
			{
				printf(" ");
			}
			printf_s("%c\n", read);
			spaceCount++;
			flag = 0;
		}
		else if ((read == ')') || (read == ']') || (read == '}'))
		{
			if (flag == 0)
			{
				for (int i = 0; i < spaceCount - 1; i++)
				{
					printf(" ");
				}
				printf_s("%c\n", read);
				spaceCount--;
				flag = 0;
			}
			else if (flag == 1)
			{
				printf_s("\n");
				for (int i = 0; i < spaceCount - 1; i++)
				{
					printf(" ");
				}
				printf_s("%c\n", read);
				spaceCount--;
				flag = 0;
			}
		}
		else if(isprint(read) != 0)
		{
			if (flag == 1)
			{
				printf_s("%c", read);
			}
			else if (flag == 0)
			{
				flag = 1;
				for (int i = 0; i < spaceCount; i++)
				{
					printf_s(" ");
				}
				printf_s("%c", read);
			}
		}
		else if ((read == '\n') && (flag == 1))
		{
			printf_s("%c",read);
			flag = 0;
		}
	}
	fclose(FP);
}

