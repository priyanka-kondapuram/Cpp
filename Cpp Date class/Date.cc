/******************************************************************************************************

PROGRAM: The Date Class.

AUTHOR: Priyanka Kondapuram.
Z-ID: Z1795449.

DATE:10/10/2016

FUNCTION: This program implements all the member functions and non-member functions of the Date class.

******************************************************************************************************/



#include"Date.h" // Including the header file.


// Method 1
/* This This is a public constructor that can be used to create a Date object for the month m, day d,
   and year y, where MONTH = “January”, DAY = 1, and YEAR = 2000 are the default values.*/

Date::Date(const string& m, const int& d, const int& y)
{
 month = m;
 day = d;    // Storing the respective variables in month, day, year and call the method 4 (Month()).
 year = y;
 Month();
}
// End of Method 1.



// Method 2(A)
/* This method is used to set the month. */

void Date::setMonth(const string& m)
{
 month = m;
 Month(); // Calling Month() - (Method 4)
}
// End of Method 2(A).



// Method 2(B)
/* This method is used to set the day. */

void Date::setDay(const int& d)
{
 day = d;
}
// End of Method 2(B).



// Method 2(C)
/* This method is used to set the year. */

void Date::setYear(const int& y)
{
 year = y;
}
// End of Method 2(C).



// Method 3(A)
/* This method is used to return the month. */

string Date::getMonth() const
{
 return month;
}
// End of Method 3(A).



// Method 3(B)
/* This method is used to return the day. */

int Date::getDay() const
{
 return day;
}
// End of Method 3(B).



// Method 3(C)
/* This method is used to return th year. */

int Date::getYear() const
{
 return year;
}
// Method 3(C).



// Method 4
/* This public member function is used to convert the month component of a Date object by changing its first letter
   to uppercase and the rest of its letters to lowercase, so the month of a date can be entered as case insensitive. */

void Date::Month()
{
 if(islower(month[0])) // Condition for checking if the starting letter of the month is lower letter.
  month[0] = toupper(month[0]); // Converting it into uppercase.
 for(unsigned i=1; i<month.length(); i++) // Loop for checking the rest of the letters of the month.
 {
  if(isupper(month[i]))
   month[i] = tolower(month[i]); // Converting the letters to lowercase.
 }
}
// End of the Method 4.



// Method 5
/* This public member function checks a Date object, and if it’s a valid date, it returns true;
   otherwise, it returns false. It calls the private member function bool isValidMonth ( ) const to
   check if the month component is valid, and it calls the private member function int daysInMonth ( const string& m ) const
   to return the number of days in the month m to check if the day component is valid. If the month m is February, the function
   daysInMonth ( ) calls the private member function bool isLeapYear ( ) const to get the correct number of days in the month m. */

bool Date::isValidDate() const
{
 if(year!=0) // Condition for checking if the year is greater than 0.
 {
  if(isValidMonth()) // Calls isValidMonth() - (Method 5(A))
  {
   int max_days = daysInMonth(getMonth()); // Stores the days of a month by calling daysInMonth() - (Method 5(B))
   if(day <= max_days)
    return true;
   else           // Returning true if the day is less than or equal to the maximum days in that month, else returning false.
    return false;
  }
  else
   return false; // Returning false if the month is not a valid month.
 }
 else
  return false; // Returning false where year has negative or other values.
}
// End of Method 4.



// Method 5(A).
/* This method is used to check if the month component is valid */

bool Date::isValidMonth() const
{
 int v = 0;
 for(unsigned i=0; i<months.size(); i++) // Loop for comparing the month values with the values in the months vector.
 {
  if(month == months[i]) // Condition for checking if the month is equal to the string in the vector months.
  {
   v = 1; // Setting the variable v to 1 if true.
   break;
  }
 }
 if(v == 1)
  return true; // Returning true if the month is same as the month in the vector.
 else
  return false; // Else returning false.
}
// End of Method 5(A).



// Method 5(B).
/* This method is used to return the number of days in the month m to check if the day
   component is valid. If the month m is February, the function daysInMonth () calls the private
   member function bool isLeapYear ( ) const to get the correct number of days in the month m. */

int Date::daysInMonth(const string& m) const
{
 if(m == months[0] || m == months[2] || m == months[4] || m == months[6] || m == months[7] || m == months[9] || m == months[11])
  return X1; // Returning X1(31) for the months 'Jan', 'mar', 'may', 'july', 'aug', 'oct', 'dec'.

 else if(m == months[1]) // Condition for month 'February'.
 {
  if(isLeapYear()) // Condition for checking if the year is a leap year by calling isLeapYear() - (5(B(a)))
   return X3; // Returning 29 days.
  else
   return X4; // Returning 28 days.
 }

 else
  return X2; // Returning X2(30) for the months 'apr' 'june' 'sept' 'nov'.
}
// End of method 5(B).



// Method 5(B(a))
/* This Method is used to get the correct number of days in the month m. */

bool Date::isLeapYear() const
{

 if(year % 4 == 0 && year % 100 == 0 && year % 400 == 0) // Condition for checking if the year comes after 4 years.
  return true;
 else if(year % 4 == 0 && year % 100 != 0)
  return true;
 return false; // Returns false if the condtition fails.
}
// End of Method 5(B(a))



// Mehthod 6
/* This public member function can be used to convert the month component of a Date object in the form dd–mmm–yyyy,
   where dd is a one- or two-digit date, mmm the three-letter abbreviation for the month, and yyyy is the four-digit year. */

string Date::toString() const
{
 string str1 = "";
 str1 = intToString(day) + "-" + month.substr(0,3) + "-" + intToString(year); // Storing the string in the form dd-mmm-yyyy and calling the method inToString - (Method 6(A)).
 return str1; // Returning the string.
}
// End of Method 6.



// Method 6(A).
/* This method takes the integer value n and returns its corresponding value as a string. */

string Date::intToString(int n) const
{
 ostringstream ost; // Declaring ostringstream variable.
 ost<<n;
 return ost.str(); // Returning the value as string.
}
// End of Method 6(A).



//Method 7
/* This method reads the individual date components from the stream is to the Date object d, where a date can be
   entered either in the form month day year or month day, year. This method uses the unget function to get the characters. */

istream& operator>> (istream& is, Date& d)
{
 char ch;
 is>>d.month>>d.day>>ws>>ch; // Reads month, day, and the next character excluding the white spaces.
 if(isdigit(ch)) // Condition for checking if the character is a digit.
 {
  is.unget(); // Taking the character.
  is>>d.year; // Setting the character as year.
 }
 else
 {
  is.get();
  is>>ws;         // Else setting the other digits into year.
  is>>d.year;
 }
 return is;
}
// End of Method 7.



// Method 8.
/* This non-member function is implemented as a friend to the Date class, which overloads the insertion operator (<<).
   It gets the individual components from the Date object d and to the stream os, where d is inserted in os in the form month day, year. */

ostream& operator<< (ostream& os, const Date& d)
{
 os<<d.month<<" "<<d.day<<","<<" "<<d.year; // Formatting the output by setting the white spaces and coma.
 return os;
}
// End of Method 8.



// Method 9.
/* This is a public copy constructor that is used to create a new Date object from the copy of the Date object d. */

Date::Date(const Date& d)
{
 day = d.day;
 month = d.month;
 year = d.year;
 Month();   // Calling month() (Method 4).
}
// End of Method 9.



// Method 10.
/* This is a public assignment operator that overwrites an existing Date object with the copy of the Date object d. */

Date& Date::operator=(const Date& d)
{
 if(this != &d) // Condition for checking the self assignment.
 {
  day = d.day;
  month = d.month;
  year = d.year;
 }
 return *this; // Returning the current object.
}
// End of Method 10.



// Method 11.
/* This public function is used to add n number of days to a Date object. */

Date & Date::addDay (const int& n)
{
 int totalDays =n;
 int dim = daysInMonth(getMonth()); // Storing the daysInMonth of the current month.
 int m;
 if(totalDays > 0) // Condition for checking if the total days are positive.
 {
  if((dim-day) >= n)
  {
   day = day+n; // Adding the total days.
  }
  else
  {
   totalDays = totalDays - (dim-day);
   while(totalDays > 0) // Loop for getting all the days greater than 0.
   {
    m = monthIndex();
    if(m+1 <= 11) // Condition for checking if the month is between Feb to Dec.
     month = months[m+1]; //Going to the next month.
    else
    {
     month = months[0]; // Storing January in month.
     year = year+1; // Getting the next year.
    }
    dim = daysInMonth(getMonth()); // Getting the days on the month.
    day = 0;
    if(totalDays > dim)
     totalDays = totalDays-dim; // Storing the difference of the days and actual days in the month, if value is greater than dayInMonth.
    else
    {
     day = totalDays;
     totalDays = 0;
    }
   }
  }
 }
 if(totalDays < 0) // Condition for checking if the total days are negative.
 {
  for(int i=n; i<0; i++)
  {
   if(day == 1) // Checking the day is equal to 1.
   {
    m = monthIndex(); // storing the month index by calling monthIndex() (Method 15)
    if(m-1 >= 0)
     month = months[m-1]; // Getting the previous month.
    else
    {
     month = months[11]; // Getting the last month from the months Vector.
     year = year-1;
     if(year == 0)
      year = -1; // Storing the negative year.
    }
    day = daysInMonth(getMonth());
   }
   else
    day = day-1;
  }
 }
 return *this;
}
// End of Method 11.



// Method 12.
/* This public function is used to add n number of months to a Date object.
   If the day of the resulting month is larger than the number of days in
   that month, then we choose the following month with day = 1. */

Date& Date::addMonth(const int& n)
{
 int m = monthIndex();
 if(n < 0) // Checking if the month is less than 0.
 {
  int i=0;
  while(i<-(n)) // Loop for taking the all the negative values.
  {
   if(m-1 >= 0)
   {
    month = months[m-1]; // Storing the previous month.
    m = m-1;
   }
   else
   {
    month = months[11]; // Taking the december month from months vector.
    year = year-1;
    if(year == 0)
     year = -1;
    m = 11;
   }
   i++;
  }
  if(day > daysInMonth(getMonth()))
  {
   m = monthIndex();
   day = 1;
   if(m+1 <= 11) // Checking if the months dont exceed the max number of months.
   {
    month = months[m+1];
   }
   else
   {
    month = months[0];
    year = year+1;
    if(year == 0)
     year = 1;
   }
  }
 }
 if(n > 0) // Condition for checking if the month is greater than 0.
 {
  for(int i=0; i<n; i++)
  {
   if(m+1 <= 11)
   {
    month = months[m+1];
    m = m+1;
   }
   else
   {
    month = months[0]; // Taking the 1st month.
    year = year+1;
    if(year == 0) // Condition to check if the year value is equal to 0.
     year = 1;
    m = 0;
   }
  }
  if(day > daysInMonth(getMonth()))
  {
   m = monthIndex(); // Getting the month index by calling monthIndex() (Method 15)
   day = 1;
   if(m+1>11)
   {
    month = months[0];
    year = year+1;
    if(year == 0)
     year = 1;
   }
   else
    month = months[m+1];
  }
 }
 return *this;
}
// End Method 12.



// Method 13.
/* This public function is used to add n number of years to a Date object. */

Date& Date::addYear(const int& n)
{
 int y = n;
 if (y > 0)
 {
  for(y=n; y>0; y--) // Loop for taking the years value that are greater than 0.
  {
   year = year + 1;
   if(year == 0)
    year = 1; // Taking the positive year.
  }
 }
 else if(y < 0)
 {
  for(y=n; y<0; y++)
  {
   year = year - 1;
   if(year == 0)
    year = -1; // Taking the negative year.
  }
 }
 if(day > daysInMonth(getMonth()))
 {
  int mI = monthIndex();
  if(mI+1 > 11)
  {
   month = months[0]; // Checking with the first month.
   day = 1;
   year = year + 1;
   if(year == 0)
    year = 1;
  }
  else
  {
   month = months[mI+1]; // Taking the next month from the months vector.
   day = 1;
  }
 }
 return *this;
}
// End of Method 13.



// Method 14.
/* This is a public function that returns an index value for a Date object, which is simply equal to the number of days
   passed from the reference date of January 1, 1 with the index value 1. This implies that the index values for days
   after this date have positive values and the index values for days before this date have negative values. */

int Date::dayIndex() const
{
 int sign =0, alpha=0, p=0,jkh=0;
 Date d = *this; // Getting the current date object.
 if(d.year>0) // Checking if the current year is greater than 0.
 {
  alpha=1;
  while(alpha< year)
  {
   d.setYear(alpha);
   if(d.isLeapYear()) // Checking the leap year condition.
   {
    sign=sign+366; // Adding 366 days to the current day.
   }
   else if(!(d.isLeapYear()))
   {
    sign= sign + 365; // Else adding 365 to the current day.
   }
   alpha++;
  }
  d.setYear(alpha);
  p = d.monthIndex(); // Storing the current month index in p.
  alpha=0;
  while(alpha<p)
  {
   d.month= months[alpha];
   sign = sign + d.daysInMonth(d.month);
   alpha++;
  }
  sign = sign+(d.day);
 }
 else
 {
  sign = 0;
  while(d.year<0) // Loop for until the year value is less than zero.
  {
   p=d.monthIndex();
   jkh=d.daysInMonth(d.month);
   sign=sign+(jkh-d.day); // Modifying the sign value.
   d.day=0;
   if((p+1)<=11) // Condition for checking if the month index is between the max months range.
    d.month=months[p+1];
    else
    {
     d.month=months[0];
     d.year=d.year+1; // Modifying the current year by taking the next value for year.
     if(d.year==0)
      d.year=1;
    }
  }
  sign =- (sign)-1;
 }
 if((day == 1) && (month == months[0]) && (year==1)) // Condition for 1st day, 1st month and the 1st year.
 {
  return 1;
 }
 return sign; // Returning the dayIndex.
}
// End of Method 14.



// Method 15.
/* This is a private function that returns the index value of a month from the months vector, which is
   between 0 and 11, and the returned index value is used to get the month of a Date object. */

int Date:: monthIndex()
{
 for (unsigned i=0; i<months.size(); i++)
  if(month == months[i]) // Comparing the month with the months in the vector.
   return i; // Returning the index value.
 return 0;
}
// End of Method 15.



// Method 16.
/* This method is used to get the number of days between the Date d1 and Date d2. */

unsigned dateDiff(const Date & d1, const Date & d2)
{
 int diff1=0, diff2=0;
 unsigned res;
 if((d1.getDay() == V1) && (d1.getMonth() == months[0]))
  if ((d1.getYear() == V1) && (d2.getYear() < V2)) // Condition for 1st day, 1st year and 1st month.
   res = d2.dayIndex() - V1;
 if((d2.getDay() == V1) && (d2.getMonth() == months[0]))
  if((d2.getYear() == V1) && (d1.getYear() < V2)) // Condition for 1st day, 1st year and 1st month.
   res = d1.dayIndex() - V1;
 diff1 = d1.dayIndex(); // Storing the 1st dayIndex.
 diff2 = d2.dayIndex(); // Storing the 2nd dayIndex.
 if(diff1 > diff2)
  res = diff1 - diff2; // Storing the difference in res.
 else
  res = diff2 - diff1;
 if(((d1.getYear() > V2) && (d2.getYear() < V2)) || ((d1.getYear() < V2) && (d2.getYear() > V2)))
  res = res-V1;
 return res; // Returning the number of days.
}
// End of Method 16.

// End of Program.
