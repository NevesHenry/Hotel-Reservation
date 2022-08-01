/** Author: Henrique Reis Neves
 * SID: 100313047
 * 
 * Assignment 1:  Hotel Reservation
 * Hotel.h file
 * Last Update: 2022-05-28
**/

#ifndef HOTEL_H
#define HOTEL_H


#include <string>
#include <vector>
#include "Room.h"

/** Hotel Class
 * The Hotel class is the main class of the program.
 * It contains the hotel name, the number of rooms,
 * the number of available rooms, and the list of rooms.
 **/

class Hotel {
    private:
        string hotelName;
        int numberOfRooms;
        int numberOfAvailableRooms;
        vector<Room>* hotelRooms;
    public:

    /** Default constructor creates a hotel.
     * 0 rooms are created
     * The hotel name is set to "No Name".
     **/
    Hotel();

    /** Constructor creates a hotel with a given name.
     * Then, 100 rooms are created and all are available.
     * @param hotelName: The name of the hotel.
     **/
    Hotel(string);

    /** Constructor to create a new Hotel with the given values:
     * @param hotelName: The name of the hotel
     * @param numberOfRooms: The number of rooms in the hotel
     * @param numberOfAvailableRooms: The number of available rooms in the hotel
     * @param hotelRooms: The list of rooms in the hotel
     **/
    Hotel(string hotelName, int numberOfRooms, int numberOfAvailableRooms, vector<Room> hotelRooms);

//  Getters that return information about the Hotel

    /** Getter for the hotel name
     * @return The name of the hotel
     **/
    string getHotelName() const;

    /** Getter for the number of rooms
     * @return The number of rooms in the hotel
     **/
    int getNumberOfRooms() const;

    /** Getter for the number of available rooms
     * @return The number of available rooms in the hotel
     **/
    int getNumberOfAvailableRooms() const;

    /** Getter for the list of rooms
     * @return The list of rooms in the hotel
     **/
    vector<Room>* getRooms() const;

    //  Setters that change the values of the private attributes
    //  Each hotel has a unique name that cannot be changed.  

    /** Setter Total Number of Rooms
     * @param totalNumberOfRooms: The new number of rooms in the hotel
     **/
    void setTotalNumberOfRooms(int totalNumberOfRooms);

    // /** Setter for the number of available rooms
    //  * @param numberOfAvailableRooms: The new number of available rooms
    //  **/
    // void setNumberOfAvailableRooms(int numberOfAvailableRooms);

    // /** Setter for the list of rooms
    //  * @param rooms: The new list of rooms
    //  **/
    // void setRooms(vector<Room> rooms);

    // Print Hotel information
    void printHotel() const;

    /** Add a new room to the hotel
     * @param room: ID of the new room to be added
     **/
    void addRoom(string roomId);

    void addRoom(string roomId, int numberOfBeds);

    /** Remove a room from the hotel
     * @param roomId: The ID number of the room to be removed
     **/
    void removeRoom(string roomId);

    //  Check if a room is available
    //  @param roomID: Room to be checked
    //  @return true if the room is available, false otherwise
    bool isAvailable(string) const;

    /** Costumer request a room
     * @param checkInDate: The check-in date of the room
     * @param customerId: Id of the customer requesting the room
     * @param beds: Number of beds requested
     * @param stayDuration: Duration of the stay
     **/
    void requestRoom(string, string, int, int);
};
#endif