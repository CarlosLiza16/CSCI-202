/* Program name: M06 Programming Assignment B-tree
 * Author: Carlos Lizarazu
 * Date last updated: 04/22/2025
 * Purpose: The purpose of the code is to write an AVL and test it 
 */

#include <iostream>

using namespace std;

//Code for  the AVL tree
template<class elemType>
struct AVLNode{
    elemType info;              // value store in the node  
    int bfactor;                //balance factor -1 right is larger, 0 is balance and 1 left is larger
    AVLNode<elemType> *llink;   // pointer to the left
    AVLNode<elemType> *rlink;   // pointer to the right
};

template<class elemType>
class AVLTree{
public:
    AVLTree(){
        root = nullptr;         // start the root as empty 
    }
    
    void insert(const elemType& item){
        bool taller = false;
        insertAVL(root, item, taller);
    }

    void inorder() const{
        inorderTraversal(root);         //we start the travesal at the root
        cout <<"\n"<< endl;
    }
private:
    AVLNode<elemType>* root;        //pointer tot he root of the node

    void insertAVL(AVLNode<elemType>*& p, const elemType& newItem, bool& taller){
        if(p == nullptr) //if the node doesnt exits then create a new one
        {
            p= new AVLNode<elemType>;
            p->info = newItem;
            p->bfactor = 0;
            p->llink = nullptr;
            p->rlink = nullptr;
            taller = true;
        }else if(newItem < p->info){              //insert the left subtree
            insertAVL(p->llink, newItem, taller);

            if (taller) {                         //update the factor base 
                switch (p->bfactor) {
                    case -1:
                        p->bfactor = 0;            //tree will becamo balance
                        taller = false;
                        break;
                    case 0:
                        p->bfactor = 1;             //tree becomes left heavy
                        break;
                    case 1:
                        balanceFromLeft(p);         // rebalance needed
                        taller = false;
                        break;
                }
            }
        }else{
            insertAVL(p->rlink, newItem, taller);       //insert in the right subtree

            if (taller) {
                switch (p->bfactor) {
                    case 1:
                        p->bfactor = 0;
                        taller = false;
                        break;
                    case 0:
                        p->bfactor = -1;
                        break;
                    case -1:
                        balanceFromRight(p);
                        taller = false;
                        break;
                }
            }
        }
    }

    void rotateToLeft(AVLNode<elemType>*& root) {
        AVLNode<elemType>* p = root->rlink;     // right child
        root->rlink = p->llink;                 // shift left subtree
        p->llink = root;                        //move root down
        root = p;                               //new root
    }

    void rotateToRight(AVLNode<elemType>*& root) {
        AVLNode<elemType>* p = root->llink;     // left child
        root->llink = p->rlink;                 // shift right subtree
        p->rlink = root;                        // move root down
        root = p;                               // New root
    }

    //------------------------------------
    void balanceFromLeft(AVLNode<elemType>*& root) {
        AVLNode<elemType>* p = root->llink;

        if (p->bfactor == 1) {  // Single right rotation
            root->bfactor = 0;
            p->bfactor = 0;
            rotateToRight(root);
        } else {  // Double rotation: left-right
            AVLNode<elemType>* w = p->rlink;

            switch (w->bfactor) {
                case 1:
                    root->bfactor = -1;
                    p->bfactor = 0;
                    break;
                case 0:
                    root->bfactor = 0;
                    p->bfactor = 0;
                    break;
                case -1:
                    root->bfactor = 0;
                    p->bfactor = 1;
                    break;
            }

            w->bfactor = 0;
            rotateToLeft(p);
            root->llink = p;
            rotateToRight(root);
        }
    }

    //---------------------------------------------------------
    void balanceFromRight(AVLNode<elemType>*& root) {
        AVLNode<elemType>* p = root->rlink;

        if (p->bfactor == -1) {  // Single left rotation
            root->bfactor = 0;
            p->bfactor = 0;
            rotateToLeft(root);
        } else {  // Double rotation: right-left
            AVLNode<elemType>* w = p->llink;

            switch (w->bfactor) {
                case -1:
                    root->bfactor = 1;
                    p->bfactor = 0;
                    break;
                case 0:
                    root->bfactor = 0;
                    p->bfactor = 0;
                    break;
                case 1:
                    root->bfactor = 0;
                    p->bfactor = -1;
                    break;
            }

            w->bfactor = 0;
            rotateToRight(p);
            root->rlink = p;
            rotateToLeft(root);
        }
    }

    //------------------------
    void inorderTraversal(AVLNode<elemType>* p) const {
        if (p != nullptr) {
            inorderTraversal(p->llink);
            cout << p->info << " ";
            inorderTraversal(p->rlink);
        }
    }
};
 
int main(){
    int n1=10, n2=20, n3=30;

    // LL Case: Heavy on left-left
    AVLTree<int> treell;
    cout<<"Order of values: "<< n3 << " - " << n2 << " - " << n1 <<endl;
    treell.insert(n3);
    treell.insert(n2);
    treell.insert(n1);  // Causes LL rotation
    cout << "Inorder Traversal after LL Rotation:\n";
    treell.inorder();  // Output should be: 10 20 30

    // RR Case: Heavy on right-right
    AVLTree<int> treerr;
    cout<<"Order of values: "<< n1 << " - " << n2 << " - " << n3 <<endl;
    treerr.insert(n1);
    treerr.insert(n2);
    treerr.insert(n3);  // Causes RR rotation
    cout << "Inorder Traversal after RR Rotation:\n";
    treerr.inorder();  // Output should be: 10 20 30

    // LR Rotation Example
    AVLTree<int> treeLR;
    cout<<"Order of values: "<< n3 << " - " << n1 << " - " << n2 <<endl;
    treeLR.insert(n3);
    treeLR.insert(n1);
    treeLR.insert(n2); // Triggers LR Rotation
    cout << "Inorder Traversal after LR Rotation:\n";
    treeLR.inorder();  // Expected: 10 20 30
    return 0;
}