#ifndef TREE_H
#define TREE_H
#include "Exceptions.h"
#include <vector>


template <typename T>
class Node{
public:
    
    Node* left;
    Node* right;
    T* data;
    int height;
    
    Node(T* value = nullptr) {
        data = value;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
};


template <typename T>
class Tree{
private:
    Node<T>* root;

    void PrintOrderedHelper(Node<T>* curNode);
    void PrintStructuredHelper(Node<T>* curNode);
    void PrintStructuredWithRootSizesHelper(Node<T>* curNode);
    void EmptyTreeHelper(Node<T>* curNode);
    void GetAllAscendingHelper(Node<T>* curNode, vector<Node<T>*> &result); 
    void GetAllDecendingHelper(Node<T>* curNode, vector<Node<T>*> &result);

    Node<T>* insertHelper(Node<T>* current, T* value){
        if(current == nullptr){
            return new Node<T>(value);
        }

        if(*value == *(current->data)){
            throw OverflowError(); //If the value is already in the tree
        }

        else if(*value < *(current->data)){
            current->left = insertHelper(current->left, value);
        } else {
            current->right = insertHelper(current->right, value);
        }

        return current;
    }

    Node<T>* findHelper(Node<T>* current, T* value) {
        if(current == nullptr){
            throw NotFound();
        }

        if(*value == *(current->data)){
            return current; // Found it!
        }

        if(*value < *(current->data)){
            return findHelper(current->left, value);
        } else {
            return findHelper(current->right, value);
        }
    }

    Node<T>* removeHelper(Node<T>* current, T* value){
        // Finds parent of remove node ?

        // if(current->right != nullptr && *value == *(current->right->data)
        // || current->left != nullptr && *value == *(current->right->data)){
        //     return current;
        // }

        if(*value == *(current->right->data) || *value == *(current->left->data)){
            return current;
        }
        else if(*value < *(current->data)){
            current = removeHelper(current->left, value);
        }
        else if(*value > *(current->data)){
            current = removeHelper(current->right, value);
        }
        cout << "Left conditions" << endl;
        throw NotFound();
        return nullptr; // Not found here?
    }

    int sizeHelper(Node<T>* current){
        if(IsEmpty()){
            return 0;
        }
        int leftSize = 0;
        int rightSize = 0;

        if(current->right == nullptr){
            rightSize = 0;
        } else {
            rightSize = sizeHelper(current->right);
        }

        if(current->left == nullptr){
            leftSize = 0;
        } else {
            leftSize = sizeHelper(current->left);
        }

        return leftSize + rightSize + 1;
    }

    Node<T>* balanceTreeHelper(vector<Node<T>*> &sorted, int beg, int end){

        if(beg > end){
            return nullptr;
        }

        int mid = (beg+end)/2;
        Node<T>* current = new Node<T>(sorted[mid]->data);

        current->left = balanceTreeHelper(sorted, beg, mid-1);
        current->right = balanceTreeHelper(sorted, mid+1, end);

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
    
    Node<T>* balanceTree(){ // works but need to do something else
        vector<Node<T>*> sorted = GetAllAscending();
        int n = sorted.size();
        return balanceTreeHelper(sorted, 0, n-1);
    }


    void Insert(T *data){
        root = insertHelper(root, data);
        root->height = depthNew(root, nullptr);
    }

    Node<T>* Remove(T *value); // Removes the value then rebalances the tree
    Node<T>* RemoveNewHelper(Node<T>* curNode, Node<T>* parent, T* value);
    Node<T>* RemoveNew(T* value);

    Node<T>* FindRightestLeft(Node<T>* curNode);

    int RotateLeft(Node<T>* parent, Node<T>* child);
    int RotateRight(Node<T>* parent, Node<T>* child);
    int RotateLeftRight(Node<T>* parent, Node<T>* child);
    int RotateRightLeft(Node<T>* parent, Node<T>* child);
    int depthNew(Node<T>* curr, Node<T>* parent);
    int NodeHeight(Node<T>* curNode);
    int LeftNodeHeight(Node<T>* curNode);
    int RightNodeHeight(Node<T>* curNode);
    
    Node<T>* Find(T *value); // Returns pointer to the value
    int Size(); //Get's the number of elements in the tree
    bool IsEmpty() {return root == nullptr;}
    vector<Node<T>*> GetAllAscending(); // Returns an array of each node from smallest to largest // Theese are going to look the the print fn done in class
    vector<Node<T>*> GetAllDecending(); // Returns an array of each node form largest to smallest // Theese are going to look the the print fn done in class
    void EmptyTree(); //Removes and deletes all nodes (No memory leaks pls)
    
    void PrintStructured(){PrintStructuredHelper(root);}
    void PrintOrdered(){PrintOrderedHelper(root);}
    void PrintStructuredWithRootSizes(){PrintStructuredWithRootSizesHelper(root);}

};

#endif