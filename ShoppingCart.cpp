#include <iostream>
#include <cstdlib>
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart(int numItems, std::string itemsName ):
	foodName(numItems, itemsName){}
bool cartEmpty = true;	
double thisTotal;
string name;
double emptyShoppingCart()
{
	cartEmpty = true;
	thisTotal = 0;
	return thisTotal;
}

void addToCart(FoodItem fItem )
{
	cartEmpty = false;
	name = fItem.getFoodName();
	FoodItem item(name);
	thisTotal += item.getFoodItemTotal();
	int tempQTY = item.getFoodQuantity();
	tempQTY--;
}

double getTotal()
{
	if (cartEmpty = true)
		thisTotal = 0;
	return thisTotal;
}