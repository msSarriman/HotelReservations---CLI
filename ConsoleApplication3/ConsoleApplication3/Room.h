#pragma once
#include "Reservation.h"

namespace std {

	class Room {
	public:
		unsigned int roomNumber;			// Room number.
		unsigned int roomCapacity;			// Room capacity.
		Reservation* roomAvailability[30];  // Room availability;
		double roomPrice;					// Room price. Refers to per Persons scale.

		Room();
		Room(int number, int capacity, double price);									// Room Constructor.
		~Room();								// Room Destructor.
		virtual bool roomReservationAdd(Reservation*);	// Method() to add reservation ("Μέθοδος προσθήκης Κράτησης").
		virtual double roomPricing();					// Method() to return income of the room ("Μέθοδος Τιμολόγησης").
		bool roomCancelation(int);				// Method() to cancel Room's assignment to reservation("Μέθοδος Ακύρωσης").
		int roomCompleteness();					// Method() to return a percentage of Room's utilization("Μέθοδος Πληρότητας"). 
	};

}

