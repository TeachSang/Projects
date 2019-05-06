#pragma once
/*
���ݴ洢�߼�����ɾ�Ĳ飩
*/
#ifndef Database_h
#define Database_h
#include<stdio.h>
#include"Book.h"

struct Node{
	Book book;
	struct Node* Nextbook;
};

typedef struct Node BookNode;

typedef struct {
	int No;
	BookNode* headbook;
}BookList;


//�������������Ϣ
BookNode* creatNode(Book book);

//��ʼ���鵥
BookList* initiateBookList();

//�ӱ����ļ��е�ȡ���������Ϣ
BookList* AddBook(FILE* file);

//����鼮
void AddtoBookindex(BookList* booklist, BookNode* booknode);

//ɾ���鼮
void DeleteBook(BookList* booklist, Book book);

//�޸��������
void ChangeBookName(BookList* booklist, char* Old_bookname, char* New_bookname);

//�޸����ID
void ChangeBookID(BookList* booklist, char* Old_bookid, char* New_bookid);

//�޸���Ľ���״̬
void ChangeBookborrow(BookList* booklist, char* BookName);

//����������
Book searchfor_a_Book_Name(BookList* booklist, char* BookName);

//����Ų���
Book searchfor_a_Book_ID(BookList* booklist, char* BookID);

void PrintBook_category(BookList* booklist, char* wanted_Category);

//��ӡδ���ĵ��鼮
void PrintBook_unBorrowed(BookList booklist);

//��ӡ�����Ϣ
void PrintDetailofBook(BookList* booklist);

//�����ݿ�����Ϣ��������txt�ļ���
void Enter(FILE* file, BookList* booklist);

#endif // !Database_h

