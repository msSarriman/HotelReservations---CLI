#include <iostream>
#include <string>
#include "Room.h"

namespace std {
	Room::Room() { // // Default Constructor.
	}

	Room::Room(int number, int capacity, double price) {	// // Constructor
		for (int i = 1; i < 31; i++) {	// Make Room available for all days of the Month.
			roomAvailability[i] = NULL;
		}
		roomNumber = number;
		roomCapacity = capacity;
		roomPrice = price;
	}

	bool Room::roomReservationAdd(Reservation* r) {		// // Method() to add reservation ("Μέθοδος προσθήκης Κράτησης").
		if (r->rsrvPersons > roomCapacity) return 0;								// If Reservation's persons are greater than room's capacity, return FALSE.
		for (unsigned int i = r->rsrvDate; i < r->rsrvDate + r->rsrvNights; i++)	// If room is not available the desired days, return FALSE.
			if (roomAvailability[i] != NULL) return 0;
		for (unsigned int i = r->rsrvDate; i < r->rsrvDate + r->rsrvNights; i++)	// If the above checks, assign to the Room for the specific days, the Reservation object.
			roomAvailability[i] = r;
		r->rsrvRoomAssignment(this);												// Update Room object that the specific reservations points to.
		return 1;																	// Return TRUE.
	}

	double Room::roomPricing() {	// // Method() to return income of the room ("Μέθοδος Τιμολόγησης").
		//cout << "\nHi from room pricing function \n";
		double roomPriceReturn = 0.0;
		for (int i = 1; i <= 30; i++) {					// For all the days of the moth for the Room, calculate...
			if (roomAvailability[i] == NULL) continue;	// if room is available that day, continue...
			else roomPriceReturn += roomAvailability[i]->rsrvPersons*roomPrice;
		}												// if its not calculate the Price for that day, and add it to total roomPriceReturn.
		return roomPriceReturn;							// Return calculated amount.
	}

	bool Room::roomCancelation(int x) {		// // Method() to cancel Room's assignment to reservation("Μέθοδος Ακύρωσης").
		for (int i = 1; i <= 30; i++) {
			if (roomAvailability[i] == NULL) continue;	// Avoid Null Point exceptions with this line!
			if (roomAvailability[i]->rsrvCode == x)		// If reservation number (x) matches reservation that the room points to, then clear it.
				roomAvailability[i] = NULL;
		}
		return 1;
	}

	int Room::roomCompleteness() {		// // Method() to return a percentage of Room's utilization("Μέθοδος Πληρότητας").
		double completeness = 0;
		double returnVar = 0;
		for (int i = 1; i <= 30; i++) {					// For all the days of the month..
			if (roomAvailability[i] == NULL) continue;	// if the room is available continue...
			else completeness++;						// else auto increment completeness variable.
		}
		returnVar = (completeness*100) / 30; // and finally calculate completeness of the room for the month, in returnVar variable.
		return returnVar;							// and return that percentage!
	}

	Room::~Room() { // // Destructor
	}

}

