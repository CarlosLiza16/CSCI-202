/* Program name: M02.2 Programming Assignment - Stacks (Binary to Decimal)
* Author: Carlos Lizarazu 
* Date last updated: 03/29/2025
* Purpose: The program will convert a binary number to decimal using stacks.
*/

#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

/*Convert the binary to decimal*/
int convertDecimal(string num){
    stack<int> digits;
    int decimal=0;
    int power= 0;

    /*Push each digit into the stack and it also vonerts them to integer using ASCII*/
    for (char d: num){
        digits.push(d - '0');
    }

    /*Converting the binary value to Dacimal */
    while(!digits.empty()){
        int stacknumber = digits.top();
        digits.pop();
        decimal += stacknumber * pow(2, power);
        power++;
    }

    return decimal;
}

int main(){

    string number;
    int decimalNumber;
    
    while(true){

        cout<< "Enter the binary number or exit to quit" <<endl;
        cin>> number;

        if (number == "exit"){
            cout<<"Exiting program."<< endl;
            break;
        }
        
        bool valid = true;
        for (char x: number){
            if(x!='0' && x!='1'){
                valid=false;
                break;
            }
        }

        if(!valid){
            cout<<"Invalid input"<<endl;
        }
        else{
            decimalNumber = convertDecimal(number);
            cout<< "The binary number in decimal is: "<< decimalNumber<<endl;
        }

    }

    return 0;
}