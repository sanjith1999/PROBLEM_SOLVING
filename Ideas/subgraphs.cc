#include <bits/stdc++.h>
using namespace std;
 

// IDEA 1: DFS BASED SOLUTION -- Function will print seperate components -> LOW COMPLEX SOLUTION
class Graph {
    int V; // No. of vertices
    list<int>* adj;
    void DFSUtil(int v, bool visited[]);
 
public:
    Graph(int V); // Constructor
    ~Graph();
    void addEdge(int v, int w);
    void connectedComponents();
};
 
// Print Connected Components
void Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            // print all reachable vertices
            // from v
            DFSUtil(v, visited);
 
            cout << "\n";
        }
    }
    delete[] visited;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices
    // adjacent to this vertex
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
 
// Driver code
int duplicateMain()
{
    // Create a graph given in the above diagram
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(2,0);

    g.addEdge(3, 4);
    g.addEdge(4,3);
    
 
    cout << "Following are connected components \n";
    g.connectedComponents();
 
    return 0;
}


// DISJOINT SET BASED SOLUTION
int merge(int* parent, int x)
{
    if (parent[x] == x)
        return x;
    return merge(parent, parent[x]);
}
 
int connectedcomponents(int n, vector<vector<int> >& edges)
{
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (auto x : edges) {
        parent[merge(parent, x[0])] = merge(parent, x[1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (parent[i] == i);
    }
    for (int i = 0; i < n; i++) {
        parent[i] = merge(parent, parent[i]);
    }
    map<int, list<int> > m;
    for (int i = 0; i < n; i++) {
        m[parent[i]].push_back(i);
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        list<int> l = it->second;
        for (auto x : l) {
            cout << x << " ";
        }
        cout << endl;
    }
    return ans;
}
 
int main()
{
    int n = 5;
    vector<int> e1 = { 0, 1 };
    vector<int> e2 = { 2, 1 };
    vector<int> e3 = { 3, 1 };
    vector<vector<int> > e;
    e.push_back(e1);
    e.push_back(e2);
    e.push_back(e3);
 
    cout << "Following are connected components:\n";
    int a = connectedcomponents(n, e);
    return 0;
}