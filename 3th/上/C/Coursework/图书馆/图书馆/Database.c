#include<stdio.h>
#include"Book.h"
#include"Database.h"
#include<string.h>
#include<stdlib.h>


BookNode* creatNode(Book book)
{
	BookNode* Node = (BookNode*)malloc(sizeof(BookNode));
	Node->book = book;
	Node->Nextbook = NULL;
	return Node;
}

BookList* initiateBookList()
{
	BookList* booklist=(BookList*)malloc(sizeof(BookList));
	booklist->headbook = NULL;
	booklist->No = 0;
	return booklist;
}

BookList* AddBook(FILE* file)
{
	if (!file)
	{
		printf("Fail to open File\n");
		return NULL;
	}
	BookList* booklist = initiateBookList();
	while (1)
	{
		char Lineoftext[200];
		Book book = { " "," ","",""};
		char* ret = fgets(Lineoftext, sizeof(Lineoftext), file);
		if (ret == NULL)
		{
			break;
		}
		int i = 0;
		while (1) 
		{
			if (Lineoftext[i] != '\n')
				i++;
			else if (i > 200)
				break;
			else 
			{
				Lineoftext[i] = '\0';
				break;
			}
		}
		sscanf(Lineoftext, "%[^/]/%[^/]/%[^/]/%[^/]", book.name, book.bookID, book.category, book.isBorrowed);
		BookNode* booknode = creatNode(book);
		AddtoBookindex(booklist, booknode);
	}
	return booklist;
}
/*
按照书的ID进行排序
*/
void AddtoBookindex(BookList* booklist, BookNode* booknode)
{
	BookNode* p=booklist->headbook;
	if (p == NULL)
	{
		booklist->headbook = booknode;
	}
	else if (strcmp(p->book.bookID,booknode->book.bookID)==1)//p->book.bookID > booknode->book.bookID
	{
		booknode->Nextbook = p;
		booklist->headbook = booknode;
	}
	else
	{
		BookNode* current = p;
		BookNode* previous = NULL;
		int found = 1;
		while (strcmp(current->book.bookID,booknode->book.bookID)==-1)
		{
			previous = current;
			current = current->Nextbook;
			if (current == NULL)
			{
				found = 0;
				break;
			}
		}
		if (found == 1)
		{
			previous->Nextbook = booknode;
			booknode->Nextbook = current;
		}
		else
		{
			previous->Nextbook = booknode;
		}
	}
	booklist->No++;
}

void DeleteBook(BookList* booklist, Book book)
{
	BookNode* head = booklist->headbook;
	while (strcmp(head->Nextbook->book.name, book.name) != 0)
	{
		head = head->Nextbook;
	}
	BookNode* NextNode=head->Nextbook;
	head->Nextbook = NextNode->Nextbook;
	booklist->No--;
}

void ChangeBookName(BookList* booklist, char* Old_bookname, char* New_bookname)
{
	BookNode* pHead;
	pHead = booklist->headbook;
	int found=0;
	while (1)
	{
		if (strcmp(pHead->book.name, Old_bookname) == 0)
		{
			found = 1;
			break;
		}
		if (pHead->Nextbook == NULL)
		{
			break;
		}
		pHead = pHead->Nextbook;
	}
	if (found == 1)
	{
		setBookName(&(pHead->book), New_bookname);
	}
	else
	{
		printf("Sorry the book you ordered is not in the list\n\n");
	}
}

void ChangeBookID(BookList* booklist, char* Old_bookid, char* New_bookid)
{
	BookNode* pHead;
	pHead = booklist->headbook;
	int found = 0;
	while (1)
	{
		
		if (strcmp(pHead->book.bookID, Old_bookid) == 0)
		{
			found = 1;
			break;
		}
		if (pHead->Nextbook == NULL)
		{
			break;
		}
		pHead = pHead->Nextbook;
	}
	if (found == 1)
	{
		setBookName(&(pHead->book), New_bookid);
	}
	else
	{
		printf("Sorry the book you ordered is not in the list\n\n");
	}
}

void ChangeBookborrow(BookList* booklist, char* BookID)
{
	BookNode* pHead;
	pHead = booklist->headbook;
	int found = 0;
	while (1)
	{
		if (strcmp(pHead->book.bookID, BookID) == 0)
		{
			found = 1;
			break;
		}
		if (pHead->Nextbook == NULL)
		{
			break;
		}
		pHead = pHead->Nextbook;
	}
	if (found == 1)
	{
		setBookBorrow(&(pHead->book));
	}
	else
	{
		printf("Sorry the book you ordered is not in the list\n\n");
	}
}

Book searchfor_a_Book_Name(BookList* booklist, char* BookName)
{
	BookNode* pHead;
	pHead = booklist->headbook;
	int found = 0;
	while (1)
	{
		
		if (strcmp(pHead->book.name, BookName) == 0)
		{
			found = 1;
			break;
		}
		if (pHead->Nextbook == NULL)
		{
			break;
		}
		pHead = pHead->Nextbook;
	}
	if (found == 1)
	{
		return pHead->book;
	}
	else
	{
		Book book = { "","","",""};
		return book;
	}
}

Book searchfor_a_Book_ID(BookList* booklist, char* BookID)
{
	BookNode* pHead;
	pHead = booklist->headbook;
	int found = 0;
	while (1)
	{
		
		if (strcmp(pHead->book.bookID, BookID) == 0)
		{
			found = 1;
			break;
		}
		if (pHead->Nextbook == NULL)
		{
			break;
		}
		pHead = pHead->Nextbook;
	}
	if (found == 1)
	{
		return pHead->book;
	}
	else
	{
		Book book = { "","",""};
		//printf("Sorry the book you ordered is not in the list");
		return book;
	}
}

void PrintBook_category(BookList* booklist, char* wanted_Category)
{
	BookNode* pHead;
	pHead = booklist->headbook;
	int flag = 0;
	while (1)
	{
		if (strcmp(pHead->book.category, wanted_Category) == 0)
		{
			flag = 1;
			printf("%-30s%-15s%-10s%-5s\n", pHead->book.name, pHead->book.bookID, pHead->book.category, pHead->book.isBorrowed);
		}
		if (pHead->Nextbook == NULL)
		{
			break;
		}
		pHead = pHead->Nextbook;
	}
	if (flag == 0)
	{
		printf("There is no such category!\n\n");
	}
}

void PrintBook_unBorrowed(BookList booklist)
{
	BookNode* pHead;
	pHead = booklist.headbook;
	while (1)
	{
		
		if (strcmp(pHead->book.isBorrowed,"NO")==0)
		{
			printf("%-30s%-15s%-10s\n", pHead->book.name, pHead->book.bookID,pHead->book.category);
		}
		if (pHead->Nextbook == NULL)
		{
			break;
		}
		pHead = pHead->Nextbook;
	}
}

void PrintDetailofBook(BookList* booklist)
{
	BookNode* pHead;
	pHead = booklist->headbook;
	while (pHead)
	{
		printf("%-30s%-15s%-10s%-5s\n", pHead->book.name, pHead->book.bookID, pHead->book.category, pHead->book.isBorrowed);
		pHead = pHead->Nextbook;
	}
}

void Enter(FILE* file, BookList* booklist)
{
	BookNode* pHead = booklist->headbook;
	while (1)
	{
		fprintf(file, "%s/%s/%s/%s\n", pHead->book.name, pHead->book.bookID,pHead->book.category,pHead->book.isBorrowed);
		if (pHead->Nextbook == NULL)
			break;
		pHead = pHead->Nextbook;
	}
}