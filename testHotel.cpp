/** Author: Henrique Reis Neves
 * 
 * Hotel Reservation
 * testHotel.cpp file
 * Last Update: 2022-08-01
**/

#include "Customer.h"
#include "Date.h"
#include "Room.h"
#include "Hotel.h"
#include <iostream>
using namespace std;

// Test Customers class:
void testCustomer(){
    
    cout << "Test Customers class:" << endl;
    Customer* c1 = new Customer();
    Customer* c2 = new Customer("B9KAHXT1HH", 4);

    c1->printCustomer();
    c2->printCustomer();

    cout << "Test setRequestedBeds() in Customer " << c1->getCustomerID() << endl;
    c1->setRequestedfBeds(15);
    c1->printCustomer();

    delete c1;
    delete c2;
    // no need to set c1,c2 to nullptr because it gone out of scope
}

// Test the Date class:
void testDate(){
    cout << "Test the Date class:" << endl;

    // Constructors
    Date* d1 = new Date();
    Date* d2 = new Date(27, 5, 2020);
    Date* d3 = new Date("03/07/2019");
    
    cout << "D1: "; d1->printDate();
    cout << "D2: "; d2->printDate();
    cout << "D3: "; d3->printDate();

    cout << "---------------------------------" << endl;
     // Test the getters and setters
    cout << "D2 Day: " << d2->getDay() << endl;
    cout << "D2 Month: " << d2->getMonth() << endl;
    cout << "D2 Year: " << d2->getYear() << endl;
    cout << "D2 Date: " << d2->getDateAsString() << endl;
    cout << "---------------------------------" << endl;

    d2->setDay(28);
    d2->setMonth(6);
    d2->setYear(2029);
    d2->setDateAsString("28/06/2029");

    cout << "D2 after setters: "; d2->printDate();

    cout << "---------------------------------" << endl;
    // Test copy constructor
    Date* d4 = d1;
    cout << "D4 = D1: "; d4->printDate();
    
    Date* d5 = new Date(27, 5, 2020);
    Date* d6 = new Date(28, 6, 2020);

    // Test subtracting dates
    int daysStay = *d6 - *d5;
    cout << "D5: "; d5->printDate();
    cout << "D6: "; d6->printDate();
    cout << "Days stay: " << daysStay << endl;

    cout << "---------------------------------" << endl;


    delete d1;
    delete d2;
    delete d3;
    //delete d4;    TODO: fix this (d4 is not using the copy constructor. It's pointing to the same memory address of d1)
    delete d5;
    delete d6;
    // no need to set d1,d2,d3,d4,d5,d6 to nullptr because it gone out of scope 
}

// Test the Room class:
void testRoom(){

    cout << "Test the Room class:" << endl;

    // Constructors
    Room* r1 = new Room();
    r1->printRoom();
    Customer* c3 = new Customer("B9KAHXT1HH", 4);
    Date* d5 = new Date(27, 5, 2020);
    Date* d6 = new Date(28, 6, 2020);
    
    Room* r2 = new Room(to_string(101),*c3, *d5, *d6, 2);
    r2->printRoom();

}

void testHotel(){
    Hotel* h1 = new Hotel();

    h1->printHotel();
}

// The assignment Hotel have 100 rooms with only one bed, 50 rooms with 2 beds 
// and 30 rooms with 3 beds.
Hotel* assignment1_hotel_build(){
    Hotel* h1 = new Hotel("Assignment 1 Hotel");
    

    // 100 rooms with only one bed
    for(int i = 0; i < 100; i++){
        h1->addRoom(to_string(i+1), 1);
    }

    // 50 rooms with 2 beds
    for(int i = 0; i < 50; i++){
        h1->addRoom(to_string(i+101), 2);
    }

    // 30 rooms with 3 beds
    for(int i = 0; i < 30; i++){
        h1->addRoom(to_string(i+151), 3);
    }
    return h1;
}


int main() {

    /**
     * @brief A whole bunch of tests to check the correctness of the code
     * 
     */
    // testCustomer();
    // // -------------------------------------------------- //
    // testDate();
    // // // -------------------------------------------------- //
    // testRoom();
    // -------------------------------------------------- //
    // testHotel();

    Hotel* assignment = assignment1_hotel_build();
    
    assignment->printHotel();

    return 0;
}
