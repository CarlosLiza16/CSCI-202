/* Program name: M01.1 Programming Assignment - Polymorphism and validation
* Author: Carlos Lizarazu 
* Date last updated: 03/10/2024
* Purpose: The assignment will allow the user to enter a number in roman numerals (ex. V, C, M, VII), 
           the program will store the number and convert it to decimal form.
*/



#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/* Create the class that romanType*/

class RomanType{
    private:
        string romanNum;
    
    public:
        //constructor
        RomanType(string userNum){
            romanNum = userNum;
        }

        //function to validate the number
        bool validateNumber(){
            string validRomanNumber = "IVXLCDM";

            for (char letter : romanNum){
                if(validRomanNumber.find(toupper(letter)) == string::npos ){
                    return false;
                }
            }
            return true;
        }

        //function to convert the number to decimal
        int convertDecimal(){
            int decimalNum= 0;
            int previousvalue= 0;

            for(int i = romanNum.length() - 1; i >= 0; i--){
               char currentLetter = toupper(romanNum[i]);
               int currentValue = 0;
               
               switch (currentLetter)
               {
               case 'I': currentValue = 1; break;
               case 'V': currentValue = 5; break;
               case 'X': currentValue = 10; break;
               case 'L': currentValue = 50; break;
               case 'C': currentValue = 100; break;
               case 'D': currentValue = 500; break;
               case 'M': currentValue = 1000; break;
               }
               
               if (currentValue<previousvalue){
                decimalNum -= currentValue;
               }
               else{
                decimalNum += currentValue;
               }

               //update the previousValue
               previousvalue = currentValue;
            }

            return decimalNum;
        }
};

int main(){

    string userInput;
    
    while(true){

        cout << "Enter a number in Roman numeral or 'exit' to quit: ";
        cin>> userInput;

        if (userInput == "exit"){
            cout<<"Exiting program."<< endl;
            break;
        }
        
        RomanType num(userInput);

        bool validatedNumber = num.validateNumber();

        if(validatedNumber){
            int decimalNumber = num.convertDecimal();
            cout<< "'" << userInput << "' is " << decimalNumber <<endl;
        }else{
            cout << "Invalid Roman numeral"  << endl;
        }
    }

    
    return 0;
}
