#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
public:
   Customer( const string & = "?", 
      int = 0, double = 0.0 );

   int account;
   string name;
   double balance;
   Customer cust(string &, int &, double &);
   void setCustomerName( const std::string & );
   string getCustomerName() const;

   void setAccountNumber( int );
   int getAccountNumber() const;

   void setBalance( double );
   double getBalance() const;
private:
   char custName[ 20 ];
};

#endif