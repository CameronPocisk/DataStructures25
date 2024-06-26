#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string> // needed?
using namespace std;

class Item{
    private:
        // Nesscessary data from the lab doc
        string SKU;
        string description;
        double price;
        string unitOfMeasure;
        int quantity;
        int leadTime;

    public:
        // Constructor with optional quntity (everything pretty much)
        Item(string sku = 0, string desc = "", double p = 0, string uom = "", int lt = 0, int q = 0){
            SKU = sku;
            description = desc;
            price = p;
            unitOfMeasure = uom;
            leadTime = lt;
            quantity = q;
        }
        // Filled in Item.cpp
        string GetPartInfo();
        double GetPrice();
        bool InStock();
        bool IsAvailable(int desiredDate);
        void DisplayItem();

        bool operator ==(const Item &right) const{ return SKU == right.SKU;}
        bool operator !=(const Item &right) const{ return SKU != right.SKU;}

        bool operator <(const Item &right) const{ return SKU < right.SKU;}
        bool operator >(const Item &right) const{ return SKU > right.SKU;}

        operator string() const{ return SKU;}
};



#endif