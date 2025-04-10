/* Program name: M04. Programming assignment Selection and Merge sort
 * Author: Carlos Lizarazu
 * Date last updated: 04/10/2025
 * Purpose: The program will test and compare two methods of sort: Selection and merge sort
 */

#include <iostream>
#include <chrono> //for time
#include <random>

 using namespace std;

//defining the structure of a node in a liked list
struct Node{
    int value;
    Node* next;

    Node(int val){
        value = val;
        next = nullptr;
    }
};

//class of the linked list
class Linkedlist{
    public:
        Node* head;
        Linkedlist() : head(nullptr){}

        //Function to append a node to the list
        void append(int value){
            Node* newNode = new Node(value);
            if(!head){
                head = newNode;
            }else{
                Node* current = head;
                while (current->next){
                    current = current-> next;
                }
                current-> next = newNode;
            }
        }

        //--------------------------------------------------------------------
        //Selection sort Code for the linked list
        void selectionSort(){
            Node* current = head;
            while (current){
                Node* minNode = current;
                Node* nextNode = current->next;
                while(nextNode){
                    if(nextNode->value < minNode->value){
                        minNode = nextNode;
                    }
                    nextNode = nextNode->next;
                }

                //Check if the current value is differernt then the min value
                if(minNode != current){
                    int t = current->value;
                    current->value = minNode->value;
                    minNode->value = t;
                }
                current = current->next;
            }
        }
        //----------------------------------------------------------------

        //------------------------------------------------------------------
        //Merge sort code for the linked list
        Node* mergeSort(Node* head){
            if(!head || !head->next){
                return head;
            }

            //Find the middle of the list
            Node* slow = head;
            Node* fast = head;
            Node* prev = nullptr;

            while(fast && fast->next){
                fast = fast->next->next;
                prev =slow;
                slow = slow->next;
            }

            if(prev){
                prev->next = nullptr;
            }

            Node* left = mergeSort(head);
            Node* right=mergeSort(slow);

            return merge(left,right);
        }

        //Merge the two list
        Node* merge(Node* left, Node* right){
            if(!left){
                return right;
            }
            if(!right){
                return left;
            }

            if(left->value< right->value){
                left->next = merge(left->next, right);
                return left;
            }else{}
                right->next = merge(left, right->next);
                return right;
            }
        //------------------------------------------------------------------
        
        //clear the lists for each test
        void clearList(){
            while(head){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        //testing the sort methods with time

        void testSort(const string& method, int numElements){
            clearList();
            for(int i=0; i<=numElements; i++){
                append(rand() % 1000);
            }

            //measure the time before sorting
            auto start = chrono::high_resolution_clock::now();

            //Sort te lists
            if(method =="selection"){
                selectionSort();
            }else if(method == "merge"){
                head = mergeSort(head);
            }

            //measure the time after the sorting
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double> duration = end - start;
            cout<< method << "  method took this time to sort  " << numElements << " numbers,  Time:  " << duration.count() << " sec " << endl;
        }
};


 int main(){
    Linkedlist linkedlist;

    int sizeList[]= {1, 10, 100, 1000, 10000};

    for (int size : sizeList){
        cout<<"Testing " << size << " numbers: " << endl;

        linkedlist.testSort("selection", size);

        linkedlist.testSort("merge",size);
    }


    return 0;
 }