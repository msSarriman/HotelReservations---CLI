#pragma once

#include <string>

namespace std {

	class Room;

	class Reservation {
	public:
		static int rsrvAutoCode;	// Unique Reservation auto incrementing ID.
		int rsrvCode;				// ID for seperate obejcts.
		string rsrvName;			// Name of customer.
		unsigned int rsrvDate;		// Date of reservation.
		unsigned int rsrvNights;	// Nights of stay over.
		unsigned int rsrvPersons;	// Persons included at reservation.
		Room* rsrvRoom;				// Room assigned to reservation.

		Reservation();						// Constructor().
		Reservation(int, string, int, int);	// Overloaded Constructor().
		~Reservation();						// Destructor().
		void rsrvShowReservation();			// Method() to diplasy reservation details.
		void rsrvRoomAssignment(Room*);		// Methos() to assign `Room* rsrvRoom` to an object of Class Room.
	};

}

