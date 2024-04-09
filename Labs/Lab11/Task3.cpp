#include "HashTable.h"
#include "HashTable.cpp"
#include "Item.h"
#include "Item.cpp"
#include "Exceptions.h"

using namespace std;

// enum for readablitiy
enum{
    AddItem = 1,
    GetItem = 2,
    IsInList = 3,
    IsEmpty = 4,
    Size = 5,
    SeeNext = 6,
    SeePrev = 7,
    SeeAt = 8,
    Reset = 9,
    DisplayList = 10,
    Quit = 11,
};


int main(){
    cout << "Running program" << endl;
    // cout << __cplusplus << endl;

    // Inits :)
    HashTable<Item> instance;
    int userChoice = 0;
    int lt, q = 0;
    double p;
    string sku, desc, uom, qChoice;

    // Valid user choice and act accoringly
    while(userChoice != 11){
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1: AddItem, 2: GetItem, 3:IsInList, 4: IsEmpty, 5: Size, 6: SeeNext, 7: SeePrev, 8: SeeAt, 9: Reset, 10: Display List, 11: Quit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << endl;

        switch (userChoice)
        {
        case AddItem: {
            // Get needed data
            cout << "Enter the SKU: ";
            cin >> sku;
            cout << "Enter the description: ";
            cin.ignore();
            getline(cin, desc);
            cout << "Enter the price: ";
            cin >> p;
            cout << "Enter the unit of measure: ";
            cin.ignore();
            getline(cin, uom);
            cout << "Enter the Lead Time: ";
            cin >> lt;
            cout << "Do you want to add a quantity? (y/n)";
            cin >> qChoice;
            if(qChoice == "y") {
                cout << "Enter the quantity: ";
                cin >> q;
            }
            // Using data from user make an item and add it to DLL
            Item item(sku, desc, p, uom, lt, q);
            instance.Insert(&item);
            cout << endl;
            cout << "---------------------- ITEM ADDED TO LIST ----------------------" << endl;

            break;
        }
        case GetItem: {
            cout << "Enter the sku of the item to remove: ";
            cin >> sku;
            Item item(sku);
            cout << endl;
            try{
                // Remove the item if possible using member funtion
                Item bruh(*(instance.Remove(&item)));
                cout << "---------------------- REMOVING ITEM: " << bruh.GetPartInfo();
            } catch(UnderflowError &e){
                cerr << e.what();
            } catch(NotFound &e){
                cerr << e.what();
            }
            cout << " ----------------------" << endl;

            break;
        }
        case IsInList: {
            // Just need SKU for deletion
            cout << "Enter the sku to search for: ";
            cin >> sku;
            Item item(sku);
            try{
                // Watch out for underflow, otherwise follow DLL implementation
                if(instance.GetItem(&item)){
                    cout << "Sku " << sku << " is in list." << endl;
                } else {
                    cout << "Sku " << sku << " is NOT in list." << endl;
                }
            } catch(UnderflowError &e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case IsEmpty:
            // Member function utilization. Be sure to catch errors
            if(instance.IsEmpty()){
                cout << "The list is currently empty" << endl;
            } else {
                cout << "The list is not empty with " << instance.GetLength() << " element(s)" << endl;
            }
            break;
        case Size:
            cout << "---------------------- List Size: " << instance.GetLength() << " ----------------------" << endl;
            break;
        default:
            break;
        }
    }


    return 0;
}

// g++ -c Task3.cpp HashTable.cpp item.cpp
// g++ -o main.exe Task3.o HashTable.o item.o
// ./main.exe



// For dom, mac is weird fr
// g++ --std=c++17 -c Lab8.cpp
// g++ --std=c++17 -o main.exe Lab8.o
// ./main.exe