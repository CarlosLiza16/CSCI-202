/* Program name: M05.1 Programming Assignment - Binary Tree
* Author: Carlos Lizarazu 
* Date last updated: 04/17/2024
* Purpose: Create a program that creates a binary tree and count how many leaves we have.
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
    int leavesCount(); // number of leaves int he three

    private:
    binaryTreeNode<elemType>* root;
    void insert(binaryTreeNode<elemType>*& node, elemType value); //recursive insert
    int leavesCount(binaryTreeNode<elemType>* node); //recursive leaf counter
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

// Public leavesCount function
template <class elemType>
int binaryTreeType<elemType>::leavesCount() {
    return leavesCount(root);
}

// Recursive leaf counting helper
template <class elemType>
int binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType>* node) {
    if (node == nullptr)
        return 0;
    if (node->leftlink == nullptr && node->rightlink == nullptr)
        return 1;
    return leavesCount(node->leftlink) + leavesCount(node->rightlink);
}


int main(){

    binaryTreeType<int> myTree;

    // Insert nodes
    myTree.insert(10);
    myTree.insert(5);
    myTree.insert(15);
    myTree.insert(3);
    myTree.insert(7);
    myTree.insert(13);
    myTree.insert(20);
    myTree.insert(18);
    myTree.insert(25);
    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(8);
    myTree.insert(23);
    myTree.insert(28);


    cout << "Number of leaf nodes: " << myTree.leavesCount() << endl;

    
    return 0;
}