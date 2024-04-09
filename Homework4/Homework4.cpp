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
                cout << "already found";
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
        twoDimSum += twoDimHash.Insert(arr[i]);
        tree.Insert(&arr[i]);
    }

    for(int i = 0; i < 50; i++){
        if(i % 7 == 0){
            linearSum += linearHash.Remove(arr[i]);
            twoDimSum += twoDimHash.Remove(arr[i]);
            tree.Remove(&arr[i]);
        }
    }

    for(int i = 50; i < 100; i++){
        linearSum += linearHash.Insert(arr[i]);
        twoDimSum += twoDimHash.Insert(arr[i]);
        tree.Insert(&arr[i]);
    }

    for(int i = 50; i < 100; i++){
        if(i % 9 == 0){
            linearSum += linearHash.Remove(arr[i]);
            twoDimSum += twoDimHash.Remove(arr[i]);
            tree.Remove(&arr[i]);
        }
    }

    linearHash.PrintTable();
    twoDimHash.PrintTable();
    tree.PrintStructured();


    int treeSum = tree.GetSpotsChecked();


    cout << "Linear:" << linearSum << endl;
    cout << "TwoDim: " << twoDimSum << endl;
    cout << "Tree: " << treeSum << endl;




    return 0;
}

// g++ -c Homework4.cpp HashLinear.cpp HashTwoDim.cpp Tree.cpp
// g++ -o main.exe Homework4.o HashLinear.o HashTwoDim.o Tree.o
// ./main.exe