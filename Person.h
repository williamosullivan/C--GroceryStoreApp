// Fig. 12.9: Person.h
// Person abstract base class.
#ifndef Person_H
#define Person_H

#include <string> // C++ standard string class
#include <cstdlib>
using namespace std;

class Person 
{
private:
	string firstName;
	string lastName;

public:
   Person( const string &, const string & );
   virtual ~Person() { } // virtual destructor

   void setFirstName( const string & ); // set first name
   string getFirstName() const; // return first name

   void setLastName( const string & ); // set last name
   string getLastName() const; // return last name

   virtual void print() const; // virtual

}; // end class Person

#endif // Person_H

