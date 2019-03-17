#include <iostream>
#include <windows.h>//SetConsoleCP() � SetConsoleOutputCP()
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>//setw();
#include <conio.h> // _getch() - ���������� ��� ������� �������;_kbhit() - ��������� �� 0,���� ������ �������

#include"Category.h"
//#include"CategoryList.h"
//#include"Menu.h"
//#include"MainControl.h"
using namespace std;

////////////////Category::///////////////////////
Category::Category()
{
	nameCategory = "";
	idCategory = 0;
	nestingLevel = 0;
	subcategory = nullptr;
}
Category::Category(string CategoryName, int id, int level, Category* subcat)//���������� ��������� 0-� � ����� �����������
{
	nameCategory = CategoryName;
	idCategory = id;
	nestingLevel = level;
	subcategory = subcat;
	if (subcategory)
	{
		nestingLevel = subcategory->getNestingLevel() + 1;
	}
	else nestingLevel = 0;
}
void Category::setNameCategory(string _nameCategory)
{
	nameCategory = _nameCategory;
}
string Category::getNameCategory()
{
	return nameCategory;
}
const string& Category::getNameCategory() const
{
	return nameCategory;
}
int Category::getIdCategory()
{
	return idCategory;
}
int Category::getNestingLevel()
{
	return nestingLevel;
}

