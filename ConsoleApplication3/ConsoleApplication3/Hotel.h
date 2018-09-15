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

	void hotelRoomAdd(Room*);						// Method() to add Room to hotel.("Μέθοδος 'Προσθήκη Δωματίου'").
	Room* hotelRoomRecover(int);					// Method() to return pointer to Room.("Μέθοδος 'Ανάκτηση Δωματίου από κωδικό'").
	Reservation* hotelRsrvRecover(int);				// Method() to return pointer to reservation.("Μέθοδος 'Ανάκτηση Κράτησης από κωδικό'").
	bool hotelReservationToRoom(Reservation*, int);	// Method() to return boolean condition of reservation booking to Room.("Μέθοδος 'Προσθήκη ΚράτησηςΣεΔωμάτιο'").
	int hotelReservationBooking(Reservation*);		// Method() to book a reservation to any available Room.("Μέθοδος 'Προσθήκη Κράτησης'").
	bool hotelReservationCancel(int);				// Method() to cancel reservation.("Μέθοδος 'Ακύρωση Κράτησης'").
	double hotelTotalIncome();						// Method() to calculate incomes.("Μέθοδος 'Υπολογισμός Εσόδων'").
	double hotelTotalIncome(int);					// Method() to calculate income from a specific Room.("Μέθοδος 'Υπολογισμός Εσόδων(Υπερκαλυμένη)'").
	void hotelReservationPlan();					// Method() to print out a table that shows availability for Rooms.("Μέθοδος Πλάνο Κρατήσεων").

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


