/*
* Roomb.cpp
*
*  Created on: May 20, 2017
*      Author: root
*/
#include <iostream>
#include <string>
#include "Roomb.h"

namespace std {

	Roomb::Roomb() {
	}

	Roomb::Roomb(int number, int capacity, double price, int discount) {	// // Constructor
		for (int i = 1; i < 31; i++) {	// Make Room available for all days of the Month.
			roomAvailability[i] = NULL;
		}
		roomNumber = number;
		roomCapacity = capacity;
		roomaPrice = price;
		roombDiscount = discount;
	}

	double Roomb::roomPricing() {		// Overwrited method for pricing of a roomb type room.
		double roomPriceReturn = 0.0;
		double afterDiscountPrice;
		int currentReservationCode;
		double discountLimit = roomaPrice / 2; // Variable that holds the lower limit of price after discount.
		for (int i = 1; i <= 30;) {
			if (roomAvailability[i] == NULL) { // if room is not reserved continue.
				i++;
				continue;
			}
			else {								// if room is reserved that day then,
				afterDiscountPrice = 0.0;		// init afterDiscountPrice variable.
				currentReservationCode = roomAvailability[i]->rsrvCode; // init reservationCode.
				while (roomAvailability[i]->rsrvCode == currentReservationCode) { // While reservation code equals to currentReservationCode, do...
					afterDiscountPrice = roomaPrice - roombDiscount;	// Apply discount.
					if (afterDiscountPrice < discountLimit)				// If the room's price gets bellow the lower limit, set it to lower limit.
						afterDiscountPrice = discountLimit;
					roomPriceReturn += afterDiscountPrice;				// store the result to total.
					i++;
					if (roomAvailability[i] == NULL) break;
				}
			}
		}
		return roomPriceReturn;						// Return total.
	}

	bool Roomb::roomCancelation(int x) {	// // Overlaped function for roomCancelation. These kinds of room cannot be cancelled.
		return 0;
	}

	Roomb::~Roomb() {	// // Default Destructor.
	}

}
