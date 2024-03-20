#ifndef TREE_H
#define TREE_H
#include "Exceptions.h"


template <typename T>
class Node{
public:
    
    Node* left;
    Node* right;
    T* data;
    
    Node(T* value = nullptr) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


template <typename T>
class Tree{
private:
    Node<T>* root;

    void PrintOrderedHelper(Node<T>* in);
    Node<T>* insertHelper(Node<T>* current, T* value){
        if(current == nullptr){
            return new Node<T>(value);
        }

        if(*value < *current->data){
            current->left = insertHelper(current->left, value);
        } else {
            current->right = insertHelper(current->right, value);
        }

        return current;
    }

    
public:
    Tree(){
        root = nullptr;
    }
    ~Tree(){
        // EmptyTree(); // Deleted tree besides root
        delete root; // Deletes final part of tree (the root)
    }
    
    void Insert(T *data){root = insertHelper(root, data);}
    Node<T>* Find(Node<T>* current, T value); // Returns pointer to the value
    int Size(); //Get's the number of elements in the tree
    bool IsEmpty() {return root == nullptr;}
    int* GetAllAscending(); // Returns an array of each node from smallest to largest // Theese are going to look the the print fn done in class
    int* GetAllDecending(); // Returns an array of each node form largest to smallest // Theese are going to look the the print fn done in class
    void EmptyTree(); //Removes and deletes all nodes (No memory leaks pls)
    Node<T>* Remove(T value); // Removes the value then rebalances the tree
    void PrintStructured();
    void PrintOrdered();
};

#endif