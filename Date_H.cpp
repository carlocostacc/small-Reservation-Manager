#include "Date.h"
Date::Date() {
	month = 0;
	day = 0;
	year = 0;
}
Date::~Date()
{
	cout << "date obj has been deleted.";
}
Date::Date(int m, int d, int y)
{
	month = (0 < m <= 12) ? m : 0;
	if (month == 2)
		day = (0 < d <= 29) ? d : 0;
	else
		day = (0 < d <= 31) ? d : 0;
	year = y;
}



void Date::SetDate(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

void Date::PrintDate()
{
	cout << endl << "the date is : " << month << "/" << day << "/" << year << endl;
}
void Date::GetDate()
{
	cout << month << "/" << day << "/" << year << endl;
}
bool Date::compare(Date d) {
	if (month = d.month && day == d.day && year == d.year)
		return true;
	else
		return false;
}