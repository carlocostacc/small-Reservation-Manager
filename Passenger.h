#pragma once
#include <iostream>
#include "Person.h"

using namespace std;
#ifndef Passenger_H
#define Passenger_H
#endif
class Passenger {
	friend class ReservationManager;
public:
	Passenger(Person);
	Passenger();
	~Passenger();
	void GetPassenger();
	void SetPassenger(Person, int*);
	bool compare(Passenger p);
private:
	Person person;
	int *reservationrequestnumbers;
};