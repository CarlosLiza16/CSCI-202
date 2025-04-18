/* Program name: M05.1 Programming Assignment - Binary Tree
* Author: Carlos Lizarazu 
* Date last updated: 04/18/2024
* Purpose: Create a binary tree with a function that returns the number of nodes that only have one child
*/

#include <iostream>

using namespace std;

template <class elemType>
struct binaryTreeNode{
    elemType info;
    binaryTreeNode<elemType> *leftlink;
    binaryTreeNode<elemType> *rightlink;

    binaryTreeNode(elemType val){
        info = val;
        leftlink = nullptr;
        rightlink = nullptr;
    }
};

//create the class binary tree
template <class elemType>
class binaryTreeType{
   
    public:
    binaryTreeType(); // constructor
    void insert(elemType value); //inserting node into te three
    int singleParent(); // cout how many single nodes we have

    private:
    binaryTreeNode<elemType>* root;
    void insert(binaryTreeNode<elemType>*& node, elemType value); //recursive insert
    int singleParent(binaryTreeNode<elemType>* node); //recursive leaf counter
};

//constructor initialize root to null
template <class elemType>
binaryTreeType<elemType> :: binaryTreeType(){
    root = nullptr;
}

//insert function
template <class elemType>
void binaryTreeType<elemType>::insert(elemType value){
    insert(root, value);
}

// Recursive insert helper
template <class elemType>
void binaryTreeType<elemType>::insert(binaryTreeNode<elemType>*& node, elemType value) {
    if (node == nullptr) {
        node = new binaryTreeNode<elemType>(value);
    } else if (value < node->info) {
        insert(node->leftlink, value);
    } else {
        insert(node->rightlink, value);
    }
}

//Funtion for the single parent
template <class elemType>
int binaryTreeType<elemType> :: singleParent(binaryTreeNode<elemType>* node){
    if(node ==  nullptr){
        return 0;
    }

    int count = 0;

    //check for a single node
    if((node->leftlink == nullptr && node->rightlink !=nullptr) || (node->leftlink != nullptr && node->rightlink ==nullptr)){
        count = 1;
    }
    count += singleParent(node->leftlink);
    count += singleParent(node->rightlink);
    return count;
}

template <class elemType>
int binaryTreeType<elemType>::singleParent() {
    return singleParent(root);
}


int main() {
    binaryTreeType<int> myTree;

    // Build a tree with some single parents
    myTree.insert(10);
    myTree.insert(5);
    myTree.insert(15);
    myTree.insert(3);
    myTree.insert(7);
    myTree.insert(8);
    myTree.insert(20);
    myTree.insert(25);
    myTree.insert(9);
    myTree.insert(23);
    myTree.insert(22);
    myTree.insert(26);
    myTree.insert(27);

    cout << "Number of single parents: " << myTree.singleParent() << endl;
    return 0;
}