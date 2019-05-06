#include<stdio.h>
#include<string.h>
#include"Logic.h"
#include"Menue.h"
#include"Database.h"

//Run Main menue
void runMain(BookList* booklist) {
	mainMenue();
	char BookName[CHARLENGTH];
	int Main;
	while (1) {
		scanf("%d", &Main);
		system("cls");
		//借阅
		if (Main == 1)
		{
			runBorrow(booklist);
		}
		else if (Main == 2)//归还
		{
			runReturn(booklist);
		}
		else if (Main == 3)//查看信息
		{
			runDetail(booklist);
		}
		else if (Main == 4)//管理员登陆
		{
			Judge_Register_superior();
			runRegister_superior(booklist);
		}
		else if (Main == 5)
		{
			printf("Loading in.....\n");
			FILE* file = fopen("Book.txt", "w");
			Enter(file, booklist);
			fclose(file);
			exit(0);
		}
		else
		{
			printf("Sorry there is something wrong with your entering, please try again\n");
		}
	}
}

//Run Borrow Menue
void runBorrow(BookList* booklist) {
	BorrowBookMenue();
	char Name_id[CHARLENGTH];
	Book Search_book;
	int Main;
	while (1)
	{
		fflush(stdin);
		scanf(" %d", &Main);
		if (Main == 1)
		{
			system("cls");
			printf("Please input the BookName\n");
			scanf(" %[^\n]", Name_id);
			Search_book = searchfor_a_Book_Name(booklist, Name_id);
			Change_Book_Borrow(Search_book, booklist);
			runBorrow(booklist);
		}
		else if (Main == 2)
		{
			system("cls");
			printf("Please input the BookID\n");
			scanf(" %s", Name_id);
			Search_book = searchfor_a_Book_ID(booklist, Name_id);
			Change_Book_Borrow(Search_book, booklist);
			runBorrow(booklist);	
		}
		else if (Main == 3)
		{
			system("cls");
			PrintBook_unBorrowed(*booklist);
			runBorrow(booklist);	
		}
		else if (Main == 4)
		{
			system("cls");
			runMain(booklist);
		}
		else
		{
			printf("Sorry there is something wrong with your entering, please try again\n");
		}
	}
}

//Run return Menue
void runReturn(BookList* booklist)
{
	ReturnBookMenue();
	char Name_id[CHARLENGTH];
	Book Search_book;
	int Main;
	while(1)
	{
		scanf(" %d", &Main);
		if (Main == 1)
		{
			system("cls");
			printf("Please input the BookID\n");
			scanf(" %s", Name_id);
			Search_book = searchfor_a_Book_ID(booklist, Name_id);
			Change_Book_return(Search_book, booklist);
			runReturn(booklist);
		}
		else if (Main == 2)
		{
			system("cls");
			printf("Please input the Book Name\n");
			scanf(" %[^\n]", Name_id);
			Search_book = searchfor_a_Book_Name(booklist, Name_id);
			Change_Book_return(Search_book, booklist);
			runReturn(booklist);	
		}
		else if (Main == 3)
		{
			system("cls");
			runMain(booklist);

		}
		else
		{
			printf("Sorry there is something wrong with your entering, please try again\n");
		}
	}

}
void runDetail(BookList* booklist)
{
	ShowDetailMenue();
	
	int Main;
	while (1)
	{
		scanf("%d", &Main);
		if (Main == 1)
		{
			char BooKName[CHARLENGTH];
			system("cls");
			printf("Please input the book name\n");
			scanf(" %[^\n]", BooKName);
			Book book = searchfor_a_Book_Name(booklist, BooKName);
			if (strcmp(book.name, "") == 0)
			{
				printf("Sorry the book you orderd is not in the list\n");
			}
			else
			{
				printf("%s %s %s %s\n", book.name, book.bookID, book.category, book.isBorrowed);
			}
			runDetail(booklist);
		}
		else if (Main == 2)
		{
			system("cls");
			char bookCategory[CHARLENGTH];
			printf("Please input the category\n");
			scanf(" %s", bookCategory);
			PrintBook_category(booklist, bookCategory);
			runDetail(booklist);
		}
		else if (Main == 3)
		{
			system("cls");
			PrintDetailofBook(booklist);
			runDetail(booklist);
		}
		else if (Main == 4)
		{
			system("cls");
			runMain(booklist);
		}
		else
		{
			printf("Sorry there is something wrong with your entering, please try again\n");
		}
	}
}

//Run Register Menue
void runRegister_superior(BookList* booklist)
{
	Register_superior();
	int Main;
	while (1)
	{
		scanf("%d", &Main);
		if (Main == 1)
		{
			AddNewBook(booklist);
			runRegister_superior(booklist);
		}
		else if (Main == 2)
		{
			DeleteNewBook(booklist);
			runRegister_superior(booklist);
		}
		else if (Main == 3)
		{
			system("cls");
			runMain(booklist);
		}
		else
		{
			printf("Sorry there is something wrong with your entering, please try again\n");
		}
	}

}


void Change_Book_Borrow(Book book,BookList* booklist)
{
	if ((strcmp(book.name, "") == 0) && (strcmp(book.bookID, "") == 0))
	{
		printf("Sorry the book you ordered is not in the list\n");
		runBorrow(booklist);
	}
	else if (strcmp(book.isBorrowed,"YES")==0)
	{
		printf("sorry the book is already borrowed\n");
		runBorrow(booklist);
	}
	else
	{
		ChangeBookborrow(booklist, book.bookID);
		printf("%-30s%-15s%-15s%-10s\n", book.name, book.bookID, book.category,book.isBorrowed);
		printf("The Book %s is successfully borrowed\n", book.name);
		runBorrow(booklist);
	}
}

//归还书籍
void Change_Book_return(Book book, BookList* booklist)
{
	if ((strcmp(book.name, "") == 0) && (strcmp(book.bookID, "") == 0))
	{
		printf("Sorry the book you ordered is not in the list\n");
		runReturn(booklist);
	}
	else if (strcmp(book.isBorrowed, "NO") == 0)
	{
		printf("sorry the book is already returned\n");
		runReturn(booklist);
	}
	else
	{
		ChangeBookborrow(booklist, book.bookID);
		printf("%-30s%-15s%-15s%-10s\n", book.name, book.bookID, book.category,book.isBorrowed);
		printf("The book %s is successfully return\n", book.name);
		runReturn(booklist);
	}
}

//添加新书
void AddNewBook(BookList* List)
{
	char NEW_book_Name[CHARLENGTH];
	char NEW_book_ID[CHARLENGTH];
	char New_book_category[CHARLENGTH];
	printf("Please enter the new Book Name:\n");
	scanf(" %[^\n]", NEW_book_Name);
	getchar();
	printf("Please enter the new Book ID:\n");
	scanf(" %s", NEW_book_ID);
	getchar();
	printf("Please enter the new Book category:\n");
	scanf(" %s", New_book_category);
	getchar();
	Book NEW_book;
	strcpy(NEW_book.name, NEW_book_Name);
	strcpy(NEW_book.bookID, NEW_book_ID);
	strcpy(NEW_book.category, New_book_category);
	strcpy(NEW_book.isBorrowed, "NO");
	BookNode* NEW_book_Node=creatNode(NEW_book);
	AddtoBookindex(List, NEW_book_Node);
}

//删除书籍
void DeleteNewBook(BookList* List)
{
	int i = 0;
	while (i<3)
	{
		char NEW_book_Name[CHARLENGTH];
		char NEW_book_ID[CHARLENGTH];
		printf("Please enter the Book Name:\n");
		scanf(" %[^\n]", NEW_book_Name);
		printf("Please enter the Book ID:\n");
		scanf(" %s", NEW_book_ID);
		Book NEW_book;
		//strcpy(NEW_book.name, NEW_book_Name);
		//strcpy(NEW_book.bookID, NEW_book_ID);
		//strcpy(NEW_book.isBorrowed, "NO");
		BookNode* pHead = List->headbook;
		int found = 0;
		while (1)
		{
			if ((strcmp(pHead->book.name, NEW_book_Name) == 0) && (strcmp(pHead->book.bookID, NEW_book_ID) == 0))
			{
				found = 1;
				NEW_book = pHead->book;
				break;
			}
			if (pHead->Nextbook == NULL)
			{
				break;
			}
			pHead = pHead->Nextbook;
		}
		if (found == 0)
		{
			system("cls");
			printf("Sorry there is something wrong with your entering please check again\n\n");
		}
		else if (found == 1)
		{
			DeleteBook(List, NEW_book);
			printf("Delete success\n\n");
			break;
		}
	}
}