#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define edge pair<int, int>

class Graph
{
private:
    // graph is stored as a vector of pairs, where each pair takes the form: <weight, edge>
    vector<pair<int, edge>> G; // graph
    vector<pair<int, edge>> T; // minimum spanning tree for the graph G
    int *parent;               // to set parents for Union Find algorithm
    int V;                     // number of vertices/nodes in graph
public:
    Graph(int V);
    void addWeightedEdge(int u, int v, int w);
    void findMSTKruskal();
    void printMST();
    void union_set(int u, int v);
    int find_set(int i);
};

Graph::Graph(int V)
{
    parent = new int[V];

    // set parent to self initially
    // i           0 1 2 3 4 5 ...
    // parent[i]   0 1 2 3 4 5 ...
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void Graph::addWeightedEdge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i)
{
    // Ensuring the same set : same parent
    if (i == parent[i])
        return i;
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) { parent[find_set(u)] = parent[find_set(v)]; }

void Graph::findMSTKruskal()
{
    sort(G.begin(), G.end());
    for (auto vertice : G)
    {
        int u = vertice.second.first, v = vertice.second.second;
        int u_set = find_set(u), v_set = find_set(v);
        if (u_set != v_set)
        {
            T.push_back(vertice);
            union_set(u, v);
        }
    }
}

void Graph::printMST()
{
    int minCost = 0;
    cout << "Edge : "
         << "Weight" << endl;
    for (int i = 0; i < int(T.size()); i++)
    {
        cout << T[i].second.first << " - " << T[i].second.second << " : " << T[i].first << endl;
        minCost += T[i].first;
    }
    cout << "Minimum Cost = " << minCost << endl;
}

int main()
{
    int numVertices;
    cin >> numVertices;

    Graph g(numVertices);

    int u, v, w;
    cin >> u;
    while (u != -1)
    {
        cin >> v >> w;
        g.addWeightedEdge(u, v, w);
        cin >> u;
    }

    g.findMSTKruskal();
    g.printMST();
    return 0;
}
