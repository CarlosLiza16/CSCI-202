/* Program name: M06 Programming Assignment B-tree
 * Author: Carlos Lizarazu
 * Date last updated: 04/22/2025
 * Purpose: The purpose of the code is to write a B-tree and test it
 */

 #include <iostream>

 using namespace std;
 
 // Forward declaration
 template <typename T> 
 class BTree;
 
 template <typename T> 
 class BTreeNode {
   T *keys;              // list of numbers
   int t;                // Will help us know when to split
   BTreeNode **children; // childrens 
   int n;                // Current number of numbers in the node
   bool leaf;            // True if node is leaf
 
 public:
   // constructor
   BTreeNode(int _t, bool _leaf){
     t = _t;
     leaf = _leaf;
     keys = new T[2 * t - 1];
     children = new BTreeNode<T> *[2 * t];
     n = 0;
   }
 
   // Declared Functions
 
   void traverse()                    //print all the numbers in order
   {    
     int i;
       for (i = 0; i < n; i++) {
         if (!leaf)
           children[i]->traverse();   // check inside the smallers folders
         cout << keys[i] << " ";      //print the number
       }
       if (!leaf)
         children[i]->traverse();     //check the last child node
   }
 
   void insertNonFull(T k)            //Add number to a empty node
 { 
     int i = n - 1;
 
     if (leaf) {
       while (i >= 0 && keys[i] > k) {
         keys[i + 1] = keys[i];
         i--;
       }
 
       keys[i + 1] = k;
       n = n + 1;
     } else {
       while (i >= 0 && keys[i] > k)
         i--;
 
       if (children[i + 1]->n == 2 * t - 1) {
         splitchild(i + 1, children[i + 1]);
 
         if (keys[i + 1] < k)
           i++;
       }
       children[i + 1]->insertNonFull(k);
     }
   }
 
 
   void splitchild(int i, BTreeNode<T> *y){
     BTreeNode<T> *z = new BTreeNode<T>(y->t, y->leaf);
       z->n = t - 1;
 
       for (int j = 0; j < t - 1; j++)
         z->keys[j] = y->keys[j + t];
 
       if (!y->leaf) {
         for (int j = 0; j < t; j++)
           z->children[j] = y->children[j + t];
       }
 
       y->n = t - 1;
 
       for (int j = n; j >= i + 1; j--)
         children[j + 1] = children[j];
 
       children[i + 1] = z;
 
       for (int j = n - 1; j >= i; j--)
         keys[j + 1] = keys[j];
 
       keys[i] = y->keys[t - 1];
       n = n + 1;
     }
 
   template <typename U> 
   friend class BTree;
 };
 
 
 template <typename T>
 class BTree {
   BTreeNode<T> *root;    //Start point the root of the three
   int t;
 
 public:
   BTree(int _t) {
     root = nullptr;      // start a new tree and start it empty
     t = _t;
   }
 
   void traverse() {       //Prints the whole tree in order
     if (root != nullptr)
       root->traverse();
   }
 
   void insert(T k) {          // Add a number into the tree
     if (root == nullptr) {    // If the tree is empty
       root = new BTreeNode<T>(t, true);    //Crerate the first node
       root->keys[0] = k;      //insert the number
       root->n = 1;
     } else {
       if (root->n == 2 * t - 1) {    //if the root is full
         BTreeNode<T> *s = new BTreeNode<T>(t, false); //create a new root
         s->children[0] = root;       //previous root becomes a child
         s->splitchild(0, root);      //split the node
 
         int i = 0;
         if (s->keys[0] < k)          //fin for the correct child node
           i++;
         s->children[i]->insertNonFull(k);  // insert the child
 
         root = s;                  //update the root
       } else {
         root->insertNonFull(k);    //this will insert it directly if it is empty
       }
     }
   }
 };
 
 int main() { 
     //BTree<int> tree(3) t=3 means each node can have at most 5 keys before spliting
 
   //Case 1
  cout<< "Case 1" <<endl;
  BTree<int> tree1(3);
  tree1.insert(10);
  tree1.insert(20);
  tree1.insert(5);
  tree1.traverse();
  cout << "\n"<< endl;
 
   //Case 2
  cout<< "Case 2" <<endl;
  BTree<int> tree2(3);
  tree2.insert(10);
  tree2.insert(20);
  tree2.insert(5);
  tree2.insert(6);
  tree2.insert(12);
  tree2.insert(30); // Root should split here
  tree2.traverse();
  cout << "\n"<< endl;
 
  //Case 3
  cout<< "Case 3" <<endl;
  BTree<int> tree3(3);
  tree3.insert(10);
  tree3.insert(20);
  tree3.insert(5);
  tree3.insert(6);
  tree3.insert(12);
  tree3.insert(30);
  tree3.insert(7);
  tree3.insert(17);
  tree3.insert(3);
  tree3.insert(2);
  tree3.insert(8); // Should trigger more growth
  tree3.traverse();
  cout << "\n"<< endl;
  
  return 0; 
 }