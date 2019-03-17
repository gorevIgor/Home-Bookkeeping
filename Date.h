#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include<ctime>
#include <conio.h>
#include<algorithm>
#include <iterator>
using namespace std;

class MyTime
{
	time_t rawtime;
	struct tm* timeinfo;
	int year, month, day;

public:
	MyTime();
	void setData(int _day, int _month, int _year);
	void SetUserData();	
	tm* getTimeStruct();	
	void SetnowData();		
	void showTimeStr()
	{
		char buffer[80];
		const char* format = "%d.%m.%y";
		strftime(buffer, 80, format, timeinfo);
		cout << "“екуща€ дата: " << buffer << endl;
	}
	void showTimeStr(tm* time)
	{
		char buffer[80];
		const char* format = "%d.%m.%y";
		strftime(buffer, 80, format, time);
		cout<< buffer;
	}
	//задание произвольной даты
	bool isLeapYear(int year)
	{
		return ((year % 4 == 0 && year % 100 != 0) || year % 400);
	}
	int dayInMonth(int month, int year)
	{
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (isLeapYear(year))
			days[1] = 29;
		return days[month - 1];
	}
	bool isValidDate(int day, int month, int year)
	{
		if ((day<1 || day>dayInMonth(month, year)) || (month < 1 || month>12))
		{
			return false;
		}
		return true;
	}

};
//class TestData
//
//{
//	MyTime* actionData = nullptr;
//	string comment = "";
//	tm data;
//public:
//	void setptrTime(MyTime& time)
//	{
//		actionData = &time;
//	}
//	void setActionData()
//	{
//		int y = 0, m = 0, d = 0;
//		cout << "Enter y: ";
//		cin >> y;
//		cin.ignore();
//		cout << "Enter m: ";
//		cin >> m;
//		cin.ignore();
//		cout << "Enter d: ";
//		cin >> d;
//		cin.ignore();
//		actionData->isCorrectData(y, m, d);
//		actionData->SetUserData();
//	}
//	void setString()
//	{
//		//_getch();
//		cout << "enter str: ";
//		string tmp;
//		getline(cin, tmp);
//		comment = tmp;
//	}
//	tm* getDataTime()
//	{
//		return &data;
//	}
//	void getAction()
//	{
//		actionData->showTimeStr(getDataTime());
//		cout << comment << endl;
//	}
//
//	void setUserTime()
//	{
//		data = *actionData->getTimeStruct();
//	}
//
//};
