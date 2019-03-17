#include <iostream>
#include <windows.h>//SetConsoleCP() и SetConsoleOutputCP()
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>//setw();
#include <conio.h> // _getch() - возвращает код нажатой клавиши;_kbhit() - возващает не 0,если нажата клавиша
#include"CategoryList.h"
#include"Category.h"
//#include"Menu.h"
//#include"MainControl.h"
using namespace std;
///////////////////CategoryList::////////////////////////////
CategoryList::CategoryList()
{
	ListOfCategory.push_back(Category("Дом", 1, 0, nullptr));
	ListOfCategory.push_back(Category("Здоровье", 2, 0, nullptr));
	ListOfCategory.push_back(Category("Авто", 3, 0, nullptr));
	ListOfCategory.push_back(Category("Бензин", 6, 1, ptrReturnByIdCategory(3)));
	ListOfCategory.push_back(Category("Образование", 4, 0, nullptr));
	ListOfCategory.push_back(Category("Транспорт", 5, 0, nullptr));
}
const list<Category>& CategoryList::getList()
{
	return ListOfCategory;
}
void CategoryList::showList()
{
	int i = 1;
	for (list <Category>::iterator it = ListOfCategory.begin(); it != ListOfCategory.end(); ++it)
	{
		int shift = 0;
		shift = it->getNestingLevel() * 5;
		if (it->getNestingLevel())
		{
			cout <</*i << */  setw(shift) << "  " << it->getNameCategory() << endl;
		}
		else
		{
			cout << "  " << /*i  << setw(10)<< */it->getNameCategory() << endl;
		}
		i++;
	}
}
Category* CategoryList::ptrReturnByIdCategory(int idCategory)
{
	Category * ptr = nullptr;
	for (list <Category>::iterator it = ListOfCategory.begin(); it != ListOfCategory.end(); ++it)
	{
		if (it->getIdCategory() == idCategory)
		{
			ptr = &(*it);
			return ptr;
		}
	}
	return ptr;
}
int CategoryList::getIdCategortByIndex(int index)
{
	int i = 0;
	Category * ptr = nullptr;
	list <Category>::iterator it = ListOfCategory.begin();
	while (i != index)
	{
		++it;
		++i;
	}
	return it->getIdCategory();
	/*for (list <Category>::iterator it = ListOfCategory.begin(); it != ListOfCategory.end(); ++it)
	{
		if (it->getIdCategory() == idCategory)
		{
			ptr = &(*it);
			return ptr;
		}
	}*/
	
}
string CategoryList::getNameCategortById(int id)
{
	for (list <Category>::iterator it = ListOfCategory.begin(); it != ListOfCategory.end(); ++it)
	{
		if (it->getIdCategory() == id)
		{
			return it->getNameCategory();
		}
	}
}
void CategoryList::addCategoryInList(string nameCategory, int indexOfSubcategory)
{
	auto it = ListOfCategory.rbegin();
	int id = (it->getIdCategory()) + 1;
	if (indexOfSubcategory >= 0)
	{
		auto it = ListOfCategory.begin();
		for (int i = 0; i < indexOfSubcategory; i++)
		{
			++it;
		}
		auto itptrSub = it;
		++it;
		ListOfCategory.insert(it, Category(nameCategory,id, 1, &(*itptrSub)));
		return;
	}
	ListOfCategory.push_back(Category(nameCategory, id));
}