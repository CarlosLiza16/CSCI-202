/* Program name: Final Project 
* Author: Carlos Lizarazu 
* Date last updated: 05/8/2025
* Purpose:  The project will simulate a job scheduling system, where we should be able to complete a task and give it a priority level. 
            The system is supposed to arrange the task in a first come first serve (FCFS), shortest job first (SJF), and priority scheduling (PS). 
*/


#include <iostream>
#include <list>
#include <string>
#include <queue>

using namespace std;


//Struct to store the Task information
struct Task{
    string taskName;    //Name of the job
    int time;           //Time needed to do do the job
    int priority;       //priority level of the job
};

//Compare the priorities of the tasks
struct comparePriority{
    bool operator()(Task& t1, Task& t2){
        return t1.priority > t2.priority;   //The priority queue sort by the lowest priority
    }
};

//Function to implement the Fisrt Come First Serve
void FCFS(list<Task>& taskList){
    cout<< "First Come First Serve: \n";
    for (auto& task : taskList){
        cout<< "-> " << task.taskName << " - " << task.time << " - " << task.priority << endl;
    }
}

//Function to implement the shortest job first

//First we need to another function to compare the time
bool compareTime(const Task& a, const Task& b){
    return a.time < b.time;     //sort the tasks by time in ascending order
}

void SJF(list<Task>& tasklist){
    tasklist.sort(compareTime);
    cout<< "Short Task First: \n";
    for(auto& task : tasklist){
        cout<< "-> " << task.taskName << " - " << task.time << " - " << task.priority << endl;
    }
}


//Function to get the priority Scheduling
void priority(priority_queue<Task, vector<Task>, comparePriority>& pq){
    cout<< "Priority Scheduling Order: \n";
    while(!pq.empty())              //Loop until th elist is empty
    {
        Task task = pq.top();       //Get the task with the highest priority (lower number means priority)
        pq.pop();                   //Remove that value from the queue

        cout<< "-> " << task.taskName << " - " << task.time << " - " << task.priority << endl;
    }
}

int main(){

    //Create the list of tasks for FCFS and SJF
    list<Task> tasklist;

    //Create the list for the priority Schedualing
    priority_queue<Task, vector<Task>, comparePriority> pq;

    int numberTask, choice;

    cout<<"Enter the number of tasks you have today: ";
    cin>>numberTask;
    cin.ignore(); //Clean the new line 

    for(int i=0; i<numberTask; i++){
        Task newTask;

        cout<<"\nEnter details for the task "<< i+1 << ": "<<endl;

        
        //getting the name
        cout<< "What is the name task: ";
        getline(cin, newTask.taskName); //so we handle spaces
        

        //getting the time to complete the assignment
        cout<<"Enter the time you need to complete this task in hours: ";
        cin>> newTask.time;

        //getting the priority level of the task (Lower value is higher priority)
        cout<<"Enter the Level of priority for this task (1 High priority, 2 medium priority, 3 less priority): ";
        cin>>newTask.priority;

        //We add the tasks to list priority queue
        tasklist.push_back(newTask);
        pq.push(newTask);
        cin.ignore();
    }

    cout<< "\nSelect the method you want to schedule your tasks: " <<endl;
    cout<<"1. First Come First serve"<<endl;
    cout<<"2. Shortest Task First"<<endl;
    cout<<"3. Priority Task First"<<endl;
    cin>>choice;

    switch (choice)
    {
    case 1:
        FCFS(tasklist);
        break;
    case 2:
        SJF(tasklist);
        break;
    case 3:
        priority(pq);
        break;
    default:
        cout<<"INVALID OPTION"<<endl;
        break;
    }

    return 0;
}