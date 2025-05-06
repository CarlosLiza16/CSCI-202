/* Program name: M07 Programming Assignment 
 * Author: Carlos Lizarazu
 * Date last updated: 05/06/2025
 * Purpose: This program demonstrates how floating-point precision errors can occur in numerical computations 
            by comparing two different ways of summing small values using both float and double
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    int n=10000;

    //Calculate the values we will be adding for float and double
    float numFloat = 1.0f/n;
    double numDouble = 1.0/n;

    //First loop Float
    float sum1_float = 0.0f;
    for (int i = 0; i < n; i++) {
        sum1_float += numFloat; // Repeatedly add small float value
    }

    //Second loop float
    float sum2_float = 0.0f; // Initialize sum for second float loop
    for (int i = 0; i < n; i++) {
        sum2_float += 1.0f; // Add 1.0f each time
    }
    sum2_float *= numFloat; // Multiply total by small float value

    //First loop double
    double sum1_double = 0.0; // Initialize sum for first double loop
    for (int i = 0; i < n; i++) {
        sum1_double += numDouble; // Repeatedly add small double value
    }

    //second loop double

    double sum2_double = 0.0; // Initialize sum for second double loop
    for (int i = 0; i < n; i++) {
        sum2_double += 1.0; // Add 1.0 each time
    }
    sum2_double *= numDouble;

    //format the outpot of the decimal
    cout << fixed << setprecision(10);

    cout << "FLOAT Precision"<<endl;
    cout << "First Loop float:  sum = " << sum1_float << endl;  
    cout << "Second Loop float: sum = " << sum2_float << endl;  
    cout << "Difference: " << sum1_float - sum2_float << endl;  

    // Output double results
    cout << "DOUBLE Precision" <<endl;
    cout << "First Loop (double):  sum = " << sum1_double << endl; // Direct sum of small double
    cout << "Second Loop (double): sum = " << sum2_double << endl; // Scaled result
    cout << "Difference: " << sum1_double - sum2_double << endl;   // Smaller difference
    return 0;
}