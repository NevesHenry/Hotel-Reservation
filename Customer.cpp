/** Author: Henrique Reis Neves
 * 
 * Hotel Reservation
 * Customer.cpp file
 * Last Update: 2022-05-27
**/

#include <string>
#include <iostream>
#include <time.h>
#include "Customer.h"
using namespace std;


Customer::Customer() : requestedBeds(1) {
    char charset [36] = {'1','2','3','4','5','6','7','8','9','0',
                        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
                        };
    for(int i = 0; i < 10; i++){
        this->CustomerID += charset[rand() % 36];
    }
}

Customer::Customer(string CustomerID, int requestedBeds) : CustomerID(CustomerID), requestedBeds(requestedBeds){}

Customer::Customer(const Customer& otherCustomer) : CustomerID(otherCustomer.CustomerID), requestedBeds(otherCustomer.requestedBeds){}


string Customer::getCustomerID() const{
    return this->CustomerID;
}
    
int Customer::getRequestedBeds() const {
    return this->requestedBeds;
}

void Customer::setRequestedfBeds(int requestedBeds) {
    this->requestedBeds = requestedBeds;
}

void Customer::printCustomer() const{
    cout << "---------------------------------" << endl;
    cout << "Customer ID: " << this->CustomerID << endl;
    cout << "Customer Requested " << this->requestedBeds << " Beds." << endl;
    cout << "---------------------------------" << endl;
}
