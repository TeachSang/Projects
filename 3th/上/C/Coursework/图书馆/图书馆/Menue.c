#include"Menue.h"
#include"Book.h"
#include"Register.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mainMenue() {
	printf("------Main menu----------\n");
	printf("----1.Borrow Book--------\n");
	printf("----2.Return Book--------\n");
	printf("----3.Check Book detail--\n");
	printf("----4.Admin Login in-----\n");
	printf("----5.Exist--------------\n");
}

void BorrowBookMenue()
{
	printf("------------Borrow Book----------\n");
	printf("----1.According to BookName------\n");
	printf("----2.According to BookID--------\n");
	printf("----3.Check Unborrowed Book------\n");
	printf("----4.Return to Main-------------\n");
}

void ReturnBookMenue()
{
	printf("------------Return Book---------------\n");
	printf("----1.Return According to BookID------\n");
	printf("----2.Return According to BookName----\n");
	printf("----3.Return to Main------------------\n");
}

void ShowDetailMenue()
{
	printf("------------Check For Book detail----------\n");
	printf("----1.Check According to BookName---------\n");
	printf("----2.Check According to category----------\n");
	printf("----3.Print All book datail----------------\n");
	printf("----4.Return to Main-----------------------\n");
}

void Judge_Register_superior()
{	
	int i = 0,j,flag=0;
	FILE* file = fopen("Superior.txt", "r");
	Superior_List* User_List = AddUser(file);
	char Name[LENGTH];
	char ID[LENGTH];
	while (i<3) {
		SuperiorNode* pUser = User_List->head;
		printf("Please input your Name\n");
		scanf("%s", Name);
		printf("Please input your password\n");
		scanf("%s", ID);
		while (1)
		{
			if ((strcmp(pUser->superior.User_Name, Name) == 0) && (strcmp(pUser->superior.User_ID, ID) == 0))
			{
				flag = 1;
				break;
			}
			else if (pUser->next_superior == NULL)
			{
				break;
			}
			pUser = pUser->next_superior;
		}
		if (flag==1)
			break;
		system("cls");
		printf("Your UserName or Password is wrong, please check again\n");
		i++;
	}
	if (!flag)
	{
		printf("Sorry Please check again\n");
		exit(0);
	}
}

void Register_superior()
{
	printf("-----Admin login----------------\n");
	printf("-----1.Add Book-----------------\n");
	printf("-----2.Delete Book--------------\n");
	printf("-----3.Return to Main-----------\n");
}

char* scanfBookName()
{
	printf("Please enter Book Name:\n");
	char BookName[CHARLENGTH];
	int i = 0;
	while (1)
	{
		BookName[i] = getchar();
		if (BookName[i] == '\0')
		{
			break;
		}
		i++;
	}
	BookName[i] = '\0';
	return BookName;
}

char* scanfBookId()
{
	printf("Please enter Book Name:\n");
	char Name[CHARLENGTH];
	fgets(Name, CHARLENGTH, stdin);
	return Name;
}




