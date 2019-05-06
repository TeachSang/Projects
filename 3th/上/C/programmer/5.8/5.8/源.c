#include "stdio.h"

int main()
{
	/*To declear variables*/
	int price_mac = 0;
	int price_hand = 0;
	float price = 0;
	float price_1 = 0;
	float price_2 = 0;

	/*To get price of each purchase*/
	printf("Please input the price of “机械加工制品”and“手工制品”.\n");
	scanf("%d %d", &price_mac, &price_hand);

	/*To calculate the price of machine-make purchase*/
	switch (price_mac / 100) {
	case 0:
		price_1 = price_mac;
		printf("%f", price);
		break;
	case 1:
		price_1 = price_mac*0.95;
		break;
	case 2:
		price_1 = price_mac*0.925;
		break;
	default:
		price_1 = price_mac*0.9;
		break;
	}

	/*To calculate the price of hand-make purchase*/
	switch (price_hand / 100) {
	case 0:
		price_2 = price_mac*.95;
		break;
	case 1:
		price_2 = price_mac*0.925;
		break;
	case 2:
		price_2 = price_mac*0.9;
		break;
	default:
		price_2 = price_mac*0.85;
		break;
	}

	/*To calculate the total amounts*/
	price = price_1 + price_2;
	printf("The money you showed paying is: %f", price);
}
