#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item{
    private:
        // Nesscessary data from the lab doc
        int SKU;
        string description;
        double price;
        string unitOfMeasure;
        int quantity;
        int leadTime;

    public:
        // Constructor with optional quntity (everything pretty much)
        Item(int sku = 0, string desc = "", double p = 0, string uom = "", int lt = 0, int q = 0){
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

        bool operator ==(const Item &right) const;
        bool operator <(const Item &right) const;
        bool operator >(const Item &right) const;
        bool operator !=(const Item &right) const;

};



#endif