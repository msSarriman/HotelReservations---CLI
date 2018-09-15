#pragma once
#include <iostream>
#include <string>
#include "Room.h"

namespace std {

	class Roomc : public Room {
	public:
		unsigned int roomcMinPersons;			// Minimum persons that this Room requires.
		unsigned int roomcMinNights;			// Minimum nights that this Room requires.

		virtual bool roomReservationAdd(Reservation*);	// Overwrited function() of Room's reservation add function.
		Roomc();								// Default Constructor
		Roomc(int, int, double, int, int, int);	// Overloaded Constructor.
		~Roomc();								// Default Destructor
	};

}

