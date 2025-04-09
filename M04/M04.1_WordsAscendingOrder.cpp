/* Program name: M04.1 Programming assignment Sets/Maps
 * Author: Carlos Lizarazu
 * Date last updated: 04/09/2025
 * Purpose: The program will open and read a file, it will display all the nonduplicates words in ascending order
 */

 #include <iostream>
 #include <fstream>  
 #include <string>
 #include <sstream>
 #include <set>

 using namespace std;
 
 
 int main(){

    string myText;
    set<string> setWords;

    //open the file
    ifstream file("D:/Ivy Tech/Spring Semester 2025/CSCI 202/Codigos/M04/Text.txt");
 
    //check if the file opens
    if(!file){
        cout<<"Error: the file was not able to open"<< endl;
        return 1;
    }
 
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (file, myText)) {
        stringstream line(myText);
        string word;

        while (line >> word) //get evry word of a line
        {
            setWords.insert(word);
        }
        
    }
 
    file.close();

    cout<<"Nonduplicated words first paragraph "<<endl;
    
    for (const auto& wordsinSet : setWords) {
        cout << wordsinSet << endl;
    }

    return 0;
 }