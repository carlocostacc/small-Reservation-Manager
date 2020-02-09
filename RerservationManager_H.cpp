#include "ReservationManager.h"
using namespace std;

ReservationManager::ReservationManager(Date d, int c, int n, int** r, ReservatioRequest res)
{
	traveldate = d;
	capacity = c;
	numberofstation = n;
	reservationobj = res;
	reservationtable = new int * [capacity];
	for (int i = 0; i < capacity; i++) {
		reservationtable[i] = new int[numberofstation];
	}
	reservationrequest[capacity * numberofstation] = {};
	passengerarr[capacity * numberofstation] = {};
}


ReservationManager::ReservationManager()
{
	Date d;
	traveldate = d;
	capacity = 0;
	numberofstation = 0;
	reservationtable = new int* [capacity];
	reservationtable[capacity] = new int[numberofstation];
	reservationrequest[capacity * numberofstation] = {};
	passengerarr[capacity * numberofstation] = {};

}


ReservationManager::~ReservationManager()
{
	delete[] reservationtable;
	delete[]reservationrequest;
	delete[]passengerarr;
	cout << endl << "the data of the reservation manager is deleted." << endl;
}


void ReservationManager::GetReservationManager()
{
	cout << endl << "the information of the reservation manager is :";
	cout << ", " << "capacity is :" << capacity<< "number of stations are"<< numberofstation<< ", ";
	cout << "reservation table is "; 
	PrintReservationtable();
}


void ReservationManager::SetReservationManager(Date d, int c, int n, int** r, ReservatioRequest res)
{
	traveldate = d;
	capacity = c;
	numberofstation = n;
	reservationobj = res;
	reservationtable = new int* [capacity];
	for (int i = 0; i < capacity; i++) {
		reservationtable[i] = new int[numberofstation];
	}
	reservationrequest[capacity * numberofstation] = {};
}


void ReservationManager::PrintReservationtable()
{
	for (int i = 0; i < capacity; i++) {
		for (int y = 0; y < numberofstation; y++) {
			cout << reservationtable[i][y] << ", ";
		}
	}
}


int ReservationManager::GetReservationRequestStationnumberstart(ReservatioRequest res) {
	string x = res.GetReservationRequeststart();
	if (x.compare( "montreal") == 0 || x.compare("Montreal")==0) {
		return 0;
	}
	if (x.compare("Dorval") == 0 || x.compare("dorval")== 0)
	{
		return 1;
	}
	if (x.compare("Brockville")==0 || x.compare("brockville")==0)
	{
		return 2;
	}
	if (x.compare("Kingston") == 0 || x.compare("kingston") == 0)
	{
		return 3;
	}
	if (x.compare("Belleville") == 0 || x.compare("belleville") == 0)
	{
		return 4;
	}
	if (x.compare("Toronto" ) == 0|| x.compare("toronto"))
	{
		return 5;
	}
}


int ReservationManager::GetReservationRequestStationnumberfinish(ReservatioRequest res) {
	string x = res.GetReservationRequestend();
	if (x.compare("montreal") == 0 || x.compare("Montreal") == 0) {
		return 0;
	}
	if (x.compare("Dorval") == 0 || x.compare("dorval") == 0)
	{
		return 1;
	}
	if (x.compare("Brockville") == 0 || x.compare("brockville") == 0)
	{
		return 2;
	}
	if (x.compare("Kingston") == 0 || x.compare("kingston") == 0)
	{
		return 3;
	}
	if (x.compare("Belleville") == 0 || x.compare("belleville") == 0)
	{
		return 4;
	}
	if (x.compare("Toronto") == 0 || x.compare("toronto"))
	{
		return 5;
	}
}


bool  ReservationManager::ReservationRequestManage(ReservatioRequest res) {
	if (res.GetReservationRequestseat() > capacity) {
		cout << "the reservation request : ";
		res.GetReservationRequest();
		cout<< "is not valid";
		res.~ReservatioRequest();
	}
	else
	{
		int counter = 0;
		if (GetReservationRequestStationnumberstart(res) < GetReservationRequestStationnumberfinish(res)) {
			for (int i = 0; i < capacity; i++) {
				counter = 0;
				for (int z = GetReservationRequestStationnumberstart(res); z < GetReservationRequestStationnumberfinish(res); z++) {
					if (reservationtable[i][z] <= res.GetReservationRequestnumber())
						counter++;
					if (counter + res.GetReservationRequestseat() > capacity) {
						cout << "the reervation request has not been accepted the no seats available " << endl;
						res.~ReservatioRequest();
						return false;
					}
				}

				SetReservationnum(res);

				cout << "the reservation request has been accepted " << endl;
				return true;
			}/* //i dont know if it is possible to do returns bc not asked in questions
			if (GetReservationRequestStationnumberstart(res) > GetReservationRequestStationnumberfinish(res)) {
				for (int i = 0; i < capacity; i++) {
					for (int z = GetReservationRequestStationnumberfinish(res); z < GetReservationRequestStationnumberstart(res); z--) {
						cout << "do struff";
					}
				}
			}*/
		}
	}
}


void ReservationManager::Addtopassengerarray(ReservatioRequest res) {
	ReservatioRequest r;
	for (int i = 0; i < capacity * numberofstation; i++) {
		if (reservationrequest[i].compare(r) == true) {
			reservationrequest[i] = res;
		}
	}
}

void ReservationManager::SetPassenger(ReservatioRequest res) {
	bool added = false;
	for (int i = 0; i < capacity * numberofstation; i++) {
		if (passengerarr[i].person.compare(res.preson) == true)
			for (int y = 0; y < 5; y++) {
				if (passengerarr[i].reservationrequestnumbers[y] == 0) {
					passengerarr[i].reservationrequestnumbers[y] = res.reservationrequestnum;
					added = true;
					break;
				}
				if (passengerarr[i].reservationrequestnumbers[y] != 0 && y == 4) {
					cout << "the reservation request can't be added to the passenger array"<< endl;
					cout << "the maximum number of reservations has been reached for this passenger"<<endl;
				}
			}
	}
	if (added == false) {
		Passenger emptypass;
		Passenger p(res.preson);
		p.reservationrequestnumbers[0] = res.reservationrequestnum;
		for (int i = 0; i < capacity * numberofstation; i++) {
			if (passengerarr[i].compare(emptypass) == true) {
				passengerarr[i] = p;
				break;
			}
			if (passengerarr[i].compare(emptypass) == false && i == capacity * numberofstation - 1) {
				cout << "the passenger array is full" << endl;
				cout << "dont know what to do...  ¯\_(ツ)_/¯" << endl;
			}
		}
	}
}


void ReservationManager::SetseatForPassenger(ReservatioRequest res) {
	ReservatioRequest r;
	int counter = 0;
	for (int z = GetReservationRequestStationnumberstart(res); z < GetReservationRequestStationnumberfinish(res); z++)
	 {
		counter = 0;
		for (int i = 0; i < capacity; i++) {
			if (reservationtable[i][z] == 0) {
				reservationtable[i][z] = res.reservationrequestnum;
				counter++;
			}
			if (counter == res.numberofseats)
				break;
		}
	}
	Addtopassengerarray(res);
}


int ReservationManager::SetReservationnum(ReservatioRequest res) {
	res.reservationrequestnum = res.reservationnumcount;
	return res.reservationrequestnum;
}


/*A member function that receives a reservation request number as a parameter and outputs
the details of the reservation including seat assignments.*/


void ReservationManager::PrintReservationdetails(int resn) {
	ReservatioRequest res;
	for (int i = 0; i < capacity * numberofstation; i++)
		if (reservationrequest[i].reservationrequestnum == resn) {
			res = reservationrequest[i];
			cout << "the reservation number is: " << resn << "\nthe start station is " << reservationrequest[i].station << "\n the destination is " << reservationrequest[i].destination;
			cout << '\n' << "the name of the passenger is "; reservationrequest[i].preson.PrintPerson();
			break;
		}
	for (int z = GetReservationRequestStationnumberstart(res); z < GetReservationRequestStationnumberfinish(res); z++){
		for (int i = 0; i < capacity; i++) {
			if (reservationtable[i][z] == resn) {
				cout << "seat number " << i << "for station number " << z;
				cout << endl;
				}
			}
		}
	}

/*A member function that receives a reservation request number and cancels reservation request*/
void ReservationManager::ReservationRequestCancellation(ReservatioRequest res) {

}