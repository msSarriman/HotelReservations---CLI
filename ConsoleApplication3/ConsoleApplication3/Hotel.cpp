/*
* Hotel.cpp
*
*  Created on: May 21, 2017
*      Author: root
*/

#include "Hotel.h"
#include "Room.h"

using std::Room;
using std::cout;
using std::string;
using std::vector;


Hotel::Hotel() { // // Default constructor.
}

Hotel::Hotel(const string& name) { // // Overloaded constructor.
	hotelName = name;
}

Hotel::Hotel(const string name) // // Overloaded constructor.
{
	hotelName = name;
}

Hotel::Hotel(const char *name) // // Overloaded constructor.
{
	hotelName = name;
}

void Hotel::hotelRoomAdd(Room *r) { // // Method() to add Room to hotel.("Μέθοδος 'Προσθήκη Δωματίου'").
	hotelRoomVector.push_back(r);	// Push back in Vector that stores the rooms, the r object.
}

Room* Hotel::hotelRoomRecover(int roomNmbr) {	// // Method() to return pointer to Room.("Μέθοδος 'Ανάκτηση Δωματίου από κωδικό'"). 
	for (unsigned int i = 0; i < hotelRoomVector.size(); i++) { // Through all the list(vector elements) that holds the Rooms ...
		if (roomNmbr == signed(hotelRoomVector[i]->roomNumber))	// ..search for the one with the specific number...
			return hotelRoomVector[i];							// ..and return a reference to it.
	}
	return NULL;	// If the above fails, return NULL.
}

Reservation* Hotel::hotelRsrvRecover(int rsrvCode) {	// // Method() to return pointer to reservation.("Μέθοδος 'Ανάκτηση Κράτησης από κωδικό'").
	for (unsigned int i = 0; i < hotelRsrvVector.size(); i++) { // For all the elements of the reservation list(vector) ...
		if (rsrvCode == hotelRsrvVector[i].rsrvCode)			// .. search the one with the specific code...
			return &hotelRsrvVector[i];							// .. and return a reference to it.
	}
	return NULL;	// If the above fails, return NULL.
}

bool Hotel::hotelReservationToRoom(Reservation* rx, int roomNmbr) { // Method() to return boolean condition of reservation booking to Room.("Μέθοδος 'Προσθήκη ΚράτησηςΣεΔωμάτιο'").
	Room *room;											// Create a pointer to a Room.
	room = hotelRoomRecover(roomNmbr);					// Assign this pointer to the Room with the roomNmbr room number.
	if (room == NULL) return 0;							// If room var is null, then return FALSE.
	bool cond = room->roomReservationAdd(rx);			// Call roomReservationAdd() with rx, and check that return boolean type.	
	if (cond == 1) {									// If that type is ==1 then...
		hotelRsrvVector.push_back(*rx);					// Add the reservation to Hotel's list of reservations.
		cout << "Reservation Added Successfully!\n";	// Print coresponding message.
		return 1;										// Return TRUE.
	}
	cout << "Reservation was un-successfull!\n";	// In error print coresponding message.
	return 0;										// Return FALSE.
}

int Hotel::hotelReservationBooking(Reservation *r) {	// Method() to book a reservation to any available Room.("Μέθοδος 'Προσθήκη Κράτησης'").
	bool cond;
	for (unsigned int i = 0; i < hotelRoomVector.size(); i++) { // For all the rooms in Hotel's room list, try to ....
		cond = hotelRoomVector[i]->roomReservationAdd(r);		// add the reservation to that room.
		if (cond == 1) {										// If reservation is added then do..
			hotelRsrvVector.push_back(*r);						// .. add the reservation to Hotel's reservation list.
			cout << "Reservation added to Room " << hotelRoomVector[i]->roomNumber << " .\n";
			return hotelRoomVector[i]->roomNumber;				// .. return the number of the Room that reservation assigned to.
		}
	}
	cout << "Reservation could not be added to Room!\n";	// If the above fails print coresponding message and return FALSE.
	return 0;
}

bool Hotel::hotelReservationCancel(int rsrvCode) {	// // Method() to cancel reservation.("Μέθοδος 'Ακύρωση Κράτησης'").
	Reservation* rs;
	int j = 0;
	rs = hotelRsrvRecover(rsrvCode);		// Recover to rs reservation pointer, a reservation with specific number.
	if (rs == NULL) {						// If rs == NULL, reservation does not exists. That will return a 0.
		cout << "Reservation with that code, does not exists!\n";
		return 0;
	}
	if (rs->rsrvRoom->roomCancelation(rsrvCode) != 0) {	// If the call of roomCancelation() function is not FALSE, then do...
		for (unsigned int i = 0; i < hotelRsrvVector.size(); i++) {		// Find the reservation in Hotel's list.
			if (hotelRsrvVector[i].rsrvCode == rsrvCode) {
				i = j;
				break;
			}
		}
		hotelRsrvVector.erase(hotelRsrvVector.begin() + j);				// ..and delete it from that list.
		cout << "Reservation cancelled successfully and removed from Hotel's list!\n";
		return 1;
	}
	cout << "Reservation cancelled un-successfully!\n";
	return 0;
}

double Hotel::hotelTotalIncome(int roomCode) {		// // Method() to calculate incomes.("Μέθοδος 'Υπολογισμός Εσόδων'").
	int j = 0;
	for (unsigned int i = 0; i < hotelRoomVector.size(); i++) {	// For all the Rooms of the hotel do...
		if (hotelRoomVector[i]->roomNumber == roomCode) {		// search the index of the one with the roomCode room number.
			i = j;
		}
	}
	double income = hotelRoomVector[j]->roomPricing();			// Assign to income, the above's room return of roomPricing() function.
	return income;												// Return income.
}

double Hotel::hotelTotalIncome()	// // Method() to calculate income from a specific Room.("Μέθοδος 'Υπολογισμός Εσόδων(Υπερκαλυμένη)'")
{
	double income = 0.0;
	for (unsigned int i = 0; i < hotelRoomVector.size(); i++) {	// For all the Rooms of the hotel.
		income += hotelRoomVector[i]->roomPricing();				// Calculate the income of each, and sum it up to income double variable.
	}
	return income;	// Return Income.
}

void Hotel::hotelReservationPlan() {	// // Method() to print out a table that shows availability for Rooms.("Μέθοδος Πλάνο Κρατήσεων").
	cout << "Room   ";
	for (int i = 1; i <= 30; i++) {
		cout << i << " | ";
	}
	cout << std::endl;

	for (unsigned int i = 0; i < hotelRoomVector.size(); i++) {
		cout << hotelRoomVector[i]->roomNumber << "    ";
		for (int j = 1; j <= 30; j++) {
			if (j < 10) {
				if (hotelRoomVector[i]->roomAvailability[j] == NULL) {
					if (j != 30) cout << "_ | ";
					else if (j == 30) cout << "_\n";
				}
				else {
					if (j != 30) cout << "* | ";
					else if (j == 30) cout << "*\n";
				}
			}
			else {
				if (hotelRoomVector[i]->roomAvailability[j] == NULL) {
					if (j != 30) cout << "_  | ";
					else if (j == 30) cout << "_\n";
				}
				else {
					if (j != 30) cout << "*  | ";
					else if (j == 30) cout << "*\n";
				}
			}
		}
	}
}

void Hotel::hotelDisplayReservations(){
	cout << "The are #" << hotelRsrvVector.size() << " reservations made, with the folowing codes:" << std::endl;
	for (unsigned int i = 0; i < hotelRsrvVector.size(); i++) {
		cout << "\"" << hotelRsrvVector[i].rsrvCode << "\" ";
	}
	cout << std::endl;
}

void Hotel::hotelDisplayRooms() {
	cout << "There are #" << hotelRoomVector.size() << " Rooms available, with numbers of:" << std::endl;
	for (unsigned int i = 0; i < hotelRoomVector.size(); i++) {
		cout << hotelRoomVector[i]->roomNumber << " ";
	}
	cout << std::endl;
}

void Hotel::hotelDisplayReservationsFormat(){
	cout << "Reservation Code |     Customer Name     | Room Number\n";
	for (unsigned int i = 0; i < hotelRsrvVector.size(); i++) {
		cout << "      " << hotelRsrvVector[i].rsrvCode << "      |";
		cout << "    " << hotelRsrvVector[i].rsrvName << "    |";
		cout << " " << hotelRsrvVector[i].rsrvRoom->roomNumber << std::endl;
	}
}

void Hotel::hotelDisplayRoomsFormat(){
	cout << "Room Number |  Completness  | Room's Income\n";
	for (unsigned int i = 0; i < hotelRoomVector.size(); i++) {
		cout << "    " << hotelRoomVector[i]->roomNumber << "     |";
		cout << "      " << hotelRoomVector[i]->roomCompleteness() << "%      |";
		cout << "    " << hotelRoomVector[i]->roomPricing() << std::endl;
	}
}

Hotel::~Hotel() { // Default destructor.
}

