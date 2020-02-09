#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
#ifndef ReservationRequest_H
#define ReservationRequest_H
#endif // !ReservationRequest_H


class ReservatioRequest {
	friend class ReservationManager;
private:
	Person preson;
	static int reservationnumcount;
	int reservationrequestnum;
	Date reservationdate;
	string station;
	string destination;
	int numberofseats;
	bool compare(ReservatioRequest res);
public:
	ReservatioRequest(Person, Date, string, string, int);
	ReservatioRequest();
	~ReservatioRequest();
	int GetReservationRequestnumber();
	int GetReservationRequestseat();
	string GetReservationRequeststart();
	string GetReservationRequestend();
	void GetReservationRequest();
	void SetReservationRequest(Person, Date, string, string, int);

	int Getnumberofstationstart();

};
