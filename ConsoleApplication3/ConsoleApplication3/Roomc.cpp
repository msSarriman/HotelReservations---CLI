/*
* Roomc.cpp
*
*  Created on: May 21, 2017
*      Author: root
*/

#include "Roomc.h"

namespace std {

	Roomc::Roomc() { // // Default Constructor.
	}

	Roomc::Roomc(int number, int capacity, double price, int discount, int minpersons, int minnights) {
		for (int i = 1; i < 31; i++) {	// Make Room available for all days of the Month.
			roomAvailability[i] = NULL;
		}
		roomNumber = number;
		roomCapacity = capacity;
		roomPrice = price;
		roomcMinNights = minnights;
		roomcMinPersons = minpersons;
	}

	bool Roomc::roomReservationAdd(Reservation* r) {	// // Overlaped method for reservation assignment to this Roomc type.
		if (r->rsrvPersons > roomCapacity) return 0;								// If Reservation's persons are greater than room's capacity, return FALSE.
		for (unsigned int i = r->rsrvDate; i < r->rsrvDate + r->rsrvNights; i++)	// If Room is not available the desired days, return FALSE.
			if (roomAvailability[i] != NULL) return 0;
		if (r->rsrvPersons >= roomcMinPersons || r->rsrvNights >= roomcMinNights)	// If persons >= min and nights >= minnights
			return 0;
		for (unsigned int i = r->rsrvDate; i < r->rsrvDate + r->rsrvNights; i++)	// If the above checks, assign to the Room for the specific days, the Reservation object.
			roomAvailability[i] = r;
		r->rsrvRoomAssignment(this);												// Update Room object that the specific reservations points to.
		return 1;																	// Return TRUE.
	}


	Roomc::~Roomc() {
	}

}
