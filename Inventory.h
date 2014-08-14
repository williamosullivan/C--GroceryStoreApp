#ifndef INVENTORY_H
#define INVENTORY_H
using namespace std;

#include <string>
#include <cstdlib>
using namespace std;
class Inventory
{
public:
   Inventory( const std::string & = "?", 
      int = 0, double = 0.0 );

   void setFoodName( const std::string & );
   string getFoodName() const;

   void setQuantity( int );
   int getQuantity() const;

   void setPrice( double );
   double getPrice() const;
   void reduceQuantity( int );
private:
   int foodCode;
   char foodName[ 15 ];
   int quantity;
   double price;
};

#endif
