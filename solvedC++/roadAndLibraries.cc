#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // No. of vertices
    int num_islands;
    int num_nodes;
    long total_cost;
 
    // Pointer to an array containing adjacency lists
    list<int>* adj;
 
    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
 
public:
    Graph(int V); // Constructor
    ~Graph();
    void addEdge(int v, int w);
    long connectedComponents(int c_lib, int c_road);
};
 
// Method to print connected components in an
// undirected graph
long Graph::connectedComponents(int c_lib, int c_road)
{
    // Mark all the vertices as not visited
    num_islands = 0,total_cost= 0;
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            num_nodes = 0;
            DFSUtil(v, visited);
            total_cost += (long)(num_nodes-1)*c_road;
            num_islands++;
        }
    }
    total_cost += (long)num_islands*c_lib;
    delete[] visited;
    return total_cost;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    num_nodes++;
    
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
Graph::~Graph() { delete[] adj; }
 
// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}





long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    // if cost of c_lib is less build a library to each city
    if (c_lib<c_road)
        return (long)n*c_lib;
    
    // Finding the # bridges
    Graph g(n);
    for (auto edge:cities){
        g.addEdge(edge[0]-1, edge[1]-1);
    }
    
    return g.connectedComponents(c_lib, c_road);

}

int main(){
    Graph g(10);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);

    g.addEdge(4,5);
    g.addEdge(5,6);

    g.addEdge(7,8);
    g.addEdge(8,9);

    cout<<g.connectedComponents(2,4)<<endl;
    return 0;
}