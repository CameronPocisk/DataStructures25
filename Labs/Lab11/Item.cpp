#include "Item.h"

string Item::GetPartInfo(){
    return "SKU: " + SKU + ", Description: " + description;
}

double Item::GetPrice(){
    return price;
}

bool Item::InStock(){
    return quantity > 0;
}

bool Item::IsAvailable(int desiredDate){
    if(quantity > 0){
        return true;
        // If it arrives before they want it it is counted as avaliable
    } else if(desiredDate > leadTime){
        return true;
    }
    return false;
}

void Item::DisplayItem(){
    //mmmmmmmhmm
    cout << "-----------------" << endl;
    cout << "|  Sku: " << SKU << endl;
    cout << "|  Description: " << description << endl;
    cout << "|  Price: " << price << endl;
    cout << "|  Quantity: " << quantity << endl;
    cout << "-----------------" << endl;
}


// Operator overloading for DLL work
bool Item::operator ==(const Item &right) const{
    return SKU == right.SKU;
}

bool Item::operator <(const Item &right) const{
    return SKU < right.SKU;
}

bool Item::operator >(const Item &right) const{
    return SKU > right.SKU;
}

bool Item::operator !=(const Item &right) const{
    return SKU != right.SKU;
}