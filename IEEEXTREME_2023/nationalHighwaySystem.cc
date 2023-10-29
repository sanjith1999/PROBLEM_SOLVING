#include <bits/stdc++.h>
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
    void findMSTKruskal(int random_pick);
    int costMST();
    void union_set(int u, int v);
    int find_set(int i);
};

Graph::Graph(int V)
{
    parent = new int[V];
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

void Graph::findMSTKruskal(int random_pick)
{
    T.clear();
    sort(G.begin(), G.end());
    for (int ver = 0; ver < G.size(); ver++)
    {
        pair<int, edge> vertice = G[ver];
        if (ver == random_pick)continue;
        int u = vertice.second.first, v = vertice.second.second;
        int u_set = find_set(u), v_set = find_set(v);
        if (u_set != v_set)
        {
            T.push_back(vertice);
            union_set(u, v);
        }
    }
}

int Graph::costMST()
{
    int minCost = 0;
    for (int i = 0; i < int(T.size()); i++)
    {
        minCost += T[i].first;
    }
    return minCost;
}

int main()
{
    int n = 0, w = 0, c_city = 0;
    string c1, c2;
    map<string, int> city_map;
    vector<vector<int>> edges;

    cin >> n;
    for (int r = 0; r < n; r++)
    {
        vector<int> e;
        cin >> c1 >> c2 >> w;
        if (city_map.find(c1) == city_map.end())
            city_map[c1] = c_city, c_city++;
        if (city_map.find(c2) == city_map.end())
            city_map[c2] = c_city, c_city++;

        e.push_back(city_map[c1]);
        e.push_back(city_map[c2]);
        e.push_back(w);
        edges.push_back(e);
    }

    // Check whether the graph is complete
    int expected_edges = c_city * (c_city - 1) / 2;
    if (expected_edges > n)
        cout << "-1" << endl;
    else

    {
        Graph g(c_city);
        for (auto e : edges)
            g.addWeightedEdge(e[0], e[1], e[2]);
        g.findMSTKruskal();
        cout << g.costMST() << endl;
    }
    return 0;
}