#pragma once
#ifndef Register_h
#define Register_h
#include<stdio.h>
#define LENGTH 20
#define MAX_USER 30 //最大管理员数量

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

//初始化列表
Superior_List* inList();

//创建节点
SuperiorNode* creatSuperiorNode(Superior super);

//录入管理员名单（管理员有人数限定）
Superior_List* AddUser(FILE* file);

//将TXT中的名单录入动态链表中
void AddtoSuperList(Superior_List* List, SuperiorNode* Node);

//添加人员名单
void Add_INFO_List(Superior_List* List, SuperiorNode* Node);
#endif // !Register_h

