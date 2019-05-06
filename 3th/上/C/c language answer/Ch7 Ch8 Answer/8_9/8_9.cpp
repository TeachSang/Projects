#include <stdio.h>
#include <string.h>
void main(){
	float price;
	int temp;
	printf("Please input the cost with the format \"RRRR.PP\"\n");
	scanf("%f",&price);
	temp=price/1000.0;
	if(temp){
		switch(temp){
		case 0:
			break;
		case 1:
			printf("ONE ");
			break;
		case 2:
			printf("TWO ");
			break;
		case 3:
			printf("THREE ");
			break;
		case 4:
			printf("FOUR ");
			break;
		case 5:
			printf("FIVE ");
			break;
		case 6:
			printf("SIX ");
			break;
		case 7:
			printf("SEVEN ");
			break;
		case 8:
			printf("EIGHT ");
			break;
		case 9:
			printf("NINE ");
			break;
		}//End of switch
	printf("THOUSAND ");
	}//End of if
	if((int)price%1000/100.0){
		temp=(int)price%1000/100.0;
		switch(temp){
		case 0:
			break;
		case 1:
			printf("ONE ");
			break;
		case 2:
			printf("TWO ");
			break;
		case 3:
			printf("THREE ");
			break;
		case 4:
			printf("FOUR ");
			break;
		case 5:
			printf("FIVE ");
			break;
		case 6:
			printf("SIX ");
			break;
		case 7:
			printf("SEVEN ");
			break;
		case 8:
			printf("EIGHT ");
			break;
		case 9:
			printf("NINE ");
			break;
		}//End of switch
		printf("HUNDRED ");
	}//End of if
	if(((int)price%100)>=20){
		temp=(int)price%100/10.0;
		switch(temp){
		case 0:
			break;
		case 2:
			printf("TWENTY ");
			break;
		case 3:
			printf("THIRTY ");
			break;
		case 4:
			printf("FORTY ");
			break;
		case 5:
			printf("FIFTY ");
			break;
		case 6:
			printf("SIXTY ");
			break;
		case 7:
			printf("SEVENTY ");
			break;
		case 8:
			printf("EIGHTY ");
			break;
		case 9:
			printf("NINETY ");
			break;
		}//End of switch
		temp=(int)price%10;
		switch(temp){
		case 0:
			break;
		case 1:
			printf("ONE ");
			break;
		case 2:
			printf("TWO ");
			break;
		case 3:
			printf("THREE ");
			break;
		case 4:
			printf("FOUR ");
			break;
		case 5:
			printf("FIVE ");
			break;
		case 6:
			printf("SIX ");
			break;
		case 7:
			printf("SEVEN ");
			break;
		case 8:
			printf("EIGHT ");
			break;
		case 9:
			printf("NINE ");
			break;
		}//End of switch
	}//End of if
	if(((int)price%100)>=10.0){
		temp=(int)price%100;
		switch(temp){
			case 10:
				printf("TEN ");
				break;
			case 11:
				printf("ELEVEN ");
				break;
			case 12:
				printf("TWELVE ");
				break;
			case 13:
				printf("THIRTEEN ");
				break;
			case 14:
				printf("FOURTEEN ");
				break;
			case 15:
				printf("FIFTEEN ");
				break;
			case 16:
				printf("SIXTEEN ");
				break;
			case 17:
				printf("SEVENTEEN ");
				break;
			case 18:
				printf("EITHTEEN ");
				break;
			case 19:
				printf("NINETEEN ");
				break;
		}//End of switch		
	}//End of if
	if((int)(price*100)%100){
		printf("%AND PAISE ");
		price=price*100;
			if(((int)price%100)>=20){
		temp=(int)price%100/10.0;
		switch(temp){
		case 0:
			break;
		case 2:
			printf("TWENTY ");
			break;
		case 3:
			printf("THIRTY ");
			break;
		case 4:
			printf("FORTY ");
			break;
		case 5:
			printf("FIFTY ");
			break;
		case 6:
			printf("SIXTY ");
			break;
		case 7:
			printf("SEVENTY ");
			break;
		case 8:
			printf("EIGHTY ");
			break;
		case 9:
			printf("NINETY ");
			break;
		}//End of switch
		temp=(int)price%10;
		switch(temp){
		case 0:
			break;
		case 1:
			printf("ONE ");
			break;
		case 2:
			printf("TWO ");
			break;
		case 3:
			printf("THREE ");
			break;
		case 4:
			printf("FOUR ");
			break;
		case 5:
			printf("FIVE ");
			break;
		case 6:
			printf("SIX ");
			break;
		case 7:
			printf("SEVEN ");
			break;
		case 8:
			printf("EIGHT ");
			break;
		case 9:
			printf("NINE ");
			break;
		}//End of switch
	}//End of if
	if(((int)price%100)>=10.0){
		temp=(int)price%100;
		switch(temp){
			case 10:
				printf("TEN ");
				break;
			case 11:
				printf("ELEVEN ");
				break;
			case 12:
				printf("TWELVE ");
				break;
			case 13:
				printf("THIRTEEN ");
				break;
			case 14:
				printf("FOURTEEN ");
				break;
			case 15:
				printf("FIFTEEN ");
				break;
			case 16:
				printf("SIXTEEN ");
				break;
			case 17:
				printf("SEVENTEEN ");
				break;
			case 18:
				printf("EITHTEEN ");
				break;
			case 19:
				printf("NINETEEN ");
				break;
		}//End of switch		
	}//End of if
	}//End of if
printf("\n");


}//End of main