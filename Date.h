/** Author: Henrique Reis Neves
 * SID: 100313047
 * 
 * Assignment 1:  Hotel Reservation
 * Date.h file
 * Last Update: 2022-05-27
 **/


#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

/** Date class stores the data in a format xx/xx/xxxx
 * Or as a separete input of day, month, year
 **/

class Date {
    private:
        string dateString;
        int day;
        int month;
        int year;

    public:
    //Creates a ramdom date
    Date();

    // Creates a date if given the format "xx/xx/xxxx"
    Date(string s);

    /** Creates a date if given the parameters
     * @param day the day of the month
     * @param month the month of the year
     * @param year the year
     **/
    Date(int, int, int);

    // Copy constructor
    Date(const Date&);

    //Getters and Setters

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    string getDateAsString() const;

    // Setters
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setDateAsString(string);

    //Operators
    
    /** Overloads the minus operator to subtract two dates
     * @param d1: the date to be subtracted
     * @param d2: the date to be subtracted
     * @return the difference of the two dates
     **/
    friend int operator - (const Date&, const Date&);

    Date* addInterger(int);

    //Prints the date
    void printDate() const;
    //string dateToString(int,int,int);
};
#endif