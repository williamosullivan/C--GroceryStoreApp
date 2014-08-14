// ShoppingCart.h
// ShoppingCart class definition. This file presents ShoppingCart public 
// interface without revealing the implementations of ShoppingCart member
// functions, which are defined in ShoppingCart.cpp.
#include <string> // class ShoppingCart uses C++ standard string class
#include <cstdlib>
#include "FoodItem.h"
#ifndef SHOPPINGCART
#define SHOPPINGCART
using namespace std;
// ShoppingCart definition
class ShoppingCart
{

private:
	FoodItem foodName;
	double totalPrice;

public:
	void addToCart(FoodItem);
	double getTotal();
	double emptyShoppingCart();
	ShoppingCart( FoodItem );
	ShoppingCart(int, std::string);
}; // end class ShoppingCart  
#endif



