#pragma once
/*
�������в˵��Ĵ�ӡ
*/
#ifndef Menue_h
#define Menue_h

#include<stdio.h>
#include"Book.h"
#include"Register.h"

//�������˵���ʽ
void mainMenue();

//����ͼ��˵�
void BorrowBookMenue();

//�黹�鼮�˵�
void ReturnBookMenue();

//�鼮��Ϣ
void ShowDetailMenue();

//ȷ���Ƿ�Ϊ����Ա��½�˵�
void Judge_Register_superior();

//����Ա��½�û�����
void Register_superior();

//���������Ϣ�˵�
char* scanfBookName();

//��������鼮�ı��
char* scanfBookId();


#endif

