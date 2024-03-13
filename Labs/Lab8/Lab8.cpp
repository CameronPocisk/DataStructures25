#include <iostream>
#include "OrderedDll.h"
#include "OrderedDll.cpp" //For Dom, mac is so strange
#include "Item.h"
#include "Item.cpp"

using namespace std;

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

    OrderedDll<Item> instance;
    int userChoice = 0;
    int sku, lt, q = 0;
    double p;
    string desc, uom, qChoice;

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
            Item item(sku, desc, p, uom, lt, q);
            instance.AddItem(&item);
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
                cout << "---------------------- REMOVING ITEM: " << instance.GetItem(&item).GetPartInfo();
            } catch(UnderflowError &e){
                cerr << e.what();
            } catch(NotFound &e){
                cerr << e.what();
            }
            cout << " ----------------------" << endl;

            break;
        }
        case IsInList: {
            cout << "Enter the sku to search for: ";
            cin >> sku;
            Item item(sku);
            try{
                if(instance.IsInList(&item)){
                    cout << "Sku " << sku << " is in list." << endl;
                } else {
                    cout << "Sku " << sku << " is NOT in list." << endl;
                }
            } catch(UnderflowError &e) {
                cerr << e.what() << endl;
            }
            break;
;        }
        case IsEmpty:
            if(instance.IsEmpty()){
                cout << "The list is currently empty" << endl;
            } else {
                cout << "The list is not empty with " << instance.Size() << " element(s)" << endl;
            }
            break;
        case Size:
            cout << "---------------------- List Size: " << instance.Size() << " ----------------------" << endl;
            break;
        case SeeNext:
            try{
                cout << "---------------------- Next Item: " << instance.SeeNext().GetPartInfo();
            } catch(UnderflowError &e) {
                cerr << e.what();
            }catch(NotFound  &e){
                cerr << e.what();
            };
            cout << "----------------------" << endl;
            break;
        case SeePrev:
            try{
                cout << "---------------------- Prev Item: " << instance.SeePrev().GetPartInfo();
            } catch(UnderflowError &e) {
                cerr << e.what();
            }catch(NotFound  &e){
                cerr << e.what();
            };
            cout << "----------------------" << endl;
            break;
        case SeeAt:
            cout << "Enter the place get the item from: ";
            cin >> sku;
            cout << endl;
            try{
                cout << "---------------------- Item at " << sku << ": " << instance.SeeAt(sku).GetPartInfo();
            } catch(UnderflowError &e) {
                cerr << e.what();
            }catch(NotFound  &e){
                cerr << e.what();
            };
            cout << "----------------------" << endl;
            break;
        case  Reset:
            cout << "Resetting see place to first position" << endl;
            instance.Reset();
            break;
        case DisplayList:
            try{
                instance.PrintItems();
            } catch(UnderflowError &e){
                cerr << e.what() << endl;
            }
            break;
        default:
            break;
        }
    }


    return 0;
}

// g++ -c Lab8.cpp OrderedDll.cpp
// g++ -o main.exe Lab8.o OrderedDll.o
// ./main.exe


// For dom, mac is weird fr
// g++ --std=c++17 -c Lab8.cpp
// g++ --std=c++17 -o main.exe Lab8.o
// ./main.exe