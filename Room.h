/** Author: Henrique Reis Neves
 * SID: 100313047
 * 
 * Assignment 1:  Hotel Reservation
 * Room.h file
 * Last Update: 2022-05-28
 **/


#ifndef ROOM_H
#define ROOM_H

#include "Customer.h"
#include "Date.h"
using namespace std;

/** The Room has information such as the customer who’s 
 * currently occupying it, when the customer gets the room (check in date), 
 * when the customer is leaving the room (check out date), and the number of 
 * beds in the room.
 **/

class Room {
    private:
        string roomID;
        Customer* roomCustomer;
        Date* checkIn;
        Date* checkOut;
        int staysDuration;
        int beds;
        bool available;
    public:
    /** The default constructor has no parameters.
     *  It creates a Room with one bed and zero Customer in it.
     * There is no checkin and checkout date.
     **/
    Room();

    /** The constructor has one parameter: the room ID.
     * It creates a Room with one bed and zero Customer in it.
     * There is no checkin and checkout date.
     * @param roomID: The room ID.
     **/
    Room(string id);

    /** The constructor has two parameters: the room ID and the number of beds.
     * It creates a Room with a given number of beds and zero Customer in it.
     * There is no checkin and checkout date.
     * @param roomID: The room ID.
     * @param beds: The number of beds in the room.
     **/
    Room(string id, int beds);

    /** Constructor to create a new Room with the given values. 
     * Duration is calculated from checkIn and checkOut
     * @param RoomID: The ID of the Room.
     * @param Customer: Customer who's currently occupying the room
     * @param checkIn: Date when the customer gets the room
     * @param checkOut: Date when the customer is leaving the room
     * @param beds: Number of beds in the room.
     **/
    Room(string, Customer&, Date&, Date&, int);

    /**  Constructor to create a new Room with the given values.
     * CheckOut date is calculated from checkIn and stayDuration.
     * @param RoomID: The ID of the Room.
     * @param Customer: Customer who's currently occupying the room
     * @param checkIn: Date when the customer gets the room
     * @param stayDuration: Number of days the customer stays in the room
     * @param beds: Number of beds in the room
     **/
    Room(string, Customer&, Date&, int, int);

    /** Copy constructor to create a new Room with the same values as the given Room.
     * @param other: Room to be copied
     **/
    Room(const Room&);
    
    //  Getters that return information about the Room
    string getRoomId() const;
    Customer& getCustomer() const;
    Date& getCheckIn() const;
    Date& getCheckOut() const;
    int getStaysDuration() const;
    int getBeds() const;
    
    // //  Check if the room is available
    bool isAvailable() const;

    // //  Setters that change the values of the private attributes
    void setCustomer(Customer&);
    void setCheckIn(Date&);
    void setCheckOut(Date&);
    void setStaysDuration(int);
    void setBeds(int);
    void setAvailable(bool);

    // Print Room information
    void printRoom() const;

};

#endif