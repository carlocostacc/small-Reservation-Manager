#pragma once
#include <iostream>;

using namespace std;

#ifndef Date_H
#define Date_H 
#endif

class Date {
public:
	Date(int, int, int);
	Date();
	~Date();
	void SetDate(int , int , int);
	void PrintDate();
	void GetDate();
	bool compare(Date d);
private:
	int month;
	int day;
	int year; 
};

