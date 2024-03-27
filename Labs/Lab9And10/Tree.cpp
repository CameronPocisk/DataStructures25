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


// Insert and Remove helpers
template <typename T>
int Tree<T>::NodeHeight(Node<T>* curNode){
    if(curNode == nullptr){return 0;}

    int lHeight = NodeHeight(curNode->left);
    int rHeight = NodeHeight(curNode->right);
    return max(lHeight, rHeight) + 1;
}

// Used for checking which rotations to use
template <typename T>
int Tree<T>::LeftNodeHeight(Node<T>* curNode){
    if(curNode == nullptr){
        return 0;
    } 
    else if(curNode->left == nullptr){
        return 1;
    } // else
    return NodeHeight(curNode->left) + 1;
}
template <typename T>
int Tree<T>::RightNodeHeight(Node<T>* curNode){
    if(curNode == nullptr){
        return 0;
    } // else
    else if(curNode->right == nullptr){
        return 1;
    }
    return NodeHeight(curNode->right) + 1;
}


template <typename T>
// If you spot a node below that can be rotated call this fn
int Tree<T>::RotateLeft(Node<T>* parent, Node<T>* child){
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
        return depthNew(child, parent);
}
template <typename T>
int Tree<T>::RotateLeftRight(Node<T>* parent, Node<T>* child){
        if(parent == nullptr){
            //Rotate around root
            Node<T>* newRoot = root->left->right;
            root->left->right = newRoot->left;
            newRoot->left = root->left;
            root->left = newRoot->right;
            newRoot->right = root;
            root = newRoot;

            return depthNew(root, nullptr);
        }
        parent->left = child->left->right;
        child->left->right = parent->left->left;
        parent->left->left = child->left;
        child->left = parent->left->right;
        parent->left->right = child;

        return depthNew(child, parent);

}

template <typename T>
int Tree<T>::RotateRight(Node<T>* parent, Node<T>* child){
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
        return depthNew(child, parent);
}
template <typename T>
int Tree<T>::RotateRightLeft(Node<T>* parent, Node<T>* child){
            if(parent == nullptr){
            //Rotate around root
            Node<T>* newRoot = root->right->left;
            root->right->left = newRoot->right;
            newRoot->right = root->right;
            root->right = newRoot->left;
            newRoot->left = root;
            root = newRoot;

            return depthNew(root, nullptr);
        }
        parent->right = child->right->left;
        child->right->left = parent->right->right;
        parent->right->right = child->right;
        child->right = parent->right->left;
        parent->right->left = child;

        return depthNew(child, parent);
        //Balance depths
}
template <typename T>
int Tree<T>::depthNew(Node<T>* curr, Node<T>* parent){
    if(curr == nullptr){return 0;}
    //Curr is child for rotate function
    int Lheight = depthNew(curr->left, curr); //Curr will become the next parent, to call for rotate later
    int Rheight = depthNew(curr->right, curr);

    if(Lheight > Rheight){
        if(Lheight > Rheight + 1){ // need to rotate
            int Lchild = depthNew(curr->left->left, curr->left);
            int Rchild = depthNew(curr->left->right, curr->left);
            if(Rchild > Lchild) {
                // PrintStructuredHelper(curr, parent);
                cout << "LEFTRIGHT" << endl;
                Lheight = RotateLeftRight(parent, curr);
            } else{
                cout << "RIGHT" << endl;
                Lheight = RotateRight(parent, curr);
            }
        } 
        curr->height = Lheight + 1;
        return Lheight + 1;
    } else if(Rheight > Lheight){
        if(Rheight > Lheight + 1){
        int Lchild = depthNew(curr->right->left, curr->right);
        int Rchild =  depthNew(curr->right->right, curr->right);
            if(Lchild > Rchild) {
                // PrintStructuredHelper(curr, parent);
                cout << "RIGHTLEFT" << endl;
                Rheight = RotateRightLeft(parent, curr); //Readjust height after rotate
            } else{
                // PrintStructuredHelper(curr, parent);
                cout << "LEFT" << endl;
                Rheight = RotateLeft(parent, curr); //Readjust height after rotate
            }   
        }
    }
    curr->height = Rheight + 1;
    return Rheight + 1;
}



template <typename T>
Node<T>* Tree<T>::Remove(T *value){ // Removes the value then rebalances the tree
    // if(Find(root, value) == nullptr){
    //     throw NotFound();
    // }

    Node<T>* parent = removeHelper(root, value);
    // Make child node for simplicity?
    
    if(*value < *parent->data){ //Remove one on left
        Node<T>* remNode = parent->left;
        if(parent->left->left == nullptr && parent->left->right == nullptr){ // no children
            parent->left = nullptr;
            root->height = depthNew(root, nullptr);
            return remNode;
        }
        else if(parent->left->left == nullptr || parent->left->right == nullptr){ // one child
            if(parent->left->left == nullptr){ // child Right child 
                // Assign other pointers?
                parent->left = parent->left->right; // Parents Left becomes childs right
                remNode->right = nullptr; // Remove no longer points to anything
                root->height = depthNew(root, nullptr);
                return remNode;
            }
            else{ // child Left child
                parent->left = parent->left->left;
                remNode->left = nullptr;
                root->height = depthNew(root, nullptr);
                return remNode;
            }
        }
        else{ // two children
            Node<T>* replace = parent->left->left;
            Node<T>* temp = parent->left->left;
            if(replace->right != nullptr){
                replace = replace->right; // ?
            }
            while(replace->right != nullptr){ // finds largest smaller
                replace = replace->right;
                temp = temp->right;
            }
            if(replace->left == nullptr){
                temp->right = nullptr;
            }
            else{
                temp->right = temp->right->left;
            }
            parent->left = replace;
            replace->right = remNode->right;
            replace->left = remNode->left;
            remNode->right = nullptr; // Three below clear the removed node before returning
            remNode->left = nullptr;
            root->height = depthNew(root, nullptr);
            return remNode;
        }
    }
    else{ //Remove one on right
        Node<T>* remNode = parent->right;
        if(parent->right->left == nullptr && parent->right->right == nullptr){ // no children
            parent->right = nullptr;
            root->height = depthNew(root, nullptr);
            return remNode;
        }
        else if(parent->right->left == nullptr || parent->right->right == nullptr){ // one child
            if(parent->right->left == nullptr){
                parent->right = parent->right->right;
                remNode->right = nullptr;
                root->height = depthNew(root, nullptr);
                return remNode;
            }
            else{
                parent->right = parent->right->left;
                remNode->left = nullptr;
                root->height = depthNew(root, nullptr);
                return remNode;
            }
        }
        else{ // two children
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
                temp->right = nullptr;//idk
            }
            else{
                temp->right = temp->right->left;
            }
            parent->right = replace;
            replace->left = remNode->left;
            replace->right = remNode->right;
            remNode->right = nullptr;
            remNode->left = nullptr;
            root->height = depthNew(root, nullptr);
            return remNode;
        }
    }
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
void Tree<T>::PrintStructuredHelper(Node<T>* curNode){
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

template <typename T>
void Tree<T>::PrintStructuredWithRootSizesHelper(Node<T>* curNode){
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