#include "Tree.h"

#include <iostream>
using namespace std;

template <typename T>
Node<T>* Tree<T>::Find(T *value){
    return findHelper(root, value);
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
    // Node<T>* temp
    
    
    return nullptr;
}

template <typename T>
void Tree<T>::PrintStructuredHelper(Node<T>* curNode){
    // NOT COMPLETE EDGE CASE MISSING (From Class)
    if (curNode == nullptr) { return; }

    // Print root and children data
    cout << *curNode->data << '(';

    // Put left info in paren if it exists
    if(curNode->left != nullptr){
        cout << *curNode->left->data << " ,";
    }
    else{
        cout << "_ , ";
    }

    if(curNode->right != nullptr){
        cout << *curNode->right->data << ')' << endl;
    }
    else{
        cout << "_)" << endl;
    }

    PrintStructuredHelper(curNode->left); // Do same with Left
    PrintStructuredHelper(curNode->right); // Then same w/ right
    
}
template <typename T>
void Tree<T>::PrintStructured(){ 
    PrintStructuredHelper(root);
}

template <typename T>
void Tree<T>::PrintOrderedHelper(Node<T>* curNode){

    if (curNode == nullptr){
        return; // cannot porint nothing so..
    }

    PrintOrderedHelper(curNode->left); // Print left side first 

    cout << *(curNode->data);

    PrintOrderedHelper(curNode->right); // Print right side after cur (bc its larger)
}
template <typename T>
void Tree<T>::PrintOrdered(){ 
    PrintOrderedHelper(root); 
}