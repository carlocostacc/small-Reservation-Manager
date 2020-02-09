#include "RerservationRequest.h"


ReservatioRequest::ReservatioRequest(Person p , Date d, string s, string eds, int seat)
{
	reservationnumcount++;
	preson = p;
	reservationdate = d;
	station = s;
	destination = eds;
	reservationrequestnum = 0;
	if (0 > seat > 5) {
		numberofseats = 0;
		cout <<endl<< "a wrong number of seats was entered"<< endl;
	}
	numberofseats = seat;
	
}

ReservatioRequest::ReservatioRequest()
{
	Person p;
	Date d;
	preson = p;
	reservationdate = d;
	station ;
	destination ;
	reservationnumcount++ ;
	reservationrequestnum ;
	numberofseats ;
}

ReservatioRequest::~ReservatioRequest()
{
	cout << "the reservation request has been deleted.";
}

int ReservatioRequest::GetReservationRequestnumber() {
	return reservationnumcount;
}


int ReservatioRequest::GetReservationRequestseat()
{
	return numberofseats;
}

string ReservatioRequest::GetReservationRequeststart()
{
	return station;
}

string ReservatioRequest::GetReservationRequestend()
{
	return destination;
}

void ReservatioRequest::GetReservationRequest()
{
	cout << "the information of the obj";
	preson.PrintPerson();
	cout << "/";
	reservationdate.PrintDate();
	cout<< "/";
	cout << station << "/" << destination << "/ reservation number : " << reservationnumcount << "reservation request number " << reservationrequestnum << "number of seats " << numberofseats;

}

bool ReservatioRequest::compare(ReservatioRequest res) {
	if (preson.compare(res.preson) == true && station.compare(res.station) == 0 &&
		reservationdate.compare(res.reservationdate) == true && destination.compare(res.destination) == 0
		&& numberofseats == res.numberofseats && reservationrequestnum == res.reservationrequestnum)
		return true;
	else
		return false;
}
void ReservatioRequest::SetReservationRequest(Person p, Date d, string s, string eds, int seat)
{
	preson = p;
	reservationdate = d;
	station = s;
	destination = eds;
	reservationrequestnum = reservationnumcount;
	numberofseats = seat;
}
int ReservatioRequest :: Getnumberofstationstart(){
	string x = station;
	if (x == "montreal" || x == "Montreal") {
		return 0;
	}
	if (x == "Dorval" || x == "dorval")
	{
		return 1;
	}
	if (x == "Brockville" || x == "brockville")
	{
		return 2;
	}
	if (x == "Kingston" || x == "kingston")
	{
		return 3;
	}
	if (x == "Belleville" || x == "belleville")
	{
		return 4;
	}
	if (x == "Toronto" || x == "toronto")
	{
		return 5;
	}

}