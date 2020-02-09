#include "Passenger.h"

Passenger::Passenger(Person n)
{
	person = n;
	reservationrequestnumbers[5] = {};

}

Passenger::Passenger()
{
	Person p;
	person = p;
	reservationrequestnumbers[5];
}

Passenger::~Passenger()
{
	delete[] reservationrequestnumbers;
	cout <<endl<< "the passenger data has been deleted. " << endl;
}

void Passenger::GetPassenger()
{
	person.GetPerson();
	cout << "the reservation request numbers are : ";
	for (int i = 0; i < 5; i++) {
		cout << reservationrequestnumbers[i];
		if (i != 4) {
			cout << ", ";
		}
	}
	cout << endl;
}

void Passenger::SetPassenger(Person p, int* arr)
{
	person = p;
	reservationrequestnumbers = arr;
}
bool Passenger::compare(Passenger p) {
	if (person.compare(p.person) == true && reservationrequestnumbers[0] == p.reservationrequestnumbers[0])
		return true;
	else
		return false;
}