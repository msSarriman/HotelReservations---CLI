#pragma once
#include "Room.h"

namespace std {

	class Rooma : public Room {
	public:
		double roomaPrice;		// Rooma's price.
		virtual double roomPricing();	// Overwritted pricing() function.
		Rooma();				// Default constructor
		Rooma(int, int, double);			// Overloaded constructor
		~Rooma();				// Desctructor.
	};

}
