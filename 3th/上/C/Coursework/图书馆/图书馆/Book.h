#pragma once
#ifndef Book_h
#define Book_h

#include<stdio.h>

#define CHARLENGTH 50

//设计数据模型
typedef struct {
	char name[CHARLENGTH]; //书名
	char bookID[CHARLENGTH]; //书的变化
	char isBorrowed[CHARLENGTH];//书的借阅状态 默认为NO
	char category[CHARLENGTH];
}Book;


//修改书名
void setBookName(Book* pBook, char* name);

//获取书名
char* getBookName(Book pBook);

//修改书的编号
void setBookID(Book* pBook, char* ID);

//获取书的编号
char* getBookID(Book pBook);

//修改书的借阅状态
void setBookBorrow(Book* pBook);

//获取书的借阅状态
char* getBookBorrow(Book pBook);

#endif // !Book_h

