//#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "MainControl.h"
using namespace std;
enum StartIndexCondition { startValueInLoop = -4, startValue = -3, stayValue = -2, exitValue = -1 };
class Menue
{
private:
	MainControl* ptrMc = nullptr;
	COORD c;
	vector <string> mainMenu
	{
		"1 Показать транзакции",
		"2 Добавить транзакцию",
		"3 Удалить транзакцию",
		"4 Показать категории",
		"5 Добавить категорию",
		"6 Удалить категорию",
		"7 Сформировать отчет",
		"8 Сохранить",
		"9 Выход"
	};
	vector <string> nestingOfCategoty
	{
		"Добавить главную категорию",
		"Добавить подкатегорию"
	};
	/*string menueSort[3]
	{
		"Сортировка по транзакции",
		"Сортировка по категории",
		"Сортировка по дате"
	};*/
	vector <string> date
	{
		"задать сегодняшнюю дату",
		"Задать другую дату"
	};
public:
	void setPtrMainControl(MainControl& menuController);	
	const vector <string>& getMainMenue();	
	void Stand(int x, int y, int k);	
	void showMenu(int startX, int startY, const vector <string>& menu);
	void showStrMenu(int indexStrMenu, const vector <string>& menu);	
	int setMenuPosition(int x, int y, const vector <string>& menu);	
	void addNewCategory(int startX, int startY);
	void addNewTransaction(int startX, int startY);
	void showTransactions(int startX, int startY);
};
#endif MENU_H