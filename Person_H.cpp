#include "Person.h"

Person::Person()
{
	name = "";
	Date d;
	datebirth = d;
}

Person::Person(string n, Date d)
{
	name = n;
	datebirth = d;
}
Person::~Person()
{
	cout << endl<< "the data of the person has been deleted." << endl;
}
void Person::GetPerson()
{
	cout << endl << "the information about the person are :" << name ;
	cout << "/";
	datebirth.GetDate();
}

void Person::SetPerson(string n , Date d)
{
	name = n;
	datebirth = d;
}

void Person::PrintPerson()
{
	cout << "the name is: "<<  name;
	datebirth.GetDate();
}

bool Person::compare(Person p) {
	if (name.compare(p.name) == 0 && datebirth.compare(p.datebirth) == true) {
		return true;
	}
	return false;
}