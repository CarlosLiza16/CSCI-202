/* Program name: M05.1 Programming Assignment - Recursive Pattern 
* Author: Carlos Lizarazu 
* Date last updated: 04/15/2024
* Purpose: Create a program that uses a recursive function and generates a pattern of stars from the input of a user.
*/

#include <iostream>

using namespace std;

//This recursive function will display the starts
void displayStars(int n){
    if(n==0){
        return;
    }
    cout<<"*";

    displayStars(n-1);
};

//This recursive function will send the pattern to the first function to be displayed
void pattern(int s){
    if(s == 0){
        return;
    }

    displayStars(s);
    cout << endl;
    pattern(s-1);
    displayStars(s);
    cout << endl;  
};

int main(){
    int number;

    while (true){
        cout<<"Enter a number greater than zero: "<<endl;
        cin >> number;

        if(number<=0){
            cout<<"Mus enter a valid number greater than zero"<<endl;
            break;
        }else{
            pattern(number); 
        }
    }

    return 0 ;
}
