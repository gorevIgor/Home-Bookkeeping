//#pragma once
#ifndef CATEGORY_H  
#define CATEGORY_H
#include <iostream>
using namespace std;
class Category
{
private:
	string nameCategory;
	int idCategory;
	int nestingLevel;// для правильного отбражения смещения в дереве категорий
	Category* subcategory;
public:
	Category();	
	Category(string CategoryName, int id, int level = 0, Category* subcat=nullptr);
	//Category(string CategoryName, int id, int level, Category* subcat=nullptr);	

	void setNameCategory(string _nameCategory);	
	string getNameCategory();	
	const string& getNameCategory() const;	
	int getIdCategory();	
	int getNestingLevel();	
};


#endif CATEGORY_H