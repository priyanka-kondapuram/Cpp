/******************************************************************************************************

PROGRAM: A Class for Rational Numbers.

AUTHOR: Priyanka Kondapuram.
Z-ID: Z1795449.

DATE:10/26/2016

FUNCTION: This program implements all the member functions of a Rational class.

******************************************************************************************************/


#include "Rational.h"

// Method 1.
/* This public constructor is used to create a new Rational object with
   the numerator n and denominator d. If d = 0, it prints out an error
   message on stderr but it doesn’t stop the execution of the program.
   To reduce a Rational number to its lowest terms, it calls the private
   member function: int gcd ( int x, int y ) that returns the greatest
   common divisor of the arguments x and y. */

Rational::Rational(const int& n, const int& d)
{
 num = n;
 den = d;
 if(d == 0)
  cerr<<"Error: division by zero\n"; // Error message, if denominator is zero.
 int g = gcd(num, den); // Calling Method 1(i)- (gcd()).
 num = num/g;
 den = den/g;
}
// End of Method 1.



// Method 1(i).
/* This private method calculates and returns the greatest common divisor. */

int Rational::gcd(int x, int y)
{
 while(y != 0)
 {
  int r = x % y;
  x = y;
  y = r;
 }
 return x;
}
// End of Method 1(A).



// Method 2.
/* This public copy constructor is used to create a new Rational object from the copy of the Rational object r. */

Rational::Rational(const Rational& r)
{
 num = r.num;
 den = r.den;
}
// End of Method 2.



// Method 3.
/* This public assignment operator overwrites an existing Rational object with the copy of the Rational object r. */

Rational& Rational::operator = (const Rational& r)
{
 if(this != &r)
 {
  num = r.num;
  den = r.den;
 }
 return *this;
}
// End of Method 3.



// Methods 4, 5, 6, 7.
/* These four public member functions overload the operators +=, –=, *=, and /= operators,
   respectively, for the Rational class. */

/******************************************************************************************************************/

// Method 4.
Rational& Rational::operator += (const Rational& r)
{
 *this = *this + r; //Changing the current object by calling the 'operator +' constructor directly.
 return *this;
}
// End of Method 4.

// Method 5.
Rational& Rational::operator -= (const Rational& r)
{
 *this = *this - r; //Changing the current object by calling the 'operator -' constructor directly.
 return *this;
}
// End of Method 5.

// Method 6.
Rational& Rational::operator *= (const Rational& r)
{
 *this = *this * r; //Changing the current object by calling the 'operator *' constructor directly.
 return *this;
}
// End of Method 6.

// Method 7.
Rational& Rational::operator /= (const Rational& r)
{
 *this = *this / r; //Changing the current object by calling the 'operator /' constructor directly.
 return *this;
}
// End of Method 7.
/***********************************************************************************************************************/



// Methods 8 and 9.
/* These two public member functions overload the pre–increment (++) and pre–decrement (––) operators,
   respectively, for the Rational class. */

/***********************************************************************************************************************/

// Method 8.
Rational& Rational::operator ++ ()
{
 num +=den;
 return *this;
}
// End of Method 8.

// Method 9.
Rational& Rational::operator -- ()
{
 num -= den;
 return *this;
}
// End of Method 9.
/***********************************************************************************************************************/



// Methods 10 and 11.
/* These two public member functions overload the post–increment (++) and post–decrement (––) operators,
    respectively, for the Rational class. Note: To differentiate between the pre– and post– versions of
    the operators (++) and (––), an unused argument is included in the post–versions of these operators. */

/***********************************************************************************************************************/

// Method 10.
Rational Rational:: operator ++ (int unused)
{
 unused = 0;
 Rational temp(num,den);
 num += den + unused;
 return temp;
}
// End of Method 10.

// Method 11.
Rational Rational:: operator -- (int unused)
{
 unused = 0;
 Rational temp(num,den);
 num -= den + unused;
 return temp;
}
// End of Method 11.
/********************************************************************************************************************/



// Methods 12, 13, 14, 15.
/*These four friend functions overload the arithmetic operators +, –, *, and /, respectively, for the Rational class.*/

/*********************************************************************************************************************/

// Method 12.
Rational operator + (const Rational& r1, const Rational& r2)
{
 return Rational((r1.num * r2.den + r2.num * r1.den), (r1.den * r2.den)); // Returning directly by calling the copy constructor.
}
// End of Method 12.

// Method 13.
Rational operator - (const Rational& r1, const Rational& r2)
{
 return Rational((r1.num * r2.den - r2.num * r1.den), (r1.den * r2.den));
}
// End of Method 13.

// Method 14.
Rational operator * (const Rational& r1, const Rational& r2)
{
 return Rational((r1.num * r2.num), (r1.den * r2.den));
}
// End of Method 14.
// Method 15.
Rational operator / (const Rational& r1, const Rational& r2)
{
 return Rational((r1.num * r2.den), (r1.den * r2.num));
}
// End of Method 15.
/***********************************************************************************************************************/



// Methods 16, 17, 18, 19, 20, 21.
/* These six friend functions overload the relational operators ==, !=, <, <=, >, and >=, respectively, for the Rational class. */

/***********************************************************************************************************************/

// Method 16.
bool operator == (const Rational& r1, const Rational& r2)
{
 if(r1.num != r2.num)
  return false;
 if(r1.den != r2.den)
  return false;        // Returning false if the numerators and denominators are not equal.
 return true;
}
// End of Method 16.

// Method 17.
bool operator != (const Rational& r1, const Rational& r2)
{
 if(r1.num == r2.num)
  return false;
 if(r1.den == r2.den)
  return false;        // Returning false if the numerators and denominators are equal.
 return true;
}
// End of Method 17.

// Method 18.
bool operator < (const Rational& r1, const Rational& r2)
{
 if(r1.num >= r2.num)
  return false;
 if(r1.den >= r2.den)
  return false;        // Returning false if the numerators and denominators are greater than or equal to.
 return true;
}
// End of Method 18.

// Method 19.
bool operator <= (const Rational& r1, const Rational& r2)
{
 if(r1.num > r2.num)
  return false;
 if(r1.den > r2.den)
  return false;       // Returning false if the numerators and denominators are greater than.
 return true;
}
//End of Method 19.

// Method 20.
bool operator > (const Rational& r1, const Rational& r2)
{
 if(r1.num <= r2.num)
  return false;       // Returning false if the numerators are less than or equal to.
 return true;
}
// End of Method 20.

// Method 21.
bool operator >= (const Rational& r1, const Rational& r2)
{
 if(r1.num < r2.num)
  return false;       // Returning false if the numerators are less than.
 return true;
}
// End of Method 21.
/************************************************************************************************************************/



// Method 22.
/* This friend function overloads the stream insertion operator (<<) for the Rational class. It can be used to print out the Rational number r with the numerator num and denominator den as num/den on the output stream os, and if den = 1, it only prints out num. */

ostream& operator << (ostream& os, const Rational& r)
{
 if(r.den == 1)
  os<<r.num;    // Taking only the numerator, if the denominator is 1.
 else if(((r.num < 0) && (r.den <0)) || ((r.num * r.den < 0) && (r.num > 0)))
  os<<-r.num<<'/'<<-r.den; // Formatting the output to get postive rational number or making only the numerator negative.
 else
  os<<r.num<<'/'<<r.den;
 return os;
}
// End of Method 22.



/* This friend function overloads the stream extraction operator (>>) for the Rational class. It can be used to read the Rational number r from the input stream is, where each Rational number is given on a separate line with its three arguments: numerator, separator (/), and denominator, separated one or more white spaces. If a line in is does not contain a valid Rational number, it prints out an error message on stderr but it doesn’t stop the execution of the program. */
// Method 23.

istream& operator >> (istream& is, Rational& r)
{
 char c;
 string line;
 getline(is,line); // Getting each line as a string.
 istringstream ss(line);
 ss>>r.num; // Storing the first number as the numerator.
 ss>>c; // Getting the next character into a variable c.
 if(ss.fail())
  r.den = 1; // Storing denominator with 1, when a single number is given.
 if(c=='/')
 {
  ss>>r.den; // Getting the next numbers after the '/' character.
  ss>>c;
  if( !ss.fail())
   cerr<<"Error: line "<<'"'<<line<<'"'<<" contains invalid number"<<endl; // Error Message.
 }
 else
  cerr<<"Error: line "<<'"'<<line<<'"'<<" contains invalid number"<<endl; // Error Message.
 return is; // Returning the stream.
}
// End of Method 23.

// End of Program.
