/** Author: Henrique Reis Neves
 * 
 * Hotel Reservation
 * Room.cpp file
 * Last Update: 2022-08-01
 **/

#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(){
    this->roomID = "999";
    this->roomCustomer = nullptr;
    this->checkIn = nullptr;
    this->checkOut = nullptr;
    this->staysDuration = 0;
    this->beds = 1;
    this->available = true;
}

Room::Room(string id){
    this->roomID = id;
    this->roomCustomer = nullptr;
    this->checkIn = nullptr;
    this->checkOut = nullptr;
    this->staysDuration = 0;
    this->beds = 1;
    this->available = true;
}

Room::Room(string id, int beds){
    this->roomID = id;
    this->roomCustomer = nullptr;
    this->checkIn = nullptr;
    this->checkOut = nullptr;
    this->staysDuration = 0;
    this->beds = beds;
    this->available = true;
}

Room::Room(string id, Customer& roomCustomer, Date& checkIn, Date& checkOut, int beds) {
    this->roomID = id;
    this->roomCustomer = &roomCustomer;
    this->checkIn = &checkIn;
    this->checkOut = &checkOut;
    this->staysDuration = checkOut - checkIn;
    this->beds = beds;
    this->available = false;
}

Room::Room(string id, Customer& roomCustomer, Date& checkIn, int stayD , int beds) {
    this->roomID = id;
    this->roomCustomer = &roomCustomer;
    this->checkIn = &checkIn;
    this->staysDuration = stayD;
    this->checkOut = &checkIn + stayD;
    this->beds = beds;
    this->available = false;
}

Room::Room(const Room& other) {
    this->roomID = other.roomID;
    this->roomCustomer = other.roomCustomer;
    this->checkIn = other.checkIn;
    this->checkOut = other.checkOut;
    this->staysDuration = other.staysDuration;
    this->beds = other.beds;
    this->available = other.available;
}

string Room::getRoomId() const {
    return this->roomID;
}

Customer& Room::getCustomer() const {
    return *this->roomCustomer;
}

Date& Room::getCheckIn() const {
    return *this->checkIn;
}

Date& Room::getCheckOut() const {
    return *this->checkOut;
}

int Room::getStaysDuration() const {
    return this->staysDuration;
}

int Room::getBeds() const {
    return this->beds;
}

bool Room::isAvailable() const {
    return this->available;
}

void Room::setCustomer(Customer& newCustomer) {
    this->roomCustomer = &newCustomer;
}

void Room::setCheckIn(Date& newCheckIn) {
    this->checkIn = &newCheckIn;
}

void Room::setCheckOut(Date& newCheckOut) {
    this->checkOut = &newCheckOut;
}

void Room::setStaysDuration(int newStaysDuration) {
    this->staysDuration = newStaysDuration;
}

void Room::setBeds(int newBeds) {
    this->beds = newBeds;
}

void Room::setAvailable(bool isAvailable) {
    this->available = isAvailable;
}

void Room::printRoom() const {
    cout << "---------------------------------" << endl;
    cout << "Room ID: " << this->roomID << endl;
    cout << "Beds: " << this->getBeds() << endl;
    if(!this->isAvailable()) {
        cout << "Customer: " << this->getCustomer().getCustomerID() << endl;
        cout << "Check-in: " << this->getCheckIn().getDateAsString() << endl;
        cout << "Check-out: " << this->getCheckOut().getDateAsString() << endl;
        cout << "Stays duration: " << this->getStaysDuration() << endl;
    }
    else {
        cout << "No customer in this room." << endl;
    }
    cout << "---------------------------------" << endl;
}
