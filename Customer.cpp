#include <string>
#include "Customer.h"
#pragma warning(disable:4996)
using namespace std;


string customerName;
int account;
double balance;
Customer::Customer( const string &customerName, 
   int account, double balance )
   : account( account ), balance( balance )

{
   setCustomerName( customerName );
   setAccountNumber( account );
   setBalance( balance );
}
string Customer::getCustomerName() const
{
   return customerName;
}
void Customer::setCustomerName( const string &customerNameString )
{
   int length = customerNameString.size();
   length = ( length < 20 ? length : 19 );
   string str = customerNameString;
   char *cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
   customerNameString.copy( cstr, length );
   customerName[ length ] = '\0';
   customerName = customerNameString;
}
int Customer::getAccountNumber() const
{
   return account;
}
void Customer::setAccountNumber( int accountNumber )
{
   account = accountNumber;
}
double Customer::getBalance() const
{
   return balance;
}
void Customer::setBalance( double balanceValue )
{
   balance = balanceValue;
}
