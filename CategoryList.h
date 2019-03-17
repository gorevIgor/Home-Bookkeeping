//#pragma once
#ifndef CATEGORYLIST_H  
#define CATEGORYLIST_H
#include <iostream>
#include"Category.h"
using namespace std;

class CategoryList
{
private:
	list <Category> ListOfCategory;
	Category* ptrCatrgory = nullptr;
public:
	CategoryList();
	const list<Category>& getList();
	void showList();
	Category* ptrReturnByIdCategory(int idCategory);
	int getIdCategortByIndex(int index);
	string getNameCategortById(int id);
	void addCategoryInList(string nameCategory, int indexOfSubcategory = -1);
};
#endif CATEGORYLIST_H 