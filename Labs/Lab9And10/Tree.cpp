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
        return depthNew(child, parent) - 1;
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

            return depthNew(root, nullptr) - 1;
        }
        // cout << *child->data << endl;
        // cout << *parent->data << endl;

        Node<T>* newChild = child->left->right;
        child->left->left =  newChild->right;
        child->left->right = newChild->left;
        //No child->right other wise wouldn't be in

        newChild->left = child->left;
        newChild->right = child;
        child->left = child->left->left;
        child = newChild;
        parent->left = child;

        return depthNew(child, parent) - 1;

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
        return depthNew(child, parent) - 1;
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

            return depthNew(root, nullptr) - 1;
        }

        Node<T>* newChild = child->right->left;
        child->right->right =  newChild->left;
        child->right->left = newChild->right;
        //No child->right other wise wouldn't be in

        newChild->right = child->right;
        newChild->left = child;
        child->right = child->right->right;
        child = newChild;
        parent->left = child;

        return depthNew(child, parent) - 1;
        //Balance depths
}
template <typename T>
int Tree<T>::depthNew(Node<T>* curr, Node<T>* parent){
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
                // PrintStructuredHelper(curr, parent);
                // cout << "LEFTRIGHT" << endl;
                Lheight = RotateLeftRight(parent, curr);
            } else{
                // cout << "RIGHT" << endl;
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
                // PrintStructuredHelper(curr, parent);
                // cout << "RIGHTLEFT" << endl;
                Rheight = RotateRightLeft(parent, curr); //Readjust height after rotate
            } else{
                // PrintStructuredHelper(curr, parent);
                // cout << "LEFT" << endl;
                Rheight = RotateLeft(parent, curr); //Readjust height after rotate
            }   
        }
    }
    curr->height = Rheight + 1;
    return Rheight + 1;
}

template <typename T>
Node<T>* Tree<T>::RemoveNew(T* value){
    Node<T>* temp = RemoveNewHelper(root, nullptr, value); // Remove
    root->height = depthNew(root, nullptr); // Balance
    return temp;
}

template <typename T>
// Node<T>* Tree<T>::RemoveNew(Node<T>* curNode, Node<T>* parent, T* value){
Node<T>* Tree<T>::RemoveNewHelper(Node<T>* curNode, Node<T>* parent, T* value){
    if(curNode == nullptr){
        return nullptr;
    }

    // traverse to correct node
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

template <typename T>
Node<T>* Tree<T>::RemoveRightestLeft(Node<T>* curNode){

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