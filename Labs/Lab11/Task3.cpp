#include "Item.h"
// #include "Item.cpp"
#include "HashTable.h"
#include "HashTable.cpp"
#include "Exceptions.h"

using namespace std;

// enum for readablitiy
enum{
    AddItem = 1,
    GetItem = 2,
    IsInList = 3,
    IsEmpty = 4,
    Size = 5,
    DisplayList = 6,
    Quit = 7,
};


int main(){
    cout << "Running program" << endl;
    // cout << __cplusplus << endl;

    // Inits :)
    HashTable<Item> instance(100);
    int userChoice = 0;
    int lt, q = 0;
    double p;
    string sku, desc, uom, qChoice;

    // Item Test("zesty");
    // instance.Insert(&Test);


    // Valid user choice and act accoringly
    while(userChoice != Quit){
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1: AddItem, 2: GetItem, 3:IsInList, 4: IsEmpty, 5: Size, 6: Display List, 7: Quit" << endl;
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
            cout << "SKU INSERTED: " << sku << endl;
            cout << "---------------------- ITEM ADDED TO LIST ----------------------" << endl;
            item.DisplayItem();

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
                bruh.DisplayItem();
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
                instance.GetItem(&item);
                cout << "Sku " << sku << " is in list." << endl;
            } catch(NotFound &e){
                // cerr << e.what() << endl;
                cout << "Sku " << sku << " not found." << endl;
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
        case DisplayList:
            cout << "---------------------- Displaying SKUs ----------------------" << endl;
            instance.printInTable();
            cout << "------------------------- Displayed -------------------------" << endl;
            break;
        case Quit:
            cout << "BYE BYE" << endl;
            break;
        }
        
    }


    return 0;
}

// g++ -c Task3.cpp HashTable.cpp Item.cpp
// g++ -o main.exe Task3.o HashTable.o Item.o 
// ./main.exe



// For dom, mac is weird fr
// g++ --std=c++17 -c Lab8.cpp
// g++ --std=c++17 -o main.exe Lab8.o
// ./main.exe