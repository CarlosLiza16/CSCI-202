/* Program name: M05.1 Programming Assignment - Recursive Order an array 
* Author: Carlos Lizarazu 
* Date last updated: 04/15/2024
* Purpose: Create a program that uses a recursive function to reverese the elements of an array between two indices
*/

#include <iostream>

using namespace std;

//Recursive functio to reverse the Array
void reverseArray(int* array, int low, int high){
    //base case
    if(low >= high){
        return;
    }  

    int holdvalue = array[low];
    array[low] = array[high];
    array[high] = holdvalue;

    reverseArray(array, low+1, high-1);
}

//print array function
void displayArray(int array[], int l){
    for (int i=0; i<l; i++){
        cout<<array[i]<< " ";
    }
    cout << endl;
}

int main(){
    //test of the program
    int n1=9;
    int array[n1] = {10,20,30,40,50,60,70,80,90};
    
    //testing the index
    int low = 0;
    int high = 4;

    cout<<"Original Array: " << endl;
    displayArray(array, n1);

    reverseArray(array, low, high);

    cout<<"Reverse Array is: ";
    displayArray(array, n1);

    return 0 ;
}