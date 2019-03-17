//#pragma once
#ifndef MAINCONTROL_H  
#define MAINCONTROL_H 
#include <iostream>
#include"CategoryList.h"
#include "Category.h"
#include"Date.h"
#include"Transaction.h"
using namespace std;
class MainControl
{
	int index = 0;
	CategoryList* ptrCategoryList = nullptr;
	vector <string> vString;
	VectorTransaction* ptrBook = nullptr;
	MyTime* ptrMyTime = nullptr;
public:
	MainControl();

	void setptrCategoryList(CategoryList& list);
	void setptrBook(VectorTransaction& book);
	void setptrMyTime(MyTime& time);
	void show();

	void initVectorAssCategory();

	const vector <string>& getVectorCategory();

	void addCategoryInList(string nameCategory, int indexOfSubcategory = -1);
	void addNewTransaction(MyTime dataTransaction, double sum, int indexCategory, string comment);
	int bookSize();
	void showDataTransaction(int index);
	double showSumTransaction(int index);
	const string& showNameTransaction(int index);
	const string& showCommentTransaction(int index);
	bool isCorrectData(int _day, int _month, int _year);
	void setUserData(int _day, int _month, int _year);
};
#endif MAINCONTROL_H