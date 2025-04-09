/* Program name: M04.1 Programming assignment Sets/Maps
 * Author: Carlos Lizarazu
 * Date last updated: 04/09/2025
 * Purpose: The program has a map with the Initial of the 50 states. The user will be asked to enter the initial of two states
 *          and the program will display the capital of that state. 

 */

 #include <iostream>
 #include <string>
 #include <map>
 #include <algorithm>
 
 using namespace std;
 
 int main(){
 
     //creating the map, string will be the abbreviation, and state is the struct
     map<string, string> stateCap;

     //Map of the states with their capitals
     stateCap["AL"] = "Montgomery";  // Alabama
     stateCap["AK"] = "Juneau";      // Alaska
     stateCap["AZ"] = "Phoenix";     // Arizona
     stateCap["AR"] = "Little Rock"; // Arkansas
     stateCap["CA"] = "Sacramento";  // California
     stateCap["CO"] = "Denver";      // Colorado
     stateCap["CT"] = "Hartford";    // Connecticut
     stateCap["DE"] = "Dover";       // Delaware
     stateCap["FL"] = "Tallahassee"; // Florida
     stateCap["GA"] = "Atlanta";     // Georgia
     stateCap["HI"] = "Honolulu";    // Hawaii
     stateCap["ID"] = "Boise";       // Idaho
     stateCap["IL"] = "Springfield"; // Illinois
     stateCap["IN"] = "Indianapolis";// Indiana
     stateCap["IA"] = "Des Moines";  // Iowa
     stateCap["KS"] = "Topeka";      // Kansas
     stateCap["KY"] = "Frankfort";   // Kentucky
     stateCap["LA"] = "Baton Rouge"; // Louisiana
     stateCap["ME"] = "Augusta";     // Maine
     stateCap["MD"] = "Annapolis";   // Maryland
     stateCap["MA"] = "Boston";      // Massachusetts
     stateCap["MI"] = "Lansing";     // Michigan
     stateCap["MN"] = "Saint Paul";  // Minnesota
     stateCap["MS"] = "Jackson";     // Mississippi
     stateCap["MO"] = "Jefferson City"; // Missouri
     stateCap["MT"] = "Helena";      // Montana
     stateCap["NE"] = "Lincoln";     // Nebraska
     stateCap["NV"] = "Carson City"; // Nevada
     stateCap["NH"] = "Concord";     // New Hampshire
     stateCap["NJ"] = "Trenton";     // New Jersey
     stateCap["NM"] = "Santa Fe";    // New Mexico
     stateCap["NY"] = "Albany";      // New York
     stateCap["NC"] = "Raleigh";     // North Carolina
     stateCap["ND"] = "Bismarck";    // North Dakota
     stateCap["OH"] = "Columbus";    // Ohio
     stateCap["OK"] = "Oklahoma City"; // Oklahoma
     stateCap["OR"] = "Salem";       // Oregon
     stateCap["PA"] = "Harrisburg";  // Pennsylvania
     stateCap["RI"] = "Providence";  // Rhode Island
     stateCap["SC"] = "Columbia";    // South Carolina
     stateCap["SD"] = "Pierre";      // South Dakota
     stateCap["TN"] = "Nashville";   // Tennessee
     stateCap["TX"] = "Austin";      // Texas
     stateCap["UT"] = "Salt Lake City"; // Utah
     stateCap["VT"] = "Montpelier";  // Vermont
     stateCap["VA"] = "Richmond";    // Virginia
     stateCap["WA"] = "Olympia";     // Washington
     stateCap["WV"] = "Charleston";  // West Virginia
     stateCap["WI"] = "Madison";     // Wisconsin
     stateCap["WY"] = "Cheyenne";    // Wyoming
 
     //Variables
     string  userInput;
 
     while(true){
         cout<<"Enter the abbreviation of the state or 'exit' to quit: ";
         cin>>userInput;
         transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
 
         //exiting the code if the user wnats to exit
         if(userInput=="EXIT"){
             cout<<"Exiting program."<<endl;
             break;
         }
 
         //checking in hte map to see if the user input is correct
         auto state = stateCap.find(userInput);
         if (state != stateCap.end()){
             cout<<"The capital of "<< userInput << " is " << state->second<<endl;
         }else{
             cout<<"\nError: the abbreviation was not found. Try again: "<<endl;
         }
 
     }
 
     return 0;
 }