void formattedOutput(FILE* fp)
{
	int counts = 0;									// count the number of spaces 
	char ch;

	while ((ch = fgetc(fp)) != EOF)					// get a character from file pointer						
	{
		if (ch == '(' || ch == '[' || ch == '{')	// if meet the open brackets 
		{
			for (int i = 0; i < counts; i++)
			{
				printf("  ");
			}
			printf("%c", ch);
			counts++;


			/* if next character chn is a letter, a number or a space
			we should print some spaces extra */
			char chn = fgetc(fp);
			if (chn == EOF)
				break;
			if (isalnum(chn) != 0 || chn == ' ')
			{
				printf("\n");
				for (int i = 0; i < counts; i++)
					printf("  ");
			}
			else
				printf("\n");
			fseek(fp, -1, SEEK_CUR);
		}




		else if (ch == ')' || ch == ']' || ch == '}')	// if meet the close brackets 
		{
			counts--;
			if (counts < 0)
				counts = 0;
			for (int i = 0; i < counts; i++)
			{
				printf("  ");
			}
			printf("%c", ch);


			/* if next character chn is a letter, a number or a space
			we should print some spaces extra */
			char chn = fgetc(fp);
			if (chn == EOF)
				break;
			if (isalnum(chn) != 0 || chn == ' ')
			{
				printf("\n");
				for (int i = 0; i < counts; i++)
					printf("  ");
			}
			else
				printf("\n");
			fseek(fp, -1, SEEK_CUR);
		}




		else if (ch == '\n')							// if meet the '\n'
		{
			printf("\n");


			/* if next character chn is a letter, a number or a space
			we should print some spaces extra */
			char chn = fgetc(fp);
			if (chn == EOF)
				break;
			if (isalnum(chn) != 0 || chn == ' ')
			{
				for (int i = 0; i < counts; i++)
					printf("  ");
			}
			fseek(fp, -1, SEEK_CUR);
		}




		else if ((isalnum(ch)) != 0 || ch == ' ')			// if meet a letter, a number or a spaces
		{
			printf("%c", ch);


			/* if next character chn is a bracket
			we should go to the next line */
			char chn = fgetc(fp);
			if (chn == EOF)
				break;
			if (chn == '(' || chn == '[' || chn == '{' || chn == ')' || chn == ']' || chn == '}')
			{
				printf("\n");
			}
			fseek(fp, -1, SEEK_CUR);
		}
	}
	fseek(fp, 0, SEE);
}