#include"Book.h"
#include<stdio.h>
#include<string.h>

void setBookName(Book* pBook, char* name)
{
	memset(pBook->name, NULL, CHARLENGTH);
	strcpy(pBook->name, name);
	int i = 0;
	while (pBook->name[i])
	{
		i++;
	}
	pBook->name[i] = '\0';
	
}

char* getBookName(Book pBook)
{
	return pBook.name;
}

void setBookID(Book* pBook, char* ID)
{
	memset(pBook->bookID, 0, CHARLENGTH);
	strcpy(pBook->bookID, ID);
	int i = 0;
	while (pBook->bookID[i])
	{
		i++;
	}
	pBook->bookID[i] = '\0';
}

char* getBookID(Book pBook)
{
	return pBook.bookID;
}

void setBookBorrow(Book* pBook)
{
	if (strcmp(pBook->isBorrowed,"YES")==0)
	{
		strcpy(pBook->isBorrowed, "NO");
	}
	else
	{
		strcpy(pBook->isBorrowed, "YES");
	}
}

char* getBookBorrow(Book pBook)
{
	return pBook.isBorrowed;
}