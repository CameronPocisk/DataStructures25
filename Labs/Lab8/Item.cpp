#include "Item.h"

string Item::GetPartInfo(){
    return "SKU: " + to_string(SKU) + ", Description: " + description;
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
    } else if(desiredDate < leadTime){ //Not sure???
        return true;
    }
    return false;
}

void Item::DisplayItem(){
    cout << "-----------------" << endl;
    cout << "|  Sku: " << SKU << endl;
    cout << "|  Description: " << description << endl;
    cout << "|  Price: " << price << endl;
    cout << "|  Quantity: " << quantity << endl;
    cout << "-----------------" << endl;
}

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
