#include <string>
#include "Inventory.h"
#pragma warning(disable:4996)
using namespace std;

Inventory::Inventory( const string &foodName, 
   int quantity, double price )
   : quantity( quantity ), price( price )
{
   setFoodName( foodName );
}
string Inventory::getFoodName() const
{
   return foodName;
}
void Inventory::setFoodName( const string &foodNameString )
{
   int length = foodNameString.size();
   length = ( length < 15 ? length : 14 );
   foodNameString.copy( foodName, length );
   foodName[ length ] = '\0';
}
int Inventory::getQuantity() const
{
   return quantity;
}
void Inventory::setQuantity( int quantityValue )
{
   quantity = quantityValue;
}
double Inventory::getPrice() const
{
   return price;
}
void Inventory::setPrice( double priceValue )
{
   price = priceValue;
}

void Inventory::reduceQuantity( int quantity )
{
	quantity -= quantity;
}