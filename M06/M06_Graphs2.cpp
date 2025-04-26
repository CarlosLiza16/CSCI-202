/* Program name: M06 Programming Assignment B-tree
 * Author: Carlos Lizarazu
 * Date last updated: 04/22/2025
 * Purpose: The purpose of the program is to output the nodes of a graph in a breadth-first traversal.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Funtion to perfom the breadth first traversal
void BFS(int startNode, vector<vector<int>>& list, vector<bool>& visited) {
    queue<int> q;

    //Mark the start of the node as visited
    visited[startNode] = true;
    //Add the start node to the queue
    q.push(startNode);

    while (!q.empty()) {

        int node = q.front(); //get the node
        q.pop();              //remove the node
        cout << node << " ";  //print the node

        //go through all the nodes of the same level
        for (int neighbor : list[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    int numNodes, numlines;

    // Input number of nodes and lines
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    cout << "Enter number of lines: ";
    cin >> numlines;

    // Create adjacency list to store the graph
    vector<vector<int>> list(numNodes);

    // Input all the edges
    cout << "Enter lines (u v): "<<endl;
    for (int i = 0; i < numlines; i++) {
        int u, v;
        cin >> u >> v;

        // Check for invalid node numbers
        if (u >= numNodes || v >= numNodes || u < 0 || v < 0) {
            cout << "Invalid line: " << u << " " << v << endl;
            continue;
        }

        // Add edge to the adjacency list (undirected graph)
        list[u].push_back(v);
        list[v].push_back(u);
    }

    // Track visited nodes
    vector<bool> visited(numNodes, false);

    // Start BFS from node 0
    cout << "BFS traversal starting from node 0: "<<endl;
    BFS(0, list, visited);

    return 0;
}