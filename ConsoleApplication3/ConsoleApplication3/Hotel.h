#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Room.h"
#include "Reservation.h"

using std::vector;
using std::string;
using std::Room;
using std::Reservation;

class Hotel {
protected:
	static int hotelRoomListPos;
public:
	string hotelName;						// Hotel's name.
	vector<Room*> hotelRoomVector;			// Hotel's Rooms list.
	vector<Reservation> hotelRsrvVector;	// Hotel's Reservations list.

	void hotelRoomAdd(Room*);						// Method() to add Room to hotel.("������� '�������� ��������'").
	Room* hotelRoomRecover(int);					// Method() to return pointer to Room.("������� '�������� �������� ��� ������'").
	Reservation* hotelRsrvRecover(int);				// Method() to return pointer to reservation.("������� '�������� �������� ��� ������'").
	bool hotelReservationToRoom(Reservation*, int);	// Method() to return boolean condition of reservation booking to Room.("������� '�������� �����������������'").
	int hotelReservationBooking(Reservation*);		// Method() to book a reservation to any available Room.("������� '�������� ��������'").
	bool hotelReservationCancel(int);				// Method() to cancel reservation.("������� '������� ��������'").
	double hotelTotalIncome();						// Method() to calculate incomes.("������� '����������� ������'").
	double hotelTotalIncome(int);					// Method() to calculate income from a specific Room.("������� '����������� ������(������������)'").
	void hotelReservationPlan();					// Method() to print out a table that shows availability for Rooms.("������� ����� ���������").

	void hotelDisplayReservations();
	void hotelDisplayRooms();

	void hotelDisplayReservationsFormat();
	void hotelDisplayRoomsFormat();


	Hotel();			// Default constructor.
	Hotel(const string&);		// Overloaded constructor.
	Hotel(const string);
	Hotel(const char*);
	~Hotel();			// Default destructor.
};


