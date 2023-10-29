#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Implementation of Query 1
void BFS(int n, vector<vector<int>> &adj_list, vector<int> &distances)
{
    queue<int> q;
    vector<bool> visited(n);
    vector<int> d(n);
    int s = 0;

    q.push(s);
    visited[s] = true, distances[s] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj_list[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
                distances[u] = distances[v] + 1;
            }
        }
    }
    return;
}

void runQuery(int v, int l, int r, vector<int> &distances, vector<int> &values)
{
    for (int u = 0; u < distances.size(); u++)
        if (distances[u] > distances[v] && distances[u] - distances[v] <= r - l)
            values[u] = phi(l + distances[u] - distances[v]);
}

int main()
{
    int n = 0, a = 0, b = 0, q = 0, v = 0, l = 0, r = 0, query_type = 0;
    cin >> n;

    vector<vector<int>> adj_list(n, vector<int>(0));
    vector<int> values(n, 0);
    vector<int> distances(n, -1);
    vector<int> phi_values(1000,-1);


    for (int e = 0; e < n - 1; e++)
    {
        cin >> a >> b;
        adj_list[a - 1].push_back(b - 1), adj_list[b - 1].push_back(a - 1);
    }
    BFS(n, adj_list, distances);

    cin >> q;
    for (int epoch = 0; epoch < q; epoch++)
    {
        cin >> query_type;
        if (query_type == 1)
        {
            cin >> v >> l >> r;
            v--, l, r;
            runQuery(v, l, r, distances, values);
        }
        else
        {
            cin >> v;
            v--;
            cout << values[v] << endl;
        }
    }

    return 0;
}
