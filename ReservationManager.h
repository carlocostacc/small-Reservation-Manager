#pragma once
#include <iostream>
#include "Date.h"
#include "RerservationRequest.h"
#include "Passenger.h"

using namespace std;
#ifndef RerservationManager_H
#define RerservationManager_H
#endif

class ReservationManager {
	
public:	
	ReservationManager(Date, int, int, int**, ReservatioRequest );
	ReservationManager();
	~ReservationManager();
	void GetReservationManager();
	void SetReservationManager(Date, int, int, int**, ReservatioRequest );
	void PrintReservationtable();
	int GetReservationRequestStationnumberstart(ReservatioRequest res);
	int GetReservationRequestStationnumberfinish(ReservatioRequest res);
	bool ReservationRequestManage(ReservatioRequest res);
	void Addtopassengerarray(ReservatioRequest res);
	void SetPassenger(ReservatioRequest res);
	void SetseatForPassenger(ReservatioRequest res);
	int SetReservationnum(ReservatioRequest res);
	void PrintReservationdetails(int res);
	void ReservationRequestCancellation(ReservatioRequest res);
private:
	Date traveldate;
	int capacity;
	int numberofstation;
	int** reservationtable;
	ReservatioRequest reservationobj;
	ReservatioRequest* reservationrequest;
	Passenger* passengerarr;


};