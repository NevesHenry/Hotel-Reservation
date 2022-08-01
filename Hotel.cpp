/** Author: Henrique Reis Neves
 * 
 * Hotel Reservation
 * Hotel.h file
 * Last Update: 2022-08-01
**/

#include "Hotel.h"
#include <iostream>

Hotel::Hotel(){
    this->hotelName = "NoName";
    this->numberOfRooms = 0;
    this->numberOfAvailableRooms = 0;
    this->hotelRooms = new vector<Room>();

    // for(int i = 0; i < numberOfRooms; i++){
    //     this->hotelRooms->push_back(Room(to_string(i)));
    // }
}

Hotel::Hotel(string hotelName){
    this->hotelName = hotelName;
    this->numberOfRooms = 100;
    this->numberOfAvailableRooms = 100;
    this->hotelRooms = new vector<Room>();

    for(int i = 0; i < numberOfRooms; i++){
        this->hotelRooms->push_back(Room(to_string(i)));
    }
}

Hotel::Hotel(string hotelName, int numberOfRooms, int numberOfAvailableRooms, vector<Room> hotelRooms){
    this->hotelName = hotelName;
    this->numberOfRooms = numberOfRooms;
    this->numberOfAvailableRooms = numberOfAvailableRooms;
    this->hotelRooms = &hotelRooms;
}

string Hotel::getHotelName() const{
    return this->hotelName;
}

int Hotel::getNumberOfAvailableRooms() const{
    return this->numberOfAvailableRooms;
}

int Hotel::getNumberOfRooms() const{
    return this->numberOfRooms;
}

void Hotel::setTotalNumberOfRooms(int numberOfRooms){
    this->numberOfRooms = numberOfRooms;

    while(this->hotelRooms->size() < numberOfRooms){
        this->hotelRooms->push_back(Room(to_string(this->hotelRooms->size())));
    }

    while(this->hotelRooms->size() > numberOfRooms){
        this->hotelRooms->pop_back();
    }
}

void Hotel::addRoom(string roomId){
    this->hotelRooms->push_back(Room(roomId));
    this->numberOfRooms++;
    this->numberOfAvailableRooms++;
}

void Hotel::addRoom(string roomId, int numberOfBeds){
    this->hotelRooms->push_back(Room(roomId, numberOfBeds));
    this->numberOfRooms++;
    this->numberOfAvailableRooms++;
}

void Hotel::removeRoom(string roomId){
    for(int i = 0; i < this->hotelRooms->size(); i++){
        if(this->hotelRooms->at(i).getRoomId() == roomId){
            this->hotelRooms->erase(this->hotelRooms->begin() + i);
            this->numberOfRooms--;
            this->numberOfAvailableRooms--;
        }
    }
}

vector<Room>* Hotel::getRooms() const{
    return this->hotelRooms;
}

void Hotel::printHotel() const{
    cout << "Hotel Name: " << this->hotelName << endl;
    cout << "Number of Rooms: " << this->numberOfRooms << endl;
    cout << "Number of Available Rooms: " << this->numberOfAvailableRooms << endl;
    cout << "Rooms: " << endl;
    for(int i = 0; i < this->numberOfRooms; i++){
        // cout << "Room " << i << ": " << endl;
        this->hotelRooms->at(i).printRoom();
    }
}

void Hotel::requestRoom(string checkIn, string customerId, int beds, int stayDuration){
    // Create a customer Object
    Customer* c = new Customer(customerId, beds);
    Date* checkInDate = new Date(checkIn);

    if(this->numberOfAvailableRooms > 0){
        for(int i = 0; i < this->numberOfRooms; i++){
            if(this->hotelRooms->at(i).getBeds() == beds){
                this->hotelRooms->at(i).setAvailable(false);
                this->hotelRooms->at(i).setCustomer(*c);
                this->hotelRooms->at(i).setCheckIn(*checkInDate);
                this->hotelRooms->at(i).setStaysDuration(stayDuration);
                this->hotelRooms->at(i).setCheckOut(*this->hotelRooms->at(i).getCheckIn().addInterger(this->hotelRooms->at(i).getStaysDuration()));
                this->numberOfAvailableRooms--;
                break;
            }
        }
    }
    cerr << "No available rooms" << endl;
}
