#include <bits/stdc++.h>

using namespace std;

int main()
{
    long a, c, q, n, h0, cur_h;
    long count = 0;
    priority_queue<long, vector<long>, greater<long>> pq;

    cin >> n >> h0 >> a >> c >> q;
    cur_h = h0;
    pq.push(cur_h);

    for (long i = 1; i < n; i++)
    {
        count += (long)pq.size();
        cur_h = (a * cur_h + c) % q;
        while (!pq.empty() && pq.top() <= cur_h)
            pq.pop();
        pq.push(cur_h);
    }
    cout<<count<<endl;
    return 0;
}