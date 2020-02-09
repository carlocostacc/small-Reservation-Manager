#pragma once
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

#ifndef Person_H
#define Person_H
#endif




class Person {
friend class Date;
public:
	Person();
	Person(string, Date);
	~Person();
	void GetPerson();
	void SetPerson(string, Date);
	void PrintPerson();
	bool compare(Person p);
private:
	string name;
	Date datebirth;

};
