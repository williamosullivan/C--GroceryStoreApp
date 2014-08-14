#include "FoodItem.h"

FoodItem::FoodItem(std::string foodName)
{
	foodItemName = foodName;
}
FoodItem::FoodItem(int numberOfItems, std::string nameOfFood )
{
	setFoodQuantity( numberOfItems );
	setFoodName( nameOfFood );
}

double FoodItem::getFoodItemTotal()
{
	totalPriceForFoodItem = getFoodQuantity() * foodItemPrice;
	return totalPriceForFoodItem;
}
void FoodItem::setFoodName(std::string itemName)
{
	foodItemName = itemName;
}
std::string FoodItem::getFoodName()
{
	return foodItemName;
}
void FoodItem::setFoodQuantity( int numberOfFoodItem )
{
	quantity = numberOfFoodItem;
}
int FoodItem::getFoodQuantity()
{
	return FoodItem::quantity;
}
int FoodItem::getCalories()
{
	return foodItemCalories;
}
