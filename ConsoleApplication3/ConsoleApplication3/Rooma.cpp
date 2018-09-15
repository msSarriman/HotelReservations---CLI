#include <iostream>
#include <string>
#include "Rooma.h"

namespace std {

	Rooma::Rooma() { // // Default constructor 
	}

	Rooma::Rooma(int number, int capacity, double price) {	// // Constructor
		for (int i = 1; i < 31; i++) {	// Make Room available for all days of the Month.
			roomAvailability[i] = NULL;
		}
		roomNumber = number;
		roomCapacity = capacity;
		roomaPrice = price;
	}

	double Rooma::roomPricing() {	// // Overlaped Method() to return income of the Rooma ("Μέθοδος Τιμολόγησης").
		//cout << "\nHi from rooma overwritted pricing function \n";
		double roomPriceReturn = 0.0;
		for (int i = 1; i <= 30; i++) {
			if (roomAvailability[i] == NULL) continue;
			else roomPriceReturn += roomaPrice;
		}
		return roomPriceReturn;
	}

	Rooma::~Rooma() {
	}
}

