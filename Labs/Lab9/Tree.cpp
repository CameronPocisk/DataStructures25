#include "Tree.h"

#include <iostream>
using namespace std;

template <typename T>
Node<T>* Tree<T>::Find(T *value){
    return findHelper(root, value);
} 

template <typename T>
int Tree<T>::Size(){
    return sizeHelper(root);

}

template <typename T>
void Tree<T>:: GetAllAscendingHelper(Node<T>* current, vector<Node<T>*> &result){
    
    if (current != nullptr){
        GetAllAscendingHelper(current->left, result); 
        // result.push_back(current->data);
        result.push_back(current);
        GetAllAscendingHelper(current->right, result);
    }
}

template <typename T>
vector<Node<T>*>  Tree<T>:: GetAllAscending(){ // Returns an array of each node form largest to smallest // Theese are going to look the the print fn done curNode class
    vector<Node<T>*> result;
    GetAllAscendingHelper(root, result);
    return result;
}

template <typename T>
void Tree<T>:: GetAllDecendingHelper(Node<T>* current, vector<Node<T>*> &result){
    
    if (current != nullptr){
        GetAllDecendingHelper(current->right, result);
        // result.push_back(current->data);
        result.push_back(current);
        GetAllDecendingHelper(current->left, result); 
    }
}

template <typename T>
vector<Node<T>*>  Tree<T>:: GetAllDecending(){ // Returns an array of each node form largest to smallest
    vector<Node<T>*> result;
    GetAllDecendingHelper(root, result);
    return result;
}

template <typename T>
Node<T>* Tree<T>::Remove(T value){ // Removes the value then rebalances the tree
    if(find(root, value) == nullptr){
        throw NotFound();
    }

    Node<T>* parent = removeHelper(root, value);
    if(value < parent->data){ //Remove one on left
        if(parent->left->left == nullptr && parent->left->right == nullptr){ // no children
            Node<T>* remNode = parent->left;
            parent->left = nullptr;
            return remNode;
        }
        else if(parent->left->left == nullptr || parent->left->right == nullptr){ // one child
            Node<T>* remNode = parent->left;
            if(parent->left->left == nullptr){
                parent->left = parent->left->right;
                remNode->right = nullptr;
                return remNode;
            }
            else{
                parent->left = parent->left->left;
                remNode->left = nullptr;
                return remNode;
            }
        }
        else{ // two children
            Node<T>* remNode = parent->left;
            Node<T>* replace = parent->left->left;
            Node<T>* temp = parent->left->left;
            if(replace->right != nullptr){
                replace = replace->right;
            }
            while(replace->right != nullptr){ // finds largest smaller
                replace = replace->right;
                temp = temp->right;
            }
            temp->right = nullptr;
            parent->left = replace;
            replace->right = remNode->right;
            replace->left = remNode->left;
            remNode->right = nullptr;
            remNode->left = nullptr;
            return remNode;
        }
    }
    else{ //Remove one on right
        if(parent->right->left == nullptr && parent->right->right == nullptr){ // no children
            Node<T>* remNode = parent->right;
            parent->right = nullptr;
            return remNode;
        }
        else if(parent->right->left == nullptr || parent->right->right == nullptr){ // one child
            Node<T>* remNode = parent->right;
            if(parent->right->left == nullptr){
                parent->right = parent->right->right;
                remNode->right = nullptr;
                return remNode;
            }
            else{
                parent->right = parent->right->left;
                remNode->left = nullptr;
                return remNode;
            }
        }
        else{ // two children
            Node<T>* remNode = parent->right;
            Node<T>* replace = parent->right->left;
            Node<T>* temp = parent->right->left;
            if(replace->right != nullptr){
                replace = replace->right;
            }
            while(replace->right != nullptr){ // finds largest smaller
                replace = replace->right;
                temp = temp->right;
            }
            if(replace->left == nullptr){
                temp->right = nullptr;
            }
            else{
                temp->right = ;
            }
            parent->left = replace;
            replace->right = remNode->right;
            replace->left = remNode->left;
            remNode->right = nullptr;
            remNode->left = nullptr;
            return remNode;
        }
    }
    
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

template <typename T>
void Tree<T>::EmptyTreeHelper(Node<T>* curNode){
    if(curNode == nullptr){ return; }

    // Travel to next nodes
    EmptyTreeHelper(curNode->left);
    EmptyTreeHelper(curNode->right);
    // Then Delete current node
    delete curNode;
}
template <typename T>
void Tree<T>::EmptyTree(){ 
    EmptyTreeHelper(root); 
    root = nullptr; // Empty helper deletes / re allocs, need to tell tree root no longer points to something
}