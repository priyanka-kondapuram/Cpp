/******************************************************************************************************

PROGRAM: A Class for Rational Numbers.

AUTHOR: Priyanka Kondapuram.
Z-ID: Z1795449.

DATE:10/26/2016

FUNCTION: This program implements all the member functions of a Rational class.

******************************************************************************************************/

#ifndef PRI_PRG8
#define PRI_PRG8

#include<iostream>
#include<string>
#include<sstream> // Including String stream.

using namespace std;

class Rational
{

 private:

  int num, den;
  int gcd(int, int); // Method 1(i).

 public:

  Rational(const int& n = 0, const int& d = 1); // Method 1.

  Rational(const Rational&); // Method 2.

  Rational& operator = (const Rational&); // Method 3.

  Rational& operator += (const Rational&);
  Rational& operator -= (const Rational&);         // Methods 4, 5, 6, 7.
  Rational& operator *= (const Rational&);
  Rational& operator /= (const Rational&);

  Rational& operator ++ (); // Method 8.
  Rational& operator -- (); // Method 9.

  Rational operator ++ (int unused); // Method 10.
  Rational operator -- (int unused); // Method 11.

 friend Rational operator + (const Rational&, const Rational&);
 friend Rational operator - (const Rational&, const Rational&);
 friend Rational operator * (const Rational&, const Rational&);    // Methods 12, 13, 14, 15.
 friend Rational operator / (const Rational&, const Rational&);

 friend bool operator == (const Rational&, const Rational&);
 friend bool operator != (const Rational&, const Rational&);
 friend bool operator < (const Rational&, const Rational&);      // Methods 16, 17, 18, 19, 20, 21.
 friend bool operator <= (const Rational&, const Rational&);
 friend bool operator > (const Rational&, const Rational&);
 friend bool operator >= (const Rational&, const Rational&);

 friend ostream& operator << (ostream&, const Rational&); // Method 22.
 friend istream& operator >> (istream&, Rational&); // Method 23.

};


#endif
