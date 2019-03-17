#include <iostream>
#include <windows.h>//SetConsoleCP() и SetConsoleOutputCP()
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>//setw();
#include <conio.h> // _getch() - возвращает код нажатой клавиши;_kbhit() - возващает не 0,если нажата клавиша
#include<ctime>
#include"Date.h"
#include"Menu.h"
#include"MainControl.h"
#include"CategoryList.h"
#include"Category.h"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define VK_RETURN 0x0D
#define VK_ESCAPE 27

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);

	void Menue::setPtrMainControl(MainControl& menuController)
	{
		ptrMc = &menuController;
	}
	const vector <string>& Menue::getMainMenue()
	{
		return mainMenu;
	}
	void Menue::Stand(int x, int y, int k)//выделение активной строки меню цветом
	{
		CONSOLE_CURSOR_INFO ci; ci.bVisible = 1;//тест. чтоб видеть курсор. при работе изменить на "0"
		ci.dwSize = 100;//уточнить
		SetConsoleCursorInfo(H, &ci);
		c.X = x;
		c.Y = y;
		SetConsoleCursorPosition(H, c);
		SetConsoleTextAttribute(H, k);
		/* SetConsoleTextAttribute (H, 0xA2);
	Первый разряд (в данном случае 2) - это цвет текста.
	Второй разряд (в данном случае А) - цвет фона.
	Цвета в шестнадцатеричной форме:

	0 = Black       8 = Gray
	1 = Blue        9 = Light Blue
	2 = Green       A = Light Green
	3 = Aqua        B = Light Aqua
	4 = Red         C = Light Red
	5 = Purple      D = Light Purple
	6 = Yellow      E = Light Yellow
	7 = White       F = Bright White
	*/
	}
	void Menue::showMenu(int startX, int startY, const vector <string>& menu)
	{
		int wite = 7;
		int yellow = 6;
		int _x = startX;
		int _y = startY;
		int k = wite;
		for (int i = 0; i < menu.size(); i++)
		{
			if (i == 0) k = yellow;
			else k = wite;
			Stand(_x, _y + i, k);
			cout << menu[i];
			cout << endl;
		}
		c.X = startX;
		c.Y = startY;
		SetConsoleCursorPosition(H, c);
	}
	void Menue::showStrMenu(int indexStrMenu, const vector <string>& menu)
	{
		cout << menu[indexStrMenu];
	}
	int Menue::setMenuPosition(int x, int y, const vector <string>& menu)
	{
		int wite = 7;
		int yellow = 6;
		int shiftOfIndex = 1;
		int ch = _getch();
		if (ch == KEY_UP && c.Y > y)
		{
			Stand(c.X, c.Y, wite);
			showStrMenu((y + c.Y) - y - shiftOfIndex, menu);
			--c.Y;
			Stand(c.X, c.Y, yellow);
			showStrMenu((y + c.Y) - y - shiftOfIndex, menu);

		}
		else if (ch == KEY_DOWN && c.Y < (y + menu.size() - shiftOfIndex))
		{
			Stand(c.X, c.Y, wite);
			showStrMenu((y + c.Y) - y - shiftOfIndex, menu);
			++c.Y;
			Stand(c.X, c.Y, yellow);
			showStrMenu((y + c.Y) - y - shiftOfIndex, menu);
		}
		else if (ch == VK_RETURN)
		{
			int indexMenu = (y + c.Y) - y - shiftOfIndex;
			Stand(x, (y + menu.size()), wite);
			return indexMenu;
		}
		else if (ch == VK_ESCAPE)
		{
			return exitValue;
		}
		return stayValue;
	}
	void Menue::addNewCategory(int startX, int startY)
	{
		int index = startValue;
		int nestingCategory = 0;
		bool exit = true;
		cout << "Выберите статус новой категории: ";
		showMenu(startX, startY, nestingOfCategoty);
		while (exit)
		{
			if (_kbhit())
			{
				index = setMenuPosition(startX, startY, nestingOfCategoty);
			}
			if (index == exitValue)
			{
				exit = false;
				break;
			}
			else if (index == 0)
			{
				break;
			}
			else if (index > 0)
			{
				system("cls");
				cout << "Выберите родительскую категорию:";
				ptrMc->initVectorAssCategory();
				showMenu(startX, startY, ptrMc->getVectorCategory());
				bool exitTwo = true;
				while (exitTwo)
				{
					index = startValueInLoop;
					if (_kbhit())
					{
						index = setMenuPosition(startX, startY, ptrMc->getVectorCategory());
					}
					if (index == -1)
					{
						//	exit = false;
						index = -3;
						break;
					}
					else if (index >= 0)
					{
						string name;
						cout << "Введите имя новой категории: ";
						getline(cin, name);
						ptrMc->addCategoryInList(name, index);
						return;
					}
				}					
			}
		}
		string name;
		cout << "Введите имя новой категории: ";
		getline(cin, name);
		ptrMc->addCategoryInList(name);
	}
	void Menue::addNewTransaction(int startX, int startY)
	{
		int index = startValue;
		int nestingCategory = 0;
		bool exit = true;
		cout << "Выберите дату транзакции: ";
		showMenu(startX, startY, date);
		MyTime dataTransaction;
		while (exit)
		{
			if (_kbhit())
			{
				index = setMenuPosition(startX, startY, date);
			}
			if (index == -1)
			{
				exit = false;
				break;
			}
			else if (index == 0)
			{//метод задания сегодняшней даты
				system("cls");
				dataTransaction.SetnowData();				
				dataTransaction.showTimeStr();
				exit = false;				
				break;
			}
			else if (index == 1)
			{
				//метод задания произвольной даты
				system("cls");
				int day=0;
				int month = 0;
				int year = 0;
				cout << "Ведите дату транзакции: " << endl;
				cout << "дд: ";
				cin >> day;
				cin.ignore();
				cout << "мм: ";
				cin >> month;
				cin.ignore();
				cout << "гггг: ";
				cin >> year;
				cin.ignore();				
				if (dataTransaction.isValidDate(day, month, year))
				{
					dataTransaction.setData(day, month, year);
					dataTransaction.SetUserData();
					dataTransaction.showTimeStr();
					exit = false;
				}
				else
				{
					cout << "Введена неверная дата" << endl;					
				}
				_getch();				
			}
		}
		cout << "Введите сумму: ";
		double sum = 0; 
		cin >> sum;
		system("cls");
		cout << "Выберите категорию транзацкии:";
		ptrMc->initVectorAssCategory();
		showMenu(startX, startY, ptrMc->getVectorCategory());
		exit = true;
		index = -3;
		while (exit)
		{
			if (_kbhit())
			{
				index = setMenuPosition(startX, startY, ptrMc->getVectorCategory());
			}
			if (index == -1)
			{
				index = -3;
				exit = false;
				break;
			}
			else if (index >= 0)
			{
				cin.ignore();
				string comment;
				cout << "Добавьте комментарий: ";
				getline(cin, comment);
				cout << comment;
				ptrMc->addNewTransaction(dataTransaction, sum, index, comment);		
				index = -1;
			}
		}
	}
	void Menue::showTransactions(int startX, int startY)
	{
		cout<< setw(8)<< "DATE" << setw(8)<<"SUMM" << setw(25) << "CATEGORY" << setw(20) << "COMMENTARY"<<endl;
		for (int i = 0; i < ptrMc->bookSize(); ++i)
		{				
			ptrMc->showDataTransaction(i);
			cout<<setw(8)<<
			ptrMc->showSumTransaction(i)<<
			setw(20)<<" "<<
			ptrMc->showNameTransaction(i)<<
			setw(20)<< "  " <<
			ptrMc->showCommentTransaction(i)
			<< endl;			
		}
	}
