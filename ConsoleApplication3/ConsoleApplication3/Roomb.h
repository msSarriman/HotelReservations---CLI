#pragma once
#include "Rooma.h"

namespace std {

	class Roomb : public Rooma {
	public:
		int roombDiscount;				// Discount per day.
		virtual double roomPricing();			// Overlaped pricing() function.
		bool roomCancelation(int);		// Overlaped cancelation() function.
		Roomb();						// Default constructor.
		Roomb(int, int, double, int);	// Overloaded constructor.
		~Roomb();						// DefaultDestructor.
	};
}
