#include "HashLinear.h"
#include "HashTwoDim.h"
#include "Tree.h"

using namespace std;


int main(){
    srand(time(0));
    //Seed
    int arr[100];
    int size = 0;
    while(size < 100){
        bool alreadyFound = false;
        int randomNum = rand() % 9999 + 1;
        
        for(int i = 0; i < size; i ++){
            if(arr[i] == randomNum) {
                alreadyFound = true;
                break;
            }
        }

        if(!alreadyFound){
            arr[size] = randomNum;
            size++;
        }
        
    }
    HashLinear linearHash;
    HashTwoDim twoDimHash;
    Tree<int> tree;

    int twoDimSum = 0;
    int linearSum = 0;

    for(int i = 0; i < 50; i++){
        linearSum += linearHash.Insert(arr[i]);
        tree.Insert(&arr[i]);

        try{
            twoDimSum += twoDimHash.Insert(arr[i]);
        } catch (OverflowError &e) {
            cerr << e.what() << endl;
        }
    }

    for(int i = 0; i < 50; i++){
        if(i % 7 == 0){
            linearSum += linearHash.Remove(arr[i]);
            tree.Remove(&arr[i]);

            try{
                twoDimSum += twoDimHash.Remove(arr[i]);
            }
            catch(NotFound &e){
                cerr << e.what() << endl;
            }
        }
    }

    for(int i = 50; i < 100; i++){
        linearSum += linearHash.Insert(arr[i]);
        tree.Insert(&arr[i]);

        try{
            twoDimSum += twoDimHash.Insert(arr[i]);
        } catch (OverflowError &e) {
            cerr << e.what() << endl;
        }
    }

    for(int i = 50; i < 100; i++){
        if(i % 9 == 0){
            linearSum += linearHash.Remove(arr[i]);
            tree.Remove(&arr[i]);
            try{
                twoDimSum += twoDimHash.Remove(arr[i]);
            }
            catch(NotFound &e){
                cerr << e.what() << endl;
            }
        }
    }

    int treeSum = tree.GetSpotsChecked();


    cout << "Linear Spots Checked:" << linearSum << endl;
    cout << "TwoDim Spots Checked: " << twoDimSum << endl;
    cout << "Binary Tree Spots Checked: " << treeSum << endl;



    return 0;
}

// g++ -c Homework4.cpp HashLinear.cpp HashTwoDim.cpp
// g++ -o main.exe Homework4.o HashLinear.o HashTwoDim.o
// ./main.exe