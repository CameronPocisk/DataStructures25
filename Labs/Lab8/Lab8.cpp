#include <iostream>
#include "OrderedDll.h"
#include "OrderedDll.cpp" //For Dom, mac is so strange
#include "Item.h"
#include "Item.cpp"

using namespace std;

int main(){
    cout << "Running program" << endl;
    // cout << __cplusplus << endl;

    OrderedDll<Item> instance;
    int userChoice = 0;
    int sku, p, lt, q = 0;
    string desc, uom, qChoice;

    while(userChoice != 10){
        cout << "Menu:" << endl;
        cout << "1: AddItem, 2: GetItem, 3:IsInList, 4: Size, 5: SeeNext, 6: SeePrev, 7: SeeAt, 8: Reset, 9: Display List, 10: Quit" << endl;
        cin >> userChoice;
        cout << endl;

        switch (userChoice)
        {
        case 1: {
            cout << "Enter the SKU: ";
            cin >> sku;
            cout << "Enter the description: ";
            cin.ignore();
            getline(cin, desc);
            cout << "Enter the price: ";
            cin >> p;
            cout << "Enter the unit of measure: ";
            cin >> uom;
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

            break;
        }
        case 2: {
            cout << "Enter the sku of the item to remove: ";
            cin >> sku;
            Item item(sku);
            try{
                instance.GetItem(&item);
            } catch(UnderflowError &e){
                cerr << e.what() << endl;
            } catch(NotFound &e){
                cerr << e.what() << endl;
            }

            break;
        }
        case 3: {
            cout << "Enter the sku to search for: ";
            cin >> sku;
            Item item(sku);
            try{
                if(instance.IsInList(&item)){
                    cout << "Sku: " << sku << " is in list." << endl;
                } else {
                    cout << "Sku: " << sku << " is NOT in list." << endl;
                }
            } catch(UnderflowError &e) {
                cerr << e.what() << endl;
            }
            break;
;        }
        case 4:
            cout << ">>>>>>>>> List Size: " << instance.Size() << " <<<<<<<<<<<<" << endl;
            break;
        case 5:
            try{
                instance.SeeNext().DisplayItem();
            } catch(UnderflowError &e) {
                cerr << e.what() << endl;
            }catch(NotFound  &e){
                cerr << e.what() << endl;
            };
            break;
        case 6:
            try{
                instance.SeePrev().DisplayItem();
            } catch(UnderflowError &e) {
                cerr << e.what() << endl;
            }catch(NotFound  &e){
                cerr << e.what() << endl;
            };
            break;
        case 7:
            cout << "Enter the place get the item from: ";
            cin >> sku;
            try{
                instance.SeeAt(sku).DisplayItem();
            } catch(UnderflowError &e) {
                cerr << e.what() << endl;
            }catch(NotFound  &e){
                cerr << e.what() << endl;
            };
            break;
        case  8:
            cout << "Resetting see place to first position" << endl;
            instance.Reset();
            break;
        case 9:
            instance.PrintItems();
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