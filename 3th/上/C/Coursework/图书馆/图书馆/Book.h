#pragma once
#ifndef Book_h
#define Book_h

#include<stdio.h>

#define CHARLENGTH 50

//�������ģ��
typedef struct {
	char name[CHARLENGTH]; //����
	char bookID[CHARLENGTH]; //��ı仯
	char isBorrowed[CHARLENGTH];//��Ľ���״̬ Ĭ��ΪNO
	char category[CHARLENGTH];
}Book;


//�޸�����
void setBookName(Book* pBook, char* name);

//��ȡ����
char* getBookName(Book pBook);

//�޸���ı��
void setBookID(Book* pBook, char* ID);

//��ȡ��ı��
char* getBookID(Book pBook);

//�޸���Ľ���״̬
void setBookBorrow(Book* pBook);

//��ȡ��Ľ���״̬
char* getBookBorrow(Book pBook);

#endif // !Book_h

