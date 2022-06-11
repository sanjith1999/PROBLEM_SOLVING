#include <bits/stdc++.h>

using namespace std;

// Type Definitions
typedef pair<int, int> line;
struct compare_edge
{
    bool operator()(pair<int, line> const &e1, pair<int, line> const &e2)
    {
        return e1.first > e2.first;
    }
};

// Prims Algorithm
int prims(int n, vector<vector<int>> edges, int start)
{
    int u = 0, v = 0, w = 0, total_weight = 0;
    int mst_set[n];
    for (int i = 0; i < n; i++)
        mst_set[i] = -1;
    mst_set[start - 1] = 1;

    // Preparing Adjacency matrix
    list<pair<int, int>> Edges[n]; // u : v1,w1 --> v2,w2
    for (auto edge : edges)
    {
        u = edge[0] - 1, v = edge[1] - 1, w = edge[2];
        Edges[u].push_back(make_pair(v, w));
        Edges[v].push_back(make_pair(u, w));
    }

    priority_queue<pair<int, line>, vector<pair<int, line>>, compare_edge> min_q;

    // Visiting an Vertice
    u = start - 1;
    while (!Edges[u].empty())
    {
        v = Edges[u].back().first, w = Edges[u].back().second;
        Edges[u].pop_back(), Edges[v].remove(make_pair(v, w));
        min_q.push(make_pair(w, make_pair(u, v)));
    }
    while (!min_q.empty())
    {
        u = min_q.top().second.second, w = min_q.top().first;
        min_q.pop();
        if (mst_set[u] == 1)
            continue;
        mst_set[u] = 1, total_weight += w;

        while (!Edges[u].empty())
        {
            v = Edges[u].back().first, w = Edges[u].back().second;
            Edges[u].pop_back(), Edges[v].remove(make_pair(v, w));
            min_q.push(make_pair(w, make_pair(u, v)));
        }
    }
    return total_weight;
}

int main()
{
    vector<vector<int>> edges;
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 4});
    edges.push_back({4, 2, 6});
    edges.push_back({5, 2, 2});
    edges.push_back({3, 5, 7});
    edges.push_back({2, 3, 5});
    cout << prims(5, edges, 1) << endl;
}
