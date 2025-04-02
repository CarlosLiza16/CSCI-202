/* Program name: M03.1 Programming Assignment - Queues
* Author: Carlos Lizarazu 
* Date last updated: 04/02/2025
* Purpose: Create a Queue class test program to test various operations on queue
*/

#include <iostream>

using namespace std;

//Creating teh class of the Queues
class Queue{
    private:
        int* arr;
        int front;
        int back;
        int capacity;
        int size;
    
    public:
        //Create the constructor
        Queue(int cap){
            capacity = cap;
            arr = new int[capacity];
            front = 0;
            back = -1;
            size = 0;
        }
    
    //Method to add an element
    void addQueue(int newValue){
        if (isFull()) { // Check if the queue is full before adding
            cout << "Queue is full. Cannot add " << newValue << endl;
            return; // Don't add the element if the queue is full
        }
        back = (back+1) % capacity;
        arr[back] = newValue;
        size++;
    }

    int removeQueue(){
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove an element." << endl;
            return -1; // Handle the case where the queue is empty
        }
        int removeQueue = arr[front];
        front = (front + 1) % capacity;
        size--;
        return removeQueue;
    }

    bool isEmpty(){
        return size ==0;
    }

    bool isFull(){
        return size == capacity - 1;
    }

    int frontelement(){
        if(size ==0){
            cout <<"Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getSize(){
        return size;
    }
};

int main(){
    
    //Creating the size of the Queue
    Queue s(5);

    //Adding values to the Queue
    s.addQueue(100);
    s.addQueue(200);
    s.addQueue(300);
    

    
    //Testing if the Queue is full or empty
    if(s.isEmpty()){
        cout<<"The Queue is empty"<<endl;
    }else if (s.isFull())
    {
        cout<<"The Queue is full"<<endl;
    }else{
        //ask for the size and show the first element
        cout << "Queue size: " << s.getSize()<<endl;
        cout << "The front element is: "<< s.frontelement()<<endl;

        //Delete one element and ask for the size
        cout<< "Remove from the queue: "<< s.removeQueue()<<endl;
        cout << "Queue size after removing an element: " << s.getSize()<<endl;
        

        //addign more value to the Queue
       /* s.addQueue(800);
        s.addQueue(900);*/
        cout << "Queue size after adding new values: " << s.getSize()<<endl;
        if (s.isFull()){
            cout<<"The Queue is full"<<endl;
        }else{
            cout<<"Is not full yet"<<endl;
        }
    }

    
    
    return 0;
}

