#ifndef TREE_H
#define TREE_H



#include <iostream>
#include <vector>
#include <fstream>
#include "Exceptions.h"

using namespace std;

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
    int spotsChecked;

    void PrintOrderedHelper(Node<T>* curNode){
        if (curNode == nullptr){
            return; // cannot porint nothing so..
        }

        PrintOrderedHelper(curNode->left); // Print left side first 
        cout << *(curNode->data);
        PrintOrderedHelper(curNode->right); // Print right side after cur (bc its larger)
    }

    void PrintStructuredHelper(Node<T>* curNode){
        //(From Class)
        if (curNode == nullptr) { return; }

        // Print root and children data
        cout << *curNode->data << '(';
        // Put left info in paren if it exists
        if(curNode->left != nullptr){
            cout << *curNode->left->data << " ,";
        }else{
            cout << "_ , ";
        }
        if(curNode->right != nullptr){
            cout << *curNode->right->data << ')' << endl;
        }else{
            cout << "_)" << endl;
        }

        PrintStructuredHelper(curNode->left); // Do same with Left
        PrintStructuredHelper(curNode->right); // Then same w/ right
    }

    void PrintStructuredWithRootSizesHelper(Node<T>* curNode){
        if (curNode == nullptr) { return;}
        // Print root and children data
        cout << *curNode->data << '(';
        // Put left info in paren if it exists
        if(curNode->left != nullptr){
            cout << *curNode->left->data << " ,";
        }else{
            cout << "_ , ";
        }
        if(curNode->right != nullptr){
            cout << *curNode->right->data << ')';
        }else{
            cout << "_)";
        }
        // Same as structured but also print depths
        cout << "Depth: " << NodeHeight(curNode) <<
        ", L Depth: " << LeftNodeHeight(curNode->left) <<
        ", R Depth: " << RightNodeHeight(curNode->right) << endl;

        PrintStructuredWithRootSizesHelper(curNode->left); // Do same with Left
        PrintStructuredWithRootSizesHelper(curNode->right); // Then same w/ right
    }

    void EmptyTreeHelper(Node<T>* curNode){
        if(curNode == nullptr){ return; }

        // Travel to next nodes
        EmptyTreeHelper(curNode->left);
        EmptyTreeHelper(curNode->right);
        // Then Delete current node
        delete curNode;
    }

    Node<T>* insertHelper(Node<T>* current, T* value){
        if(current == nullptr){
            return new Node<T>(value);
        }

        spotsChecked+=2;
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
        spotsChecked = 0;
    }
    ~Tree(){
        // EmptyTree(); // Deleted tree besides root
        delete root; // Deletes final part of tree (the root)
    }

    int GetSpotsChecked(){
        return spotsChecked;
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

    Node<T>* Remove(T* value){
        Node<T>* temp = RemoveNewHelper(root, nullptr, value); // Remove
        root->height = depthNew(root, nullptr); // Balance
        return temp;
    }

    // Node<T>* RemoveNew(Node<T>* curNode, Node<T>* parent, T* value){
    Node<T>* RemoveNewHelper(Node<T>* curNode, Node<T>* parent, T* value){
        if(curNode == nullptr){
            return nullptr;
        }

        // traverse to correct node
        spotsChecked+=2;
        if(*value < *curNode->data) {
            curNode = RemoveNewHelper(curNode->left, curNode, value);
            return nullptr; // don't keep traversing after this
        }
        else if(*value > *curNode->data){
            curNode = RemoveNewHelper(curNode->right, curNode, value);
            return nullptr; // also dont continue here
        }

        // At correct node
        if(*(curNode->data) != *value || curNode == nullptr){
            throw NotFound();
        }

        // cout << "Parent: " << *(parent->data) << " curNode: " << *(curNode->data) << endl;

        //No children (is left or right of parent)
        if(curNode->left == nullptr && curNode->right == nullptr){
            // cout << "No children" << endl;

            if(parent->left == curNode){
                parent->left = nullptr; // Remove left node
            }
            else if(parent->right == curNode){
                parent->right = nullptr; // Remove right node
            }
            else{cout << "something bad happened. " << endl;} // Should never happen lol

            if(curNode == root){ root = nullptr; } // Also set the structures root back if needed
            Node<T>* removeHold = curNode; 
            curNode = nullptr; // Sever the node
            return removeHold; // Done!
        }

        // One node cases
        if(curNode->left == nullptr && curNode->right != nullptr
        || curNode->right == nullptr && curNode->left != nullptr){
            // cout << "One child remove" << endl;
        
            Node<T>* grandChild; // Find grandkid no matter what
            if(curNode->left != nullptr){ grandChild = curNode->left;}
            else if(curNode->right != nullptr){ grandChild = curNode->right;}
            else{cout << "Did not find grandchild" << endl;} // Should also not happen

            // Replace correct side with grandkid
            if(parent->left == curNode){
                parent->left = grandChild;
            }
            else if(parent->right == curNode){
                parent->right = grandChild;
            }
            else{cout << "issue with parent in one node" << endl;} // Another shouldnt happen

            
            if(curNode == root){ root = grandChild; } // Also set the structures root back if needed
            Node<T>* removeHold = curNode; // clean or ewwww
            curNode = nullptr;

            return removeHold;
        }

        // TWO CHILDREN CASE HEREONAFTER
        // cout << "Two children" << endl;

        // The node we will want to replace is the rightest left, handle in helper
        Node<T>* properGrandChild = RemoveRightestLeft(curNode);

        curNode->data = properGrandChild->data; // Swap the actual data
        if(curNode == root){ root = curNode; }// also set the structures root back if needed

        //Temp is what should be put in the removed spot
        // curNode->left = RemoveNewHelper(curNode->left, curNode, properGrandChild->data); // ?
        return curNode;
    }

    Node<T>* RemoveRightestLeft(Node<T>* curNode){

        Node<T>* deleteParent = curNode;
        Node<T>* rightestLeft = curNode->left; // Only in 2 child call so this is guarenteed
        // cout << "cur left: " << *(rightestLeft->data) << endl;

        while(rightestLeft->right != nullptr){
            deleteParent = rightestLeft; // Traverse as far as possible for best match
            rightestLeft = rightestLeft->right;
        }

        Node<T>* hold = rightestLeft;
        RemoveNewHelper(rightestLeft, deleteParent, rightestLeft->data); // Sever the rightest left
        return hold; // Return the held data for swapping
    }

    // If you spot a node below that can be rotated call this fn
    int RotateLeft(Node<T>* parent, Node<T>* child){
            if(parent == nullptr){
                root = child->right;
                child->right = root->left;
                root->left = child;
            }
            else if(child == parent->right){
                parent->right = child->right;
                child->right = parent->right->left;
                parent->right->left = child;
            }
            else if(child == parent->left){
                parent->left = child->right;
                child->right = parent->left->left;
                parent->left->left = child;
            }
            return depthNew(child, parent) - 1;
    }
    int RotateLeftRight(Node<T>* parent, Node<T>* child){
            if(parent == nullptr){
                //Rotate around root
                Node<T>* newRoot = root->left->right;
                root->left->right = newRoot->left;
                newRoot->left = root->left;
                root->left = newRoot->right;
                newRoot->right = root;
                root = newRoot;

                return depthNew(root, nullptr) - 1;
            }

            Node<T>* newChild = child->left->right;
            child->left->right = newChild->left;
            //No child->left other wise wouldn't be in

            newChild->left = child->left;
            child->left = newChild->right;

            newChild->right = child;
            child = newChild;
            
            if(newChild->right == parent->left){
                parent->left = child;
            } else {
                parent->right = child;
            }

            return depthNew(child, parent) - 1;

    }

    int RotateRight(Node<T>* parent, Node<T>* child){
            if(parent == nullptr){
                root = child->left;
                child->left = root->right;
                root->right = child;
            }
            else if(child == parent->left){
                parent->left = child->left;
                child->left = parent->left->right;
                parent->left->right = child;
            }
            else if(child==parent->right){
                parent->right = child->left;
                child->left = parent->right->right;
                parent->right->right = child;
            }
            //Rebalance height afterwards
            return depthNew(child, parent) - 1;
    }
    int RotateRightLeft(Node<T>* parent, Node<T>* child){
            if(parent == nullptr){
                //Rotate around root
                Node<T>* newRoot = root->right->left;
                root->right->left = newRoot->right;
                newRoot->right = root->right;
                root->right = newRoot->left;
                newRoot->left = root;
                root = newRoot;

                return depthNew(root, nullptr) - 1;
            }

            Node<T>* newChild = child->right->left;
            child->right->left = newChild->right;
            //No child->right other wise wouldn't be in

            newChild->right = child->right;
            child->right = newChild->left;

            newChild->left = child;
            child = newChild;
            if(newChild->left == parent->left){
                parent->left = child;
            } else {
                parent->right = child;
            }

            return depthNew(child, parent) - 1;
            //Balance depths
    }
    int depthNew(Node<T>* curr, Node<T>* parent){
        if(curr == nullptr){return 0;}
        //Curr is child for rotate function
        int Lheight = depthNew(curr->left, curr); //Curr will become the next parent, to call for rotate later
        int Rheight = depthNew(curr->right, curr);
        if(Lheight > Rheight){
            // cout << "Heights: " << Lheight << ", " << Rheight << endl;
            if(Lheight > Rheight + 1){ // need to rotate
                int Lchild = depthNew(curr->left->left, curr->left);
                int Rchild = depthNew(curr->left->right, curr->left);
                if(Rchild > Lchild) {
                    Lheight = RotateLeftRight(parent, curr);
                } else{
                    Lheight = RotateRight(parent, curr);
                }
            } 
            curr->height = Lheight + 1;
            return Lheight + 1;
        } else if(Rheight > Lheight + 1){
            // cout << "Heights: " << Lheight << ", " << Rheight << endl;
            if(Rheight > Lheight + 1){
            int Lchild = depthNew(curr->right->left, curr->right);
            int Rchild =  depthNew(curr->right->right, curr->right);
            // cout << Lchild << ", " << Rchild << endl;
                if(Lchild > Rchild) {
                    Rheight = RotateRightLeft(parent, curr); //Readjust height after rotate
                } else{
                    Rheight = RotateLeft(parent, curr); //Readjust height after rotate
                }   
            }
        }
        curr->height = Rheight + 1;
        return Rheight + 1;
    }

    // Insert and Remove helpers
    int NodeHeight(Node<T>* curNode){
        if(curNode == nullptr){return 0;}

        int lHeight = NodeHeight(curNode->left);
        int rHeight = NodeHeight(curNode->right);
        return max(lHeight, rHeight) + 1;
    }

    // Used for checking which rotations to use
    int LeftNodeHeight(Node<T>* curNode){
        if(curNode == nullptr){
            return 0;
        } 
        else if(curNode->left == nullptr){
            return 1;
        } // else
        return NodeHeight(curNode->left) + 1;
    }
    int RightNodeHeight(Node<T>* curNode){
        if(curNode == nullptr){
            return 0;
        } // else
        else if(curNode->right == nullptr){
            return 1;
        }
        return NodeHeight(curNode->right) + 1;
    }
    
    Node<T>* Find(T *value){return findHelper(root, value); }; // Returns pointer to the value
    int Size(){return sizeHelper(root);} //Get's the number of elements in the tree
    bool IsEmpty() {return root == nullptr;}
    
    void GetAllAscendingHelper(Node<T>* current, vector<Node<T>*> &result){
        if (current != nullptr){
            GetAllAscendingHelper(current->left, result); 
            // result.push_back(current->data);
            result.push_back(current);
            GetAllAscendingHelper(current->right, result);
        }
    }
    void GetAllDecendingHelper(Node<T>* current, vector<Node<T>*> &result){
    
        if (current != nullptr){
            GetAllDecendingHelper(current->right, result);
            // result.push_back(current->data);
            result.push_back(current);
            GetAllDecendingHelper(current->left, result); 
        }
    }

    vector<Node<T>*> GetAllAscending(){ // Returns an array of each node form largest to smallest // Theese are going to look the the print fn done curNode class
        vector<Node<T>*> result;
        GetAllAscendingHelper(root, result);
        return result;
    }
    vector<Node<T>*>   GetAllDecending(){ // Returns an array of each node form largest to smallest
        vector<Node<T>*> result;
        GetAllDecendingHelper(root, result);
        return result;
    }
    void EmptyTree(){ 
        EmptyTreeHelper(root); 
        root = nullptr; // Empty helper deletes / re allocs, need to tell tree root no longer points to something
    } // oves and deletes all nodes (No memory leaks pls)
    
    void PrintStructured(){PrintStructuredHelper(root);}
    void PrintOrdered(){PrintOrderedHelper(root);}
    void PrintStructuredWithRootSizes(){PrintStructuredWithRootSizesHelper(root);}

};


#endif