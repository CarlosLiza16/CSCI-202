/* Program name: M06 Programming Assignment B-tree
 * Author: Carlos Lizarazu
 * Date last updated: 04/26/2025
 * Purpose: The purpose of the program is to write a program that outputs the nodes of a graph in a depth-first traversal.
 */

#include <iostream>
#include <vector>
 
using namespace std;

//Function for the Depth first traversal DFS
void DFS(int node, vector<vector<int>>& list, vector<bool>& visited){
    //We mark the current node that is visited
    visited[node]=true;

    //print the current node
    cout<< node << " ";

    //loop trought all the nodes
    for(int next : list[node]){
        if(!visited[next]){
            DFS(next, list, visited);
        }
    }
}

int main(){
    int numNodes, numlines;

    //enter the nodes and lines
    cout<<"Enter the number of nodes: ";
    cin>>numNodes;
    cout<<"Enter the number of lines: ";
    cin>> numlines;

    //Create the list
    vector<vector<int>> list(numNodes);

    cout << "Enter edges (u v): "<<endl;
    for (int i = 0; i < numlines; i++) {
        int u, v;
        cin >> u >> v;
        // Add edge u-v (assuming undirected graph)
        list[u].push_back(v);
        list[v].push_back(u);
    }

    // Create a visited array
    vector<bool> visited(numNodes, false);

    // Start DFS from node 0
    cout << "DFS traversal starting from node 0: "<<endl;
    DFS(0, list, visited);

    return 0;
}