/** Author: Henrique Reis Neves
 * 
 * Hotel Reservation
 * Date.cpp file
 * Last Update: 2022-08-01
 **/

#include <string>
#include <iostream>
#include "Date.h"
#include <time.h>
using namespace std;

Date::Date(){
    srand(time(0));
    this->day = rand() % 31 + 1;
    this->month = rand() % 12 + 1;
    this->year = rand() % 5 + 2019;
    this->dateString = to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year);
    
}

Date::Date(string s){
    this->day = stoi(s.substr(0,2));
    this->month = stoi(s.substr(3,2));
    this->year = stoi(s.substr(6,4));
    this->dateString = s;
}

Date::Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
    dateString = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

Date::Date(const Date& otherDate){
    this->day = otherDate.day;
    this->month = otherDate.month;
    this->year = otherDate.year;
    this->dateString = otherDate.dateString;
}

int Date::getDay() const{
    return this->day;
}

int Date::getMonth() const{
    return this->month;
}

int Date::getYear() const{
    return this->year;
}

string Date::getDateAsString() const{
    return this->dateString;
}

void Date::setDay(int day){
    this->day = day;
}

void Date::setMonth(int month){
    this->month = month;
}

void Date::setYear(int year){
    this->year = year;
}

void Date::setDateAsString(string dateString){
    this->dateString = dateString;
}

int operator - (const Date& d1, const Date& d2){
    int days = 0;
    if(d1.year > d2.year){
        days = (d1.year - d2.year) * 365;
    }
    if(d1.month > d2.month){
        days = days + (d1.month - d2.month) * 30;
    }
    if(d1.day > d2.day){
        days = days + (d1.day - d2.day);
    }
    return days;
}

Date* Date::addInterger(int d){
    Date* newDate = new Date();
    newDate->day = this->day + d;
    newDate->month = this->month;   
    newDate->year = this->year;
    if(newDate->day > 30){
        newDate->day = newDate->day - 30;
        newDate->month = newDate->month + 1;
    }
    if(newDate->month > 12){
        newDate->month = newDate->month - 12;
        newDate->year = newDate->year + 1;
    }
    newDate->dateString = to_string(newDate->day) + "/" + to_string(newDate->month) + "/" + to_string(newDate->year);
    return newDate;
    // this->day = this->day + d;
    // if(this->day > 30){
    //     this->day = this->day - 30;
    //     this->month = this->month + 1;
    // }
    // if(this->month > 12){
    //     this->month = this->month - 12;
    //     this->year = this->year + 1;
    // }
    // this->dateString = to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year);
}

void Date::printDate() const{
    cout << this->day << "/" << this->month << "/" << this->year << endl;
}

string dateToString(int d, int m, int y){
    string s = "";
    s = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
    return s;
}
