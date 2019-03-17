#pragma once
#include <iostream>
#include<time.h>
#include "Category.h"
#include "Date.h"

using namespace std;

class VectorTransaction;
class Transaction
{
private:
	tm date;
	double sum;
	string comment;
	int idCategory;
	string nameCategory;
public:
	Transaction(tm* _date, double sum, int _idCategoty, string comment, string _nameCategory);
	//void setCategory(string name);
	//void setDate(int _day, int _month, int _year);
	//void setSum(int _sum);
	//void setCommentary(string _comment);
	tm* getDateTransaction();
	double getSum();
	const string& getName();
	const string& getComment();
};

class VectorTransaction
{
private:
	vector <Transaction> myWallet;
public:
	VectorTransaction();
	size_t getBookSize();
	void addTransaction(const Transaction & newTransaction);
	Transaction& const getTransactionfromBook(int index);
	//Transaction& const getTransactionfromBook();
};