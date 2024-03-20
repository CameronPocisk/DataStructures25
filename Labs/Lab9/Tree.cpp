#include "Tree.h"

#include <iostream>
using namespace std;

template <typename T>
Node<T>* Tree<T>::Find(Node<T>* current, T value){
    
    return nullptr;
} 

template <typename T>
int Tree<T>::Size(){
//Get's the number of elements curNode the tree
    return 0;
}

template <typename T>
int*Tree<T>:: GetAllAscending(){
// Returns an array of each node from smallest to largest // Theese are going to look the the print fn done curNode class
    return nullptr;
}

template <typename T>
int*Tree<T>:: GetAllDecending(){ // Returns an array of each node form largest to smallest // Theese are going to look the the print fn done curNode class
    return nullptr;
}

template <typename T>
void Tree<T>::EmptyTree(){ //Removes and deletes all nodes (No memory leaks pls)

}

template <typename T>
Node<T>* Tree<T>::Remove(T value){ // Removes the value then rebalances the tree
    return nullptr;
}

template <typename T>
void Tree<T>::PrintStructured(){
    // NOT COMPLETE EDGE CASE MISSING (From Class)
    
}

template <typename T>
void Tree<T>::PrintOrderedHelper(Node<T>* curNode){

    if (curNode == nullptr){
        return; // cannot porint nthing so..
    }

    PrintOrderedHelper(curNode->left); // Print left side first 

    cout << *(curNode->data);

    PrintOrderedHelper(curNode->right); // Print right side after cur (bc its larger)
}
template <typename T>
void Tree<T>::PrintOrdered(){ 
    PrintOrderedHelper(root); 
}