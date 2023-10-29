#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    for (int epoch = 0; epoch < T; epoch++)
    {
        int N, D, n = 0, r1, r2, tics;
        cin >> N >> D;
        string ride1, ride2;
        vector<vector<int>> cost_seq;

        map<string, int> ride_map;
        for (int d = 0; d < N*(N-1); d++)
        {
            cin >> ride1 >> ride2 >> tics;
            if (ride_map.count(ride1))
                r1 = ride_map[ride1];
            else
                r1 = n, ride_map[ride1] = n, n++;
            if (ride_map.count(ride2))
                r2 = ride_map[ride2];
            else
                r2 = n, ride_map[ride2] = n, n++;

            cost_seq.push_back({r1, r2, tics});
        }
        cout<<"Sanjith is a Bad Ass..!!!"<<endl;
    }
    return 0;
}

