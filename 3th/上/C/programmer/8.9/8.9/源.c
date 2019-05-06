#include"stdio.h"

char b[100] = "";

int main()
{
	/*Declear the varibles*/
	char a[128];
	int money_i, money_j;
	float money;	

	/*to get the number*/
	printf("Please input the money:");
	scanf("%f", &money);

	/*arrange money*/
	money_i = (int)money;
	money_j = (int)((money - money_i) * 100);

	/*print the money*/
	toword(money_i, money_j);
	puts(b);
}

int toword(int money_i,int money_j)
{
	char ge[10][10] = { "ZERO ","ONE ","TWO ","THREE ","FOUR ","FIVE ","SIX ","SEVEN ","EIGHT ","NINE " };
	char shi[10][10] = { "","ELVEN ","TWELVE ","THRITEEN ","FOURTEEN ","FIFTEEN ","SIXTEEN ","SEVENTEEN ","EIGHTEEN ","NINTEEN " };
	char bai[10][10] = { "TEN ","TWENTY ","THIRTY ","FORTY ","FIFTY ","SIXTY ","SEVENTY ","EIGHTY ","NINTY " };

	/*bigger than 0*/
	if ((money_i / 100) != 0) {
		strcat(b, ge[money_i / 100 % 10]);
		strcat(b, "HUNDARD ");

		if ((money_i / 10 % 10) < 2) {
			strcat(b, "AND ");
			strcat(b, shi[money_i % 10]);
		}
		else {
			strcat(b, bai[money_i / 10 % 10 - 1]);
			if ((money_i % 10) == 0) {
			}
			else {
				strcat(b, ge[money_i % 10]);
			}
		}
	}
	else
	{
		if ((money_i / 10 % 10) < 2) {
			strcat(b, shi[money_i % 10]);
		}
		else {
			strcat(b, bai[money_i / 10 % 10 - 1]);
			if ((money_i % 10) == 0) {
			}
			else {
				strcat(b, ge[money_i % 10]);
			}
		}
	}

	/*smaller than 0*/
	if (money_j == 0)
	{
	}
	else if (money_j / 10 == 0) {
		strcat(b, "AND ");
		strcat(b, ge[money_j % 10 + 1]);
	}
	else if (money_j / 10 < 2) {
		strcat(b, "AND ");
		strcat(b, shi[money_j % 10]);
	}
	else {
		if (money_j % 10 == 0) {
			strcat(b, "AND ");
			strcat(b, bai[money_j / 10 % 10 - 1]);
		}
		else{
			strcat(b, "AND ");
			strcat(b, bai[money_j / 10 % 10 - 1]);
			strcat(b, ge[money_j % 10]);
		}
	}
	
}