/**************************************************************************************************************

PROGRAM  : The Date Class

AUTHOR   : Priyanka Kondapuram.
Z-ID     : Z1795449

DATE     : 10/10/2016

FUNCTION : Including all the system header files, declaring all the functions and declaring all the constants.

**************************************************************************************************************/

#ifndef PRI_PRG6
#define PRI_PRG6

#include<iostream>
#include<string>
#include<sstream> // Including String stream.
#include<vector> // Including Vectors.

using namespace std;

const int X1 = 31;
const int X2 = 30;
const int X3 = 29; // Declaring the constant values for number of days in a month.
const int X4 = 28;
const int V1 = 1;
const int V2 = 0;
const vector<string> months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // Declaring a Vector of strings.

const string MONTH = "January";
const int DAY = 1;               // Setting the default values.
const int YEAR = 2000;



class Date
{

 private:

  string month;
  int day, year;
  bool isValidMonth() const;  // Private Method 5(A).
  int daysInMonth(const string& m) const; // Private Method 5(B).
  bool isLeapYear() const; // Private Method 5(B(a)).
  string intToString(int n) const; // Private Method 6(A).
  int monthIndex(); // Private Method 15.

 public:

  Date(const string& m = MONTH, const int& d = DAY, const int& y = YEAR); // Method 1.

  void setMonth(const string& m); // Method 2(A).
  void setDay(const int& d); // Method 2(B).
  void setYear(const int& y); // Method 2(C).

  string getMonth() const; // Method 3(A).
  int getDay() const; // Method 3(B).
  int getYear() const; // Method 3(C).

  void Month(); // Method 4.

  bool isValidDate() const; // Method 5.

  string toString() const; // Method 6.

  Date(const Date& d); // Method 9.
  Date& operator= (const Date& d); // Method 10.
  Date& addDay(const int& n); // Method 11.
  Date& addMonth(const int& n); // Method 12.
  Date& addYear(const int& n); // Method 13.
  int dayIndex() const; // Method 14.


 friend istream& operator>>(istream& is, Date& d); // Method 7 (Friend).
 friend ostream& operator<<(ostream& os, const Date& d); // Method 8 (Friend).
};

unsigned dateDiff(const Date &, const Date &); // Non-member Function (Method 16.)

#endif
