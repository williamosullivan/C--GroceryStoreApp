// FoodItem.h
// FoodItem class definition. This file presents FoodItem public 
// interface without revealing the implementations of FoodItem member
// functions, which are defined in FoodItem.cpp.
#include <string> // class Invoice uses C++ standard string class
#ifndef FOODITEM
#define FOODITEM
// FoodItem definition
class FoodItem
{

private:
	int itemNumber;
	std::string foodItemName;
	int quantity;
	int foodItemCalories;
	double totalPriceForFoodItem;

public:
	FoodItem();
	FoodItem(std::string);
	explicit FoodItem(int numberOfItems, std::string foodItemName); // constructor initialize Person
	double foodItemPrice;
	void setFoodQuantity(int);
	void setFoodName(std::string);
	double getFoodItemTotal();
	std::string getFoodName();
	int getFoodQuantity();
	int getCalories();

}; // end class FoodItem  
#endif



