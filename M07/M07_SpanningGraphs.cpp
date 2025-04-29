/* Program name: M06 Programming Assignment Spanning graphs Fleury's algorithm
 * Author: Carlos Lizarazu
 * Date last updated: 04/29/2025
 * Purpose: Create and implement the Fleury's algorithm. In other words, help to find the path of a network without repeating any.
 */


#include <iostream>
#include <list>
#include <cstring>

using namespace std;

//create a class for the graph
class Graph{
    int v;                  //number of nodes
    list<int>* adjList;     //pointer to an array of a adjacent list

    public:
        //constructor
        Graph(int v){
            this->v = v;
            adjList = new list<int>[v]; 
        }

        //destructor 
        ~Graph() { 
            delete [] adjList;
        }

        //function to add
        void addEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        //function to remove
        void rmvEdge(int u, int v){
            adjList[u].remove(v);
            adjList[v].remove(u);
        }

        //define the functions
        bool isValid(int u, int v);
        int DFSCount(int v, bool visited[]);
        void printEuler(int u);
        void printTour();
};

//We check is the edge U-v can be the enxt edge in the euler tour
bool Graph::isValid(int u, int v) {
    if (adjList[u].size() == 1) {
        return true;
    }

    bool* visited = new bool[this->v];
    memset(visited, false, this->v * sizeof(bool));
    int count1 = DFSCount(u, visited);

    rmvEdge(u, v);

    memset(visited, false, this->v * sizeof(bool));
    int count2 = DFSCount(u, visited);

    addEdge(u, v);
    delete[] visited;

    return (count1 <= count2);
}

//Counts the number of nodes(vertices) reachable from v using DFS
int Graph::DFSCount(int v, bool visited[]){
    visited[v] = true;
    int count = 1;
    for (int i : adjList[v]){
        if(!visited[i]){
            count += DFSCount(i, visited);
        }
    }
    return count;
}

//Prints the the tour starting at u
void Graph::printEuler(int u){
    for(auto it = adjList[u].begin(); it!=adjList[u].end();it++){
        int v = *it;
        if(isValid(u, v)){
            cout << u << " -> " << v << endl;
            rmvEdge(u,v);
            printEuler(v);
            break;
        }
    }
}
//Initiates the tour
void Graph::printTour(){
    int u=0;
    for (int i=0; i<v ; i++){
        if(adjList[i].size()%2 !=0){
            u = i;
            break;
        }
    }

    cout<<"The Fleuty's algorithm circuit is: \n";
    printEuler(u);
}


int main(){
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph g(numNodes);
    cout << "Enter the edges (u v): " << endl;

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    g.printTour();

    return 0;
}