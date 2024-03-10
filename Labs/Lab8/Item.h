#ifndef ITEM_H
#define ITEM_H
#include "OrderedDll.h"

class Item{
    private:
        int SKU;
        string description;
        double price;
        string unitOfMeasure;
        int quantity;
        int leadTime;

    public:
        Item(int sku, string desc, double p, string uom, int lt, int q = 0){
            SKU = sku;
            description = desc;
            unitOfMeasure = uom;
            leadTime = lt;
            quantity = q;
        }

        

};



#endif