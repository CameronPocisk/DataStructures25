/*
Binary tree is a data structure where each node in the structure is capable of pointin gto 2 child nodes
Root node - a node with no parent. top of tree
bninary tree must have 1 and only 1 path to any given node
the levels refer to the dostance from the root. the root level is 0. its children are 1, grandchildren are 2
height of the tree is maximum level
max num of nodes in a level is 2^n where n is the level
min num of levels is log2(n) + 1

to get the benefit of a binary tree, the tree needs to be arranged meaningfully. 
usually this is with smaller values as children on the left and larger as children on the right

Why binary trees? Finding a variable is fast.
*/

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int val){
            data = val;
        }
};

class tree{
    node* root;

    void add(int val){
        if(isEmpty()){
            root = new node(val);
            return;
        }
        node* current = root;
        while(current->data > val || current->left != nullptr && current->data < val || current->right != nullptr){
            if(val <= current->data){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        if(val <= current->data){
            current->left = new node(val);
        }
        else{
            current->right = new node(val);
        }
    }
    bool isEmpty(){
        return root == nullptr;
    }
    int find(int val){
        if(isEmpty()){
            return 0;
            //throw notFound(); //Exception
        }
        node* current = root;
        while(current->data > val && current->left != nullptr || current->data < val && current->right != nullptr){
            if(current->data > val){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        if(current->data == val){
            return current->data;
        }
        else{
            return 0;
            //throw notFound();
        }
    }
    int largestSmaller(node* cur){
        while(cur->right != nullptr){
            cur = cur->right;
        }
    }

    int remove(int val){
        find(val); // Handles empty and not in tree

        // Loop until we are at parent
        node* temp = root;
        while((temp->right != nullptr && temp->right->data != val) || (temp->left != nullptr && temp->left->data != val)){
            if(val < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        if(temp->data < val){ // Remove left
            if(temp->left->left == nullptr && temp->left->right == nullptr){ // Num we are removing is a leaf
                int returnVal = temp->left->data;
                delete temp->left;
                temp->left = nullptr;
                return returnVal;
            }
            else if(temp->left->left == nullptr || temp->left->right == nullptr){ // One child
                int returnVal = temp->left->data;
                if(temp->left->left == nullptr){
                    node* oldTemp = temp->left;
                    temp->left = temp->left->right;
                    delete oldTemp;
                    return returnVal;
                }
                else{
                    node* oldTemp = temp->left;
                    temp->left = temp->left->left;
                    delete oldTemp;
                    return returnVal;
                }
            }
            else{  // Two children
                // Replace with smallest larger or largest smaller
                int replace = largestSmaller(temp->left->left);
                int returnVal = temp->left->data;
                temp->left->data = replace;
            }

        }
        else{   // Remove right (not finished, look at return left)
            if(temp->right->right == nullptr && temp->right->left == nullptr){ // Num we are removing is a leaf
                int returnVal = temp->right->data;
                delete temp->right;
                temp->right = nullptr;
                return returnVal;
            }
        }
    }

};