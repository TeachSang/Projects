#include"Register.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

Superior_List* inList()
{
	Superior_List* superList = (Superior_List*)malloc(sizeof(Superior_List));
	superList->head = NULL;
	superList->No = 0;
	return superList;
}

SuperiorNode* creatSuperiorNode(Superior super)
{
	SuperiorNode* superNode = (SuperiorNode*)malloc(sizeof(SuperiorNode));
	superNode->superior = super;
	superNode->next_superior = NULL;
	return superNode;
}

Superior_List* AddUser(FILE* file)
{
	if (!file)
	{
		printf("Fail to open file\n");
		return NULL;
	}
	Superior_List* superList = inList();
	while (1)
	{
		char Lineoftext[LENGTH];
		Superior S_User = { "","" };
		char* ret = fgets(Lineoftext, sizeof(Lineoftext), file);
		if (ret == NULL)
		{
			break;
		}
		sscanf(Lineoftext, "%s %s", S_User.User_Name, S_User.User_ID);
		SuperiorNode* superNode = creatSuperiorNode(S_User);
		AddtoSuperList(superList, superNode);
	}
	return superList;
}

void AddtoSuperList(Superior_List* List, SuperiorNode* Node)
{
	SuperiorNode* pHead=List->head;
	if (List->No == 0)
	{
		List->head = Node;
	}
	else
	{
		while (pHead->next_superior)
		{
			pHead = pHead->next_superior;
		}
		pHead->next_superior = Node;
	}
	List->No++;
}

void Add_INFO_List(Superior_List* List)
{
	char Name[LENGTH];
	char ID[LENGTH];
	printf("Please enter the new User's Name:\n");
	scanf("%s",Name);
	printf("Please enter the new User's ID\n");
	scanf("%s", ID);
	Superior super;
	strcpy(super.User_Name, Name);
	strcpy(super.User_ID, ID);
	SuperiorNode* Node = creatSuperiorNode(super);
	if (List->head==NULL)
	{
		List->head = Node;
	}
	else
	{
		SuperiorNode* pHead = List->head;
		while (1)
		{
			if (pHead == NULL)
				break;
			pHead = pHead->next_superior;
		}
		pHead->next_superior = Node;
	}
}