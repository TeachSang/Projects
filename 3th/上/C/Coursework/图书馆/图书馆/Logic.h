#pragma once
/*
业务逻辑处理
*/
#ifndef Logic_h
#define Logic_h
#include<stdio.h>
#include"Database.h"

//运行主菜单
void runMain(BookList* booklist);

//运行借阅菜单
void runBorrow(BookList* booklist);

//运行归还菜单
void runReturn(BookList* booklist);

//运行detail菜单
void runDetail(BookList* booklist);

//运行管理员运行菜单
void runRegister_superior(BookList* booklist);

//判断是否还书
void Change_Book_Borrow(Book book, BookList* booklist);

//判断书是否已换
void Change_Book_return(Book book, BookList* booklist);

//功能添加新书籍
void AddNewBook(BookList* List);

//功能删除已有书籍
void DeleteNewBook(BookList* List);

#endif // !Logic_h
