#pragma once
#ifndef Register_h
#define Register_h
#include<stdio.h>
#define LENGTH 20
#define MAX_USER 30 //������Ա����

typedef struct 
{
	char User_Name[LENGTH];
	char User_ID[LENGTH];
}Superior;

struct node
{
	Superior superior;
	struct node* next_superior;
};
typedef struct node SuperiorNode;

typedef struct 
{
	SuperiorNode* head;
	int No;
}Superior_List;

//��ʼ���б�
Superior_List* inList();

//�����ڵ�
SuperiorNode* creatSuperiorNode(Superior super);

//¼�����Ա����������Ա�������޶���
Superior_List* AddUser(FILE* file);

//��TXT�е�����¼�붯̬������
void AddtoSuperList(Superior_List* List, SuperiorNode* Node);

//�����Ա����
void Add_INFO_List(Superior_List* List, SuperiorNode* Node);
#endif // !Register_h

