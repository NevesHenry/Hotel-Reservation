/** Author: Henrique Reis Neves
 * SID: 100313047
 * 
 * Assignment 1:  Hotel Reservation
 * Customer.h file
 * Last Update: 2022-05-25
 **/


#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;
/** Customer Class
 * The Customer class carries the customer ID and the 
 * number of requested beds.
 **/
class Customer{
    private:
        string CustomerID;
        int requestedBeds;

    public:
    /** The default constructor has no parameters.
     *  It creates a Customer with a random ID number and a one bed request
     **/
    Customer();

    /**  Constructor to create a new Customer with the given values:
     * @param CustomerID: Customer ID
     * @param requestedBeds: Number of requested beds
     **/
    Customer(string CustomerID, int requestedBeds);

    //Copy constructor
    Customer(const Customer&);

    // Destructor
    //Customer uses the defaut destructor

    //  Getters that return information about the Customer

    string getCustomerID() const;
    int getRequestedBeds() const;

    //  Setters that change the values of the private attributes
    //  Each customer has a unique ID that cannot be chamged.

    void setRequestedfBeds(int);

    // Print Customer information
    void printCustomer() const;

};

#endif
