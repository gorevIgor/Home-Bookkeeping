#include <iostream>
#include <windows.h>//SetConsoleCP() и SetConsoleOutputCP()
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>//setw();
#include <conio.h> // _getch() - возвращает код нажатой клавиши;_kbhit() - возващает не 0,если нажата клавиша
#include<time.h>
#include "Transaction.h"
#include"Category.h"
#include "CategoryList.h"
#include "Date.h"

//////////////Transaction::///////////////////////
Transaction::Transaction(tm* _date, double _sum, int _idCategoty, string _comment, string _nameCategory)
{
	date = *_date;
	sum = _sum;
	comment = _comment;
	idCategory = _idCategoty;
	nameCategory = _nameCategory;
}
//void Transaction::setCategory(string name)
//{
//	ptrCategory->setNameCategory(name);
//
//}
//void Transaction::setDate(int _day, int _month, int _year)
//{
//	/*day = _day;
//	month = _month;
//	year = _year;*/
//}
//void Transaction::setSum(int _sum)
//{
//	sum = _sum;
//}
//void Transaction::setCommentary(string _comment)
//{
//	comment = _comment;
//}
tm* Transaction::getDateTransaction()
{
	return &date;
}
double Transaction::getSum()
{
	return sum;
}
const string& Transaction::getName()
{
	return nameCategory;
}
const string& Transaction::getComment()
{
	return comment;
}

////////////VectorTransaction:://///////////////
VectorTransaction::VectorTransaction()
{
	myWallet.reserve(10);
}
size_t VectorTransaction::getBookSize()
{
	return myWallet.size();
}
void VectorTransaction::addTransaction(const Transaction &newTransaction)
{
	myWallet.push_back(newTransaction);
}
Transaction& const VectorTransaction::getTransactionfromBook(int index)
{
	return myWallet[index];
}
//Transaction& const VectorTransaction::getTransactionfromBook()
//{
//	return myWallet;
//}