#include<stdio.h>
#include<string.h>
#include"Menue.h"
#include"Logic.h"
#include"Database.h"
#include"Register.h"

int main()
{
	FILE* file = fopen("Book.txt", "r");
	BookList* booklist = AddBook(file);
	fclose(file);
	runMain(booklist);	

}