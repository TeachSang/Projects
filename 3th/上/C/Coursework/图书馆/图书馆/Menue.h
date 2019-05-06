#pragma once
/*
负责所有菜单的打印
*/
#ifndef Menue_h
#define Menue_h

#include<stdio.h>
#include"Book.h"
#include"Register.h"

//调用主菜单样式
void mainMenue();

//借阅图书菜单
void BorrowBookMenue();

//归还书籍菜单
void ReturnBookMenue();

//书籍信息
void ShowDetailMenue();

//确认是否为管理员登陆菜单
void Judge_Register_superior();

//管理员登陆用户界面
void Register_superior();

//输入借阅信息菜单
char* scanfBookName();

//输入借阅书籍的编号
char* scanfBookId();


#endif

