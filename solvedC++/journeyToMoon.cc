#include <bits/stdc++.h>
using namespace std;

// DISJOINT SET BASED SOLUTION
int merge(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    return merge(parent, parent[x]);
}

long long connectedcomponents(int n, vector<vector<int>> &edges)
{

    long long combinations = 0;
    int parent[n];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (auto x : edges)
        parent[merge(parent, x[0])] = merge(parent, x[1]);

    for (int i = 0; i < n; i++)
        parent[i] = merge(parent, parent[i]);

    map<int, int> m, m2;
    for (int i = 0; i < n; i++)
        m[parent[i]]++;

    for (auto it = m.begin(); it != m.end(); it++)
        m2[it->second]++;

    for (auto it = m2.begin(); it != m2.end(); it++)
    {
        combinations += (long long)it->first * it->first * it->second * (it->second - 1) / 2;
        for (auto it2 = next(it); it2 != m2.end(); it2++)
            combinations += (long long)it->second * it->first * it2->first * it2->second;
    }

    return combinations;
}
long long journeyToMoon(int n, vector<vector<int>> astronaut)
{
    return connectedcomponents(n, astronaut);
}

int main()
{
    int n = 5;
    vector<int> e1 = {1, 2};
    vector<int> e2 = {3, 2};
    vector<int> e3 = {4, 0};
    vector<vector<int>> e;
    e.push_back(e1);
    e.push_back(e2);
    e.push_back(e3);
    cout << journeyToMoon(5, e) << endl;

    return 0;
}