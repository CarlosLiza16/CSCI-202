/* Program name: M03.1 (#17) Programming Assignment - Queues - class linkedQueueType
* Author: Carlos Lizarazu 
* Date last updated: 04/03/2025
* Purpose: write a Queue class derived form a unorderedlinkedlist, and write a test program
*/

#include <iostream>

using namespace std;

template <class Type>
class nodeType{
    public:
        Type info;
        nodeType<Type>* link;
};

//UnorderedLinked class
template <class Type>
class linkedListType {
    protected:
        nodeType<Type>* first;
        nodeType<Type>* last;
        int count;

    public:
        //Constructor
        linkedListType() {
            first = nullptr;
            last = nullptr;
            count = 0;
        }

        //Destructor
        ~linkedListType() {
            nodeType<Type>* temp;
            while (first != nullptr) {
                temp = first;
                first = first->link;
                delete temp;
            }
            last = nullptr;
            count = 0;
        }

        bool isEmpty() const {
            return first == nullptr;
        }

        void insertLast(const Type& newItem) {
            nodeType<Type>* newNode = new nodeType<Type>;
            newNode->info = newItem;
            newNode->link = nullptr;

            if (isEmpty()) {
                first = last = newNode;
            } else {
                last->link = newNode;
                last = newNode;
            }
            count++;
        }

        void deleteNode(const Type& deleteItem) {
            if (isEmpty()) {
                cout << "List is empty. Cannot delete.\n";
                return;
            }

            nodeType<Type>* current = first;
            nodeType<Type>* previous = nullptr;

            while (current != nullptr && current->info != deleteItem) {
                previous = current;
                current = current->link;
            }

            if (current == nullptr) {
                cout << "Item not found in the list.\n";
                return;
            }

            if (current == first) {
                first = first->link;
                if (first == nullptr) {
                    last = nullptr;
                }
            } else {
                previous->link = current->link;
                if (current == last) {
                    last = previous;
                }
            }

            delete current;
            count--;
        }
};

//LinkedQueue Type

template <class Type>
class linkedQueueType : public linkedListType<Type>{
    public:

        //Add the new value to the queue
        void addqueue(const Type& newValue){
            this-> insertLast(newValue);
        }

        //Add a value fro the queue
        void delqueue(){
            if(!this->isEmpty()){
                this->deleteNode(this->front());
            }else{
                cout << "Queue is empty, cannot dequeue" <<endl;
            }
        }

        //Get front element
        Type front() const{
            if(!this->isEmpty()){
                return this->first->info;
            }else{
                cout << "Queue is empty" <<endl;
            }
        }
        
        //Get the back element
        Type back() const {
            if(!this->isEmpty()){
                return this->last->info;
            }else{
                cout<<"The Queue is empty" <<endl;
            }
        }
};

int main(){

    //initialize the class and give the type
    linkedQueueType<int> queue;

    cout << "Numbers that are being entered: none"<<endl;

    /*cout << "Number that are being entered: 100, 150, 200, 250"<<endl;
    queue.addqueue(100);
    queue.addqueue(150);
    queue.addqueue(200);
    queue.addqueue(250);*/

    /*cout << "Number that are being entered: 10, 15, 20, 25, 30, 35, 40"<<endl;
    queue.addqueue(10);
    queue.addqueue(15);
    queue.addqueue(20);
    queue.addqueue(25);
    queue.addqueue(30);
    queue.addqueue(35);
    queue.addqueue(40);*/

    //Show the first and last element
    cout <<"The first element of the Queue is: "<< queue.front()<<endl;
    cout <<"The last element of the queue is: "<< queue.back()<<endl;

    //delete from the queue
    queue.delqueue();

    //Show elements after deleting
    cout <<"First element of the Queue after delete an element: "<< queue.front()<<endl;
    cout <<"Last element of the Queue after delete an element: "<< queue.back()<<endl;

    return 0;
}