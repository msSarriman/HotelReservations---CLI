#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "Hotel.h"
#include "Reservation.h"
#include "Room.h"
#include "Rooma.h"
#include "Roomb.h"
#include "Roomc.h"

#include "customerNames.h"

#define DEBUG

using namespace std;

int randomNumberGen(int, int);		// Function Prototype. `randomNumberGen` produces given a range from int-int, randome number.
void sleep(unsigned int);			// Function Prototype. `sleep` is used to improve user experience during runtime.
int Reservation::rsrvAutoCode = 10000;

int main() {
	Hotel Palace("Palace");					// Hotel object creation, named Palace.
	Room room100(100, 4, 50.0);				// Room object creation, with constructor parameters of (100-RoomNumber), (4-MaxPersons), (50-RoomPricePerPerson).
	Room room101(101, 2, 100);				// Room object creation, with constructor parameters of (101-RoomNumber), (2-MaxPersons), (100-RoomPricePerPerson)
	Room room102(102, 3, 70);				// Room object creation, with constructor parameters of (102-RoomNumber), (3-MaxPersons), (70-RoomPricePerPerson)
	Rooma room103(103, 2, 75);				// Rooma object creation, with constructor parameters of (103-RoomNumber), (2-MaxPersons), (75-RoomPricePerDay)
	Rooma room104(104, 3, 70);				// Rooma object creation, with constructor parameters of (104-RoomNumber), (3-MaxPersons), (70-RoomPricePerDay)
	Rooma room105(105, 4, 50);				// Rooma object creation, with constructor parameters of (105-RoomNumber), (4-MaxPersons), (50-RoomPricePerDay)
	Roomb room106(106, 3, 80, 15);			// Roomb object creation, with constructor parameters of (106-RoomNumber), (3-MaxPersons), (80-RoomPricePerDay), (15-Discount)
	Roomb room107(107, 4, 90, 20);			// Roomb object creation, with constructor parameters of (107-RoomNumber), (4-MaxPersons), (90-RoomPricePerDay), (20-Discount)
	Roomc room108(108, 2, 80, 15, 2, 5);	// Roomc object creation, with constructor parameters of (108-RoomNumber), (2-MaxPersons), (80-RoomPricePerPerson), (2-MinPersons), (5-MinNights)	
	Roomc room109(109, 3, 70, 10, 3, 4);	// Roomc object creation, with constructor parameters of (109-RoomNumber), (3-MaxPersons), (70-RoomPricePerPerson), (3-MinPersons), (4-MinNights)

	Palace.hotelRoomAdd(&room100);			// Add room100 object, into Hotel.Palace.RoomList
	Palace.hotelRoomAdd(&room101);			// Add room101 object, into Hotel.Palace.RoomList
	Palace.hotelRoomAdd(&room102);			// Add room102 object, into Hotel.Palace.RoomList
	Palace.hotelRoomAdd(&room103);			// Add room103 object, into Hotel.Palace.RoomList
	Palace.hotelRoomAdd(&room104);			// Add room104 object, into Hotel.Palace.RoomList
	Palace.hotelRoomAdd(&room105);			// Add room105 object, into Hotel.Palace.RoomList
	Palace.hotelRoomAdd(&room106);			// Add room106 object, into Hotel.Palace.RoomList
	Palace.hotelRoomAdd(&room107);			// Add room107 object, into Hotel.Palace.RoomList
	Palace.hotelRoomAdd(&room108);			// Add room108 object, into Hotel.Palace.RoomList
	Palace.hotelRoomAdd(&room109);			// Add room109 object, into Hotel.Palace.RoomList

	srand((unsigned)time(0));				// Seed for rand function.
	for (;;) {
		int randomName = randomNumberGen(1, 41);		// Produce a random number from 1 to 41. That number will choose a random name from "customerNames.h", for the Reservation creation of the simulation.
		int randomDate = randomNumberGen(1, 30);		// Produce a random number from 1 to 30.
		int randomNights = randomNumberGen(1, 5);		// Produce a random number from 1 to 5.
		int randomPersons = randomNumberGen(1, 4);		// Produce a random number from 1 to 4.
#ifdef DEBUG
		cout << "a random name is: " << customerNames[randomName] << endl;		// Debug
		cout << "a random Date is: " << randomDate << endl;						//	Lines!
		cout << "a random Night is: " << randomNights << endl;					// Debug
		cout << "a random #Perons is: " << randomPersons << endl;				//	Lines!
#endif
		if ((randomDate + randomNights) > 30) {									// If Reservation details surpass month duration, create a new reservation.
			continue;															//
		}
		Reservation rs(randomDate, customerNames[randomName], randomNights, randomPersons); // Creation of the Reservation object with the above details.
		Palace.hotelReservationBooking(&rs);												// Booking of the Reservation.

		int cancelPossibility = randomNumberGen(1, 100);												// Create a random number from 1 to 100.
		if (cancelPossibility <= 25) {																	// If that number is smaller than 25
			cout << "Oh no! All of sudden we got a call for a reservation cancel!\n";					// Then delete a random reservation.
			int reservationToCancel = randomNumberGen(1, Palace.hotelRsrvVector.size()) - 1;
			int reservationCodeToCancel = Palace.hotelRsrvVector[reservationToCancel].rsrvCode;
			cout << "Sadly the customers with reservation number " << reservationCodeToCancel << endl;
			Palace.hotelReservationCancel(reservationCodeToCancel);
			cout << "just canceled their reservation!\n";		
			cout << endl;
		}

		while (1) {
			char userMenu;
			cout << "Press 'U', to display user menu, or 'C' to continue\n";
			cin >> userMenu;							// User here will have to submit an option.
			if (userMenu == 'U' || userMenu == 'u') {
				cout << "===========================\n";
				cout << "Welcome to the user menu!\n";
				cout << "For new Reservation,    press '1'.\n";
				cout << "For Reservation Delete, press '2'.\n";
				cout << "For Reservation List,   press '3'.\n";
				cout << "To Display Rooms,       press '4'.\n";
				cout << "For Reservation Plan,   press '5'.\n";
				cout << "To display incomes,     press '6'.\n";
				cout << "To continue the emulation,	press 'C'.\n";
				cout << "To close the programm,		press \"E\".\n";
				char userChoise;
				cin >> userChoise;					// User here will have to submit an option. Depending on the choise, the coresponding menu will appear.
				cout << "You selected option " << userChoise << endl;
				switch (userChoise) {
				case '1': {
				no:
					string inName;
					unsigned int inDate;
					unsigned int inNights;
					unsigned int inPersons;
					char Choise;
					cout << "Please enter:" << endl << "->Reservation    name:";
					cin >> inName;
					cout << "->Reservation    date:";
					cin >> inDate;
					cout << "->Reservation  nights:";
					cin >> inNights;
					cout << "->Reservation persons:";
					cin >> inPersons;
					cout << "Do you prefer a specific room? Y/N\n";
					cin >> Choise;
					if (Choise == 'Y' || Choise == 'y') {
						cout << "Please enter the Room Number you are interested in:\n";
						Palace.hotelDisplayRooms();
						int inRoomNumber;
						cin >> inRoomNumber;
						cout << "Are the following details correct? Y/N\n";
						cout << "Name:\"" << inName << "\" Date:\"" << inDate << "\" Nights:\"" << inNights << "\" Persons:\"" << inPersons << "\" Room:\"" << inRoomNumber << "\"" << endl;
						cin >> Choise;
						if (Choise == 'N' || Choise == 'n') goto no;
						cout << "Reservation will now be booked!\n";
						sleep(1000);
						Reservation res(inDate, inName, inNights, inPersons); //Creation of reservation from user input with Room Number parameter.
						Palace.hotelReservationToRoom(&res, inRoomNumber);	  //And booking of that reservation
						break;
					}
					else {
						cout << "Are the following details correct? Y/N\n";
						cout << "Name:\"" << inName << "\" Date:\"" << inDate << "\" Nights:\"" << inNights << "\" Persons:\"" << inPersons << "\"" << endl;
						cin >> Choise;
						if (Choise == 'N' || Choise == 'n') goto no;
						cout << "Reservation will now be booked!\n";
						sleep(1000);
						Reservation res(inDate, inName, inNights, inPersons); //Creation of reservation from user input without Room Number parameter.
						Palace.hotelReservationBooking(&res);				  //And booking of that reservation.
						break;
					}
					cout << "Something went terribly wrong!!\n";
					break;
				}
				case '2': {		// User menu to cancel a reservation.
				wrongResNumber:	
					Palace.hotelDisplayReservations();
					cout << "Please enter a reservation Number to cancel:\n";
					unsigned int inResNumber;
					cin >> inResNumber;
					if (Palace.hotelReservationCancel(inResNumber) == false) {
						cout << "Please enter a valid reservation number!\n";
						goto wrongResNumber;
					}
					break;
				}
				case '3': {		// User menu to display the reservation as requested.
					Palace.hotelDisplayReservationsFormat();
					break;
				}
				case '4': {		// User menu to display the rooms as requested.
					Palace.hotelDisplayRoomsFormat();
					break;
				}
				case '5': {		// User menu to display the reservation plan.
					Palace.hotelReservationPlan();
					break;
				}
				case '6': {		// User menu to see incomes from a room or for the hole union of rooms.
					cout << "Do you want to choose a specific room number? Y/N\n";
					char Choise;
					cin >> Choise;
					if (Choise == 'Y' || Choise == 'y') {
						unsigned int inRoomNumber;
						Palace.hotelDisplayRooms();
						cout << "Please enter room number:\n";
						cin >> inRoomNumber;
						cout << "The room with number " << inRoomNumber << " made the ammount of " << Palace.hotelTotalIncome(inRoomNumber) << " Euros\n";
						break;
					}
					cout << "Total income for " << Palace.hotelName << " hotel is " << Palace.hotelTotalIncome() << " Euros\n";
					break;
				}
				case 'e':
				case 'E': {
					return 0;
				}
				/*
				case 'c':
				case 'C':
				default:*/
				}
			}
			else if (userMenu == 'C' || userMenu == 'c') break; // Break is used here, because user can select and process many of his choises during a specific turn of the simulation.
		}
	}
	return 0;
}

int randomNumberGen(int min, int max) {	// Function to calculate a random number, using rand().
	int lowest, highest, range;
	lowest = min;
	highest = max;
	range = (highest - lowest) + 1;
	return (lowest + int(range*rand() / (RAND_MAX + 1.0)));
}

void sleep(unsigned int mseconds) {		// Function to sleep for MSECONDSmilliseconds.
	clock_t goal = mseconds + clock();
	while (goal > clock());
}