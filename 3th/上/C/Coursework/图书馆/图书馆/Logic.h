#pragma once
/*
ҵ���߼�����
*/
#ifndef Logic_h
#define Logic_h
#include<stdio.h>
#include"Database.h"

//�������˵�
void runMain(BookList* booklist);

//���н��Ĳ˵�
void runBorrow(BookList* booklist);

//���й黹�˵�
void runReturn(BookList* booklist);

//����detail�˵�
void runDetail(BookList* booklist);

//���й���Ա���в˵�
void runRegister_superior(BookList* booklist);

//�ж��Ƿ���
void Change_Book_Borrow(Book book, BookList* booklist);

//�ж����Ƿ��ѻ�
void Change_Book_return(Book book, BookList* booklist);

//����������鼮
void AddNewBook(BookList* List);

//����ɾ�������鼮
void DeleteNewBook(BookList* List);

#endif // !Logic_h
