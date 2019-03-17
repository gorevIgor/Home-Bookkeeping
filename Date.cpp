#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include<ctime>
#include <conio.h>
#include<algorithm>
#include <iterator>
#include"Date.h"
using namespace std;
MyTime::MyTime()
{
	rawtime = time(NULL);
	timeinfo = localtime(&rawtime);
}
void MyTime:: setData(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}
void MyTime:: SetUserData()
{
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

}
tm* MyTime:: getTimeStruct()
{
	return timeinfo;
}
void MyTime:: SetnowData()
{
	rawtime = time(NULL);
	timeinfo = localtime(&rawtime);
}