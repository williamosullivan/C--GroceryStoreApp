#include <iostream>
#include "Person.h" // Person class definition
using namespace std;

Person::Person( const string &first, const string &last )
   : firstName( first ), lastName( last )
{
} // end Person constructor

void Person::setFirstName( const string &first ) 
{ 
	firstName = first;
} // end function setFirstName

// return first name
string Person::getFirstName() const 
{ 
   return firstName;  
} // end function getFirstName

// set last name
void Person::setLastName( const string &last )
{
   lastName = last;   
} // end function setLastName

// return last name
string Person::getLastName() const
{
   return lastName;   
} // end function getLastName


void Person::print() const
{ 
	cout << getFirstName() << ' ' << getLastName();
} // end function print

