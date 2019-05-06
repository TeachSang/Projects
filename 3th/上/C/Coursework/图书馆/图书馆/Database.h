#pragma once
/*
数据存储逻辑（增删改查）
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


//创建单个书的信息
BookNode* creatNode(Book book);

//初始化书单
BookList* initiateBookList();

//从本地文件中调取所有书的信息
BookList* AddBook(FILE* file);

//添加书籍
void AddtoBookindex(BookList* booklist, BookNode* booknode);

//删除书籍
void DeleteBook(BookList* booklist, Book book);

//修改书的名字
void ChangeBookName(BookList* booklist, char* Old_bookname, char* New_bookname);

//修改书的ID
void ChangeBookID(BookList* booklist, char* Old_bookid, char* New_bookid);

//修改书的借阅状态
void ChangeBookborrow(BookList* booklist, char* BookName);

//按书名查找
Book searchfor_a_Book_Name(BookList* booklist, char* BookName);

//按编号查找
Book searchfor_a_Book_ID(BookList* booklist, char* BookID);

void PrintBook_category(BookList* booklist, char* wanted_Category);

//打印未借阅的书籍
void PrintBook_unBorrowed(BookList booklist);

//打印书的信息
void PrintDetailofBook(BookList* booklist);

//将数据库中信息重新载入txt文件中
void Enter(FILE* file, BookList* booklist);

#endif // !Database_h

