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
		"1 �������� ����������",
		"2 �������� ����������",
		"3 ������� ����������",
		"4 �������� ���������",
		"5 �������� ���������",
		"6 ������� ���������",
		"7 ������������ �����",
		"8 ���������",
		"9 �����"
	};
	vector <string> nestingOfCategoty
	{
		"�������� ������� ���������",
		"�������� ������������"
	};
	/*string menueSort[3]
	{
		"���������� �� ����������",
		"���������� �� ���������",
		"���������� �� ����"
	};*/
	vector <string> date
	{
		"������ ����������� ����",
		"������ ������ ����"
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