#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Customer.h"
#include "Inventory.h"
#include "FoodItem.h"
#include "ShoppingCart.h"
#include "Person.h"
#include <string>
#include <string.h>

using namespace std;


int enterAccount();
void createTextFile();
void updateAccount();
int accountNumber;
string shopper;
double money;
string customerNames[10];
int customerAccounts[10];
double customerBalances[10];
fstream customerName;
fstream accountNum;
fstream currentBalance;
void adminMenu();
int enterMenuChoice();
void loadInventory();
void createOutputFile();
void updateRecord();
void newRecord();
void deleteRecord();
void processFoodRequests();
void outputLine( ostream&, const Inventory & );
int getFoodNumber( const char * const );
int findAddNumber();
fstream inOutInventory;
int enterOption();
void shop();
int addFood();
string foodToAdd;
string foodName;
int quantity;
int price;
double cartTotal;void checkout();
double total;
ShoppingCart cart( quantity, foodName );
Inventory inv( foodName, quantity, price );
FoodItem item( foodName );
int foodNumber;
void endProgram();
double emptyShoppingCart();
enum Choices { REQUESTS = 1, UPDATE, PRINT, ADMIN, SHOP };

int main()
{
	cout << "Welcome to Shop Mart!" << endl << "Please follow instructions "
		<< "to begin your shopping experience!";
	Customer cust;

	customerName.open( "customers.dat", ios::in | ios::out | ios::binary );
	if( !customerName )
	{
		customerName.close();
		ofstream newFile("customers.dat", ios::out);
		newFile.seekp( 0 );
		for (int i=0; i<20; i++)
		{
		   newFile.write( reinterpret_cast< const char * >( &cust ),
             sizeof( Customer ) );
		}
		newFile.close();
		customerName.open( "customers.dat", ios::in | ios::out | ios::binary );
		while (customerName > 0)
			customerName << customerNames[10];
	}
	accountNum.open( "accounts.dat", ios::in | ios::out | ios::binary );
	if( !accountNum )
	{
		accountNum.close();
		ofstream newFile("accounts.dat", ios::out);
		newFile.seekp( 0 );
		for (int i=0; i<20; i++)
		{
		   newFile.write( reinterpret_cast< const char * >( &cust ),
             sizeof( Customer ) );
		}
		newFile.close();
		accountNum.open( "accounts.dat", ios::in | ios::out | ios::binary );
		while (accountNum > 0)
			accountNum << customerAccounts[10];
	}
	currentBalance.open( "balances.dat", ios::in | ios::out | ios::binary );
	if( !currentBalance )
	{
		currentBalance.close();
		ofstream newFile("balances.dat", ios::out);
		newFile.seekp( 0 );
		for (int i=0; i<20; i++)
		{
		   newFile.write( reinterpret_cast< const char * >( &cust ),
             sizeof( Customer ) );
		}
		newFile.close();
		currentBalance.open( "balances.dat", ios::in | ios::out | ios::binary );
		while (currentBalance > 0)
			currentBalance << customerBalances[10];
	}
}

int enterAccount()
{
	cout << "Please enter Account Number:";
	cin >> accountNumber;
	int searchList( int customerAccounts[], int size, int accountNum);
	{
		int index = 0;
		int position = -1;
		bool found = false;
		int size = sizeof(customerAccounts[10]);

		while (index < size && !found)
		{
			if (customerAccounts[index] = accountNumber)
			{
				found = true;
				position = index;
			}
			index++;
		}
		accountNumber = customerAccounts[position];
		shopper = customerNames[position];
		money = customerBalances[position];
		Customer cust(shopper, accountNumber, money);
	}
	int choice;
	cout << "\nEnter your choice" << endl
		<< "1 - Update a customer account" << endl
		<< "2 - Print customer report" << endl
		<< "3 - Admin Menu" << endl
		<< "4 - Begin shopping?\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;

	while ( choice != SHOP ) 
	{
      switch ( choice ) 
      {
         case UPDATE:
            updateAccount();
            break;
         case PRINT:
            createTextFile();
            break;
		 case ADMIN:
			 adminMenu();
         default:
            cerr << "Incorrect choice" << endl;
      }
	shop();
	}
}

void createTextFile()
{
   ofstream outPrintFile( "print.txt", ios::out );
   if ( !outPrintFile ) 
   {
      cerr << "File could not be created." << endl;
      exit( EXIT_FAILURE );
   }
   outPrintFile << setw( 100 )
      << "Customer Name: " << shopper << "Account Number: " << accountNumber
      << "Balance: $" << money << "0" << endl;
	outPrintFile.close();
}

void updateAccount()
{
   if (accountNumber >= 0)
   {
       cout << "\nEnter dollar amount you wish to add to account: ";
       double addDollars;
       cin >> addDollars;
		
	    int searchList( int customerAccounts[], int size, int accountNum);
		{
			int index = 0;
			int position = -1;
			bool found = false;
			int size = sizeof(customerAccounts[10]);

			while (index < size && !found)
			{
				if (customerAccounts[index] = accountNumber)
				{
					found = true;
					position = index;
					customerBalances[index] += addDollars;
					currentBalance.open( "balances.dat", ios::in | ios::out | ios::binary );
					while (currentBalance > 0)
						currentBalance << customerBalances[10];
				}
			index++;
			}
		}
   }
   else
	   cout << "Selected account not found" << endl;
}

void adminMenu()
{
	enum menuChoices { REQUESTS = 1, UPDATE, NEW, DELETE, PRINT, END };

	inOutInventory.open( "inventory.dat", ios::in | ios::out | ios::binary );
   if ( !inOutInventory ) 
   {
	  inOutInventory.close();
	  ofstream newFile("inventory.dat", ios::out);
	  Inventory inv;
      newFile.seekp( 0 );
	  for (int i=0; i<20; i++)
	  {
           newFile.write( reinterpret_cast< const char * >( &inv ),
              sizeof( Inventory ) );
	  }
	  newFile.close();
	  inOutInventory.open( "inventory.dat", ios::in | ios::out | ios::binary );
   }

   int choice;
   while ( ( choice = enterMenuChoice() ) != END ) 
   {
      switch ( choice ) 
      {
         case UPDATE:
            updateRecord();
            break;
         case NEW:
            newRecord();
            break;
         case DELETE:
            deleteRecord();
            break;
         case PRINT:
            createOutputFile();
            break;
         default:
            cerr << "Incorrect choice" << endl;
            break;
      }
   }
}

int enterMenuChoice()
{
   cout << "\nEnter your choice" << endl
      << "1 - Update an inventory item" << endl
      << "2 - Add a new inventory item" << endl
      << "3 - Delete an inventory item" << endl	
	  << "4 - Print inventory report" << endl
      << "5 - End program\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;
}

void createOutputFile()
{
   ofstream outPrintFile( "print.txt", ios::out );
   if ( !outPrintFile ) 
   {
      cerr << "File could not be created." << endl;
      exit( EXIT_FAILURE );
   }
   outPrintFile << setw( 16 )
      << "Food Name" << setw( 11 ) << "Quantity" << right
      << setw( 10 ) << "Price" << endl;
   inOutInventory.seekg( 0 );
   Inventory inv;
   inOutInventory.read( reinterpret_cast< char * >( &inv ),
                      sizeof( Inventory ) );
   while ( !inOutInventory.eof() ) 
   {
	   if ( inv.getFoodName().compare("?") !=0 )
            outputLine( outPrintFile, inv );
      inOutInventory.read( reinterpret_cast< char * >( &inv ), 
            sizeof( Inventory ) );
   }
}

void outputLine( ostream &output, const Inventory &record )
{
	output << setw( 16 ) << record.getFoodName()
		<< setw( 11 ) << record.getQuantity()
		<< right << setw( 10 ) << record.getPrice() << endl;
}

void updateRecord()
{
   int foodNumber = getFoodNumber( "Enter food name to update" );
   if (foodNumber >= 0)
   {
       cout << "\nEnter quantity to add and new price: ";
       int quantity;
       double price;
       cin >> quantity >> price;

	   Inventory inv;
       inOutInventory.seekg(foodNumber * sizeof( Inventory ));
       inOutInventory.read( reinterpret_cast< char * >( &inv ), 
                             sizeof( Inventory ) );
       inv.setQuantity( inv.getQuantity() + quantity );
       inv.setPrice( price ); 
       inOutInventory.seekp(foodNumber * sizeof( Inventory ));
       inOutInventory.write( reinterpret_cast< const char * >( &inv ), 
                             sizeof( Inventory ) );
   }
   else
	   cout << "Selected food not found in the inventory" << endl;
}

void newRecord()
{
      string foodName;
	  int quantity;
	  double price;
      cout << "Enter new food name, quantity and price\n";
      cin >> foodName >> quantity >> price;
	  int foodNumber = findAddNumber();

	  Inventory inv;
      inv.setFoodName( foodName );
      inv.setQuantity( quantity );
      inv.setPrice( price );

      inOutInventory.seekp((foodNumber) * sizeof( Inventory ));                      
      inOutInventory.write( reinterpret_cast< const char * >( &inv ),
         sizeof( Inventory ) );                     
}

void deleteRecord( )
{
	  int foodNumber = getFoodNumber( "Enter food name to delete" );
      if (foodNumber >= 0)
      {

	      Inventory inv;
          inv.setFoodName( "?" );
          inv.setQuantity( 0 );
          inv.setPrice( 0.0 );

          inOutInventory.seekp((foodNumber) * sizeof( Inventory ));                      
          inOutInventory.write( reinterpret_cast< const char * >( &inv ),
             sizeof( Inventory ) );                     
	  }
	  else
		  cout << "Selected food not found in the inventory" << endl;
}

int getFoodNumber( const char * const prompt )
{
   string foodName;
   cout << prompt << ":";
   cin >> foodName;

   Inventory inv;
   int foodNumber=0;
   inOutInventory.seekg(0);
   while ( !inOutInventory.eof() ) 
   {
	   inOutInventory.read( reinterpret_cast< char * >( &inv ), 
         sizeof( Inventory ) );
	   if (inv.getFoodName().compare(foodName) == 0) return foodNumber;
	   foodNumber++;
   }

   return -1;
}

int findAddNumber( )
{
   Inventory inv;
   foodNumber=0;
   inOutInventory.seekg(0);
   while ( !inOutInventory.eof() ) 
   {
	   inOutInventory.read( reinterpret_cast< char * >( &inv ), 
         sizeof( Inventory ) );
	   if (inv.getFoodName().compare("?") == 0) return foodNumber;
	   foodNumber++;
   }

   return -1;
}

void shop()
{
	cout << "Enjoy your shopping experience!";

	enum options { REQUESTS = 1, ADD, EMPTY, PRINT, CHECKOUT, END };
	int option = enterOption();
	while ( option != END ) 
	{
      switch ( option ) 
      {
         case ADD:
            addFood();
			shop();
            break;
         case EMPTY:
            emptyShoppingCart();
			shop();
            break;
         case PRINT:
            createOutputFile();
			shop();
            break;
         case CHECKOUT:
            checkout();
            break;
		 case END:
			 endProgram();
			 break;
         default:
            cerr << "Incorrect choice" << endl;
			shop();
            break;
      }
   }
}

int enterOption()
{
   cout << "\nEnter your choice" << endl
      << "1 - Add item to cart" << endl
      << "2 - Empty cart" << endl
      << "3 - Print items in cart" << endl	
	  << "4 - Checkout" << endl
      << "5 - End program\n? ";

   int menuOption;
   cin >> menuOption;
   return menuOption;
}

int addFood()
{
	cout << "Please enter the food item which you wish to purchase:";
	cin >> foodToAdd;
	foodNumber=0;
	inOutInventory.seekg(0);
	while ( !inOutInventory.eof() ) 
	{
	   inOutInventory.read( reinterpret_cast< char * >( &inv ), 
         sizeof( Inventory ) );
	   if (inv.getFoodName().compare(foodToAdd) == 0) return foodNumber;
	   foodNumber++;
	}
	inOutInventory.seekg(foodNumber);
	char buff[30];
	inOutInventory.getline(buff, sizeof(buff));
	inOutInventory << foodName;
	cout <<  "Enter quantity desired: ";
	cin >> quantity;
	FoodItem item( quantity, foodName );
	inOutInventory.seekg(foodNumber);
	foodNumber++;
	price = foodNumber;
	ShoppingCart cart(quantity, foodName);
	cartTotal += foodNumber;
	inv.reduceQuantity(quantity);

	return cartTotal;
	enterOption();
}

void checkout()
{
	cout << "Your total today comes to: $" <<
		cartTotal << "0 dollars" << endl;
	cout << "The amount will be debited from " <<
		"your store account." << endl;
	int searchList( int customerAccounts[], int size, int accountNum);
		{
			int index = 0;
			int position = -1;
			bool found = false;
			int size = sizeof(customerAccounts[10]);

			while (index < size && !found)
			{
				if (customerAccounts[index] = accountNumber)
				{
					found = true;
					position = index;
					customerBalances[index] -= total;
					currentBalance.open( "balances.dat", ios::in | ios::out | ios::binary );
					while (currentBalance > 0)
						currentBalance >> customerBalances[10];
				}
			index++;
			}
		}
	inv.setQuantity( inv.getQuantity() + quantity );
	foodNumber = getFoodNumber("");
	inOutInventory.seekp(foodNumber * sizeof( Inventory ));
    inOutInventory.write( reinterpret_cast< const char * >( &inv ), 
						sizeof( Inventory ) );
	cout << "Thank you for shopping with Shop Mart!";
	endProgram();
}

void endProgram()
{
	exit(0);
}
