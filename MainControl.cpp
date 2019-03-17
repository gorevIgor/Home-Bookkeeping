#include <iostream>
#include <windows.h>//SetConsoleCP() и SetConsoleOutputCP()
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>//setw();
#include <conio.h> // _getch() - возвращает код нажатой клавиши;_kbhit() - возващает не 0,если нажата клавиша
#include"MainControl.h"
#include"CategoryList.h"
#include"Category.h"
#include"Menu.h"
#include "Transaction.h"
#include"Date.h"

using namespace std;

MainControl::MainControl()
{
	ptrCategoryList = nullptr;
	vString.reserve(20);
}
void MainControl::setptrCategoryList(CategoryList& list)
{
	ptrCategoryList = &list;
}
void MainControl::setptrBook(VectorTransaction& book)
{
	ptrBook = &book;
}
void MainControl::show()
{
	ptrCategoryList->showList();
}
void MainControl::setptrMyTime(MyTime& time)
{
	ptrMyTime = &time;
}
void MainControl::initVectorAssCategory()
{
	/*for (list <Category>::const_iterator it = ptrCategoryList->getList().begin(); it != ptrCategoryList->getList().end(); ++it)
	{
		vString.push_back(it->getNameCategory());
	}*/
	vString.clear();
	for (auto it = ptrCategoryList->getList().begin(); it != ptrCategoryList->getList().end(); ++it)
	{
		vString.push_back(it->getNameCategory());
	}
}
const vector <string>& MainControl::getVectorCategory()
{
	return vString;
}
void MainControl::addCategoryInList(string nameCategory, int indexOfSubcategory)
{
	ptrCategoryList->addCategoryInList(nameCategory, indexOfSubcategory);
}
void MainControl::addNewTransaction(MyTime dataTransaction, double sum, int indexCategory, string comment)
{
	int idCategory = ptrCategoryList->getIdCategortByIndex(indexCategory);
	cout << "MainControl::addNewTransaction idCategory = "<< idCategory << endl;
	string nameCategory = ptrCategoryList->getNameCategortById(idCategory);
	ptrBook->addTransaction(Transaction(dataTransaction.getTimeStruct(), sum, idCategory, comment, nameCategory));	
}
int MainControl:: bookSize()// возвращает количество сохраненных транзакций
{
	return  ptrBook->getBookSize();
}
void MainControl::showDataTransaction(int index)// возваращет дату транзакции
{
	Transaction obj = ptrBook->getTransactionfromBook(index);
	 ptrMyTime->showTimeStr(obj.getDateTransaction());
	
}
double MainControl::showSumTransaction(int index)// возваращет сумму транзакции
{
	return ptrBook->getTransactionfromBook(index).getSum();
}
const string& MainControl::showNameTransaction(int index)// возваращет имя транзакции
{
	return ptrBook->getTransactionfromBook(index).getName();
}
const string& MainControl::showCommentTransaction(int index)// возваращет комментарий к транзакции
{
	return ptrBook->getTransactionfromBook(index).getComment();
}
bool MainControl::isCorrectData(int _day, int _month, int _year)
{
	return ptrMyTime->isValidDate(_day, _month, _year);
}
void MainControl::setUserData(int _day, int _month, int _year)
{
	ptrMyTime->setData(_day, _month, _year);
}