/* Program name: M03.2 Programming Assignment - Hash Tables
* Author: Carlos Lizarazu 
* Date last updated: 04/05/2024
* Purpose: Create a Hash table with the following functions: search, isItemAtEqual, retrieve, remove, print, constructor, and destructor. 
           Then the program is being tested by three Hashing functions.
*/

#include <iostream>
#include <list>

using namespace std;

//Hash class

class hashTable {
    private:
        int table[10]; //Store values
        bool occupied[10]; //track the slots

        int (*hashFunc)(int); //pointer

    public:
        //Create the constructor
        hashTable(int (*hf)(int)){
            for(int i=0; i<10; i++){
                occupied[i] = false; //Slots are empty
            }
            hashFunc = hf; //assign the hash function
        }

        void insert(int key, int value){
            int index = hashFunc(key);
            int startIndex = index;

            while(occupied[index]){
                index = (index+1) % 10;
                if(index == startIndex){
                    cout<< "Hash table is full"<<endl;
                    return;
                }
            }
            table[index] = value; //storing the value
            occupied[index] = true; //mark the slot to used
        }

        // Search for a key
        bool search(int key) const {
            int index = hashFunc(key);
            int startIndex = index;

            while (occupied[index]) {
                if (table[index] == key) // Match found
                    return true;

                index = (index + 1) % 10;
                if (index == startIndex)
                    break;
            }

            return false; // Not found
        }


        //isItemarEqual function
        bool isItemAtEqual(int key, int value) const {
            int index = hashFunc(key);
            return occupied[index] && table[index] == value;
        }
        

        //retrevie a value
        void retrieve(int key, int& value) const {
            int index = hashFunc(key);
            int startIndex = index;
    
            while (occupied[index]) {
                if (table[index] == key) {
                    value = table[index];
                    return;
                }
    
                index = (index + 1) % 10;
                if (index == startIndex)
                    break;
            }
    
            cout << "Item not found.\n";
        }
    
        //remove a value
        void remove(int key) {
            int index = hashFunc(key);
            int startIndex = index;
    
            while (occupied[index]) {
                if (table[index] == key) {
                    occupied[index] = false; // Just mark as not occupied
                    return;
                }
    
                index = (index + 1) % 10;
                if (index == startIndex)
                    break;
            }
    
            cout << "Item not found.\n";
        }

        //print a value
        void print() const {
            for (int i = 0; i < 10; ++i) {
                if (occupied[i])
                    cout << "Slot " << i << ": " << table[i] << endl;
                else
                    cout << "Slot " << i << ": empty" << endl;
            }
        }

        //Destructor
        ~hashTable() {}
};

//Three testing programs with hash
int simpleMod(int key) {
    return key % 10;
}

// Mid-square hash function
int midSquare(int key) {
    int sq = key * key;
    return (sq / 100) % 10;
}

// Digit folding hash function
int digitFold(int key) {
    int sum = 0;
    while (key > 0) {
        sum += key % 10;
        key /= 10;
    }
    return sum % 10;
}

int main(){
    cout << "\nTesting Simple Mod Hash"<<endl;
    hashTable ht1(simpleMod);
    ht1.insert(23, 23);
    ht1.insert(33, 33);
    ht1.insert(43, 43);
    ht1.print();

    cout << "\nTesting Mid-Square Hash"<<endl;
    hashTable ht2(midSquare);
    ht2.insert(23, 23);
    ht2.insert(33, 33);
    ht2.insert(43, 43);
    ht2.print();

    cout << "\nTesting Digit Folding Hash "<<endl;
    hashTable ht3(digitFold);
    ht3.insert(23, 23);
    ht3.insert(33, 33);
    ht3.insert(43, 43);
    ht3.print();

    return 0;
}