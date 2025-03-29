/* Program name: M02.2 Programming Assignment - Stacks (Infix to postfix)
* Author: Carlos Lizarazu 
* Date last updated: 03/29/2025
* Purpose: The program will convert an infix arithmetic expression to postfix using a stack. 
           It processes each character, handling operands, operators, and parentheses to generate the corresponding postfix expression.
*/

#include <iostream>
#include <stack>

using namespace std;

/*Create the class for the infix and postfix */
class infixpostfix{
    private:
        string infix, postfix;
        
        int sym(char operand){
            if(operand =='+' || operand == '-'){
                return 1;
            }
            else if(operand =='*' || operand == '/'){
                return 2;
            }
            else{
                return 0;
            }
        }

    public:
    /*constructor*/
    infixpostfix(string expresion){
        infix = expresion;
        postfix = "";
    }

    /*Method to get the infix*/
    void getInfix(string exp){
        infix = exp;
    }

    /*method to convert the infix to postfix*/
    void convertToPostfix() {
        stack<char> s; //creating the empty stack

        //We'll loop through the expression
        for (char c : infix) {
            if (isalnum(c)) { //ask is the me have a sym or a number or a letter
                postfix += c; // if is number or letter it goes to postfix
            } else if (c == '(') {
                s.push(c); // Push or keep the operand in the stak
            } else if (c == ')') {
                while (!s.empty() && s.top() != '(') { //in this loop we'll add the rest of operands in the stack to the postfix until we find Open parenthesis '('
                    postfix += s.top();
                    s.pop();
                }
                s.pop(); // Remove '(' from stack
            } else { // check for operadors and their precedence
                while (!s.empty() && sym(s.top()) >= sym(c)) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        while (!s.empty()) {
            postfix += s.top();
            s.pop();
        }
    }

    /*Method to show the infix*/
    void showInfix(){
        cout<< "Infix expression: " << infix<< "; ";
    }

    /*method to show the postfix*/
    void showPostfix(){
        cout<< "Postfix: " << postfix <<endl;
    }
};
int main(){

    string userinput;
    cout<<"Enter the the experession: "<<endl;
    cin>> userinput;

    infixpostfix exp(userinput);
    exp.convertToPostfix();
    exp.showInfix();
    exp.showPostfix();

    return 0;
}