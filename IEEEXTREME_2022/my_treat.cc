#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    for (int epcho = 0; epcho < T; epcho++)
    {
        int M = 0;
        vector<string> peers;
        string person, eater;
        int num_days = 0, num_meals = 0;
        // int p_id, e_id;
        map<string, pair<int, int>> per_ate_gave;

        cin >> M;
        for (int p = 0; p < M; p++)
        {
            cin >> person;
            int N = 0;
            cin >> N;

            if (per_ate_gave.find(person) != per_ate_gave.end())
                per_ate_gave[person].second += N;
            else
                per_ate_gave.insert(make_pair(person, make_pair(0, N)));
            for (int e = 0; e < N; e++)
            {
                cin >> eater;
                if (per_ate_gave.find(eater) != per_ate_gave.end())
                    per_ate_gave[eater].first++;
                else
                    per_ate_gave.insert(make_pair(eater, make_pair(1, 0)));
            }
        }
        for (auto person : per_ate_gave)
        {
            int temp = person.second.second - person.second.first;
            num_days = max(temp, num_days);
            num_meals += max(temp, 0);
        }
        cout<<num_meals<<" "<<num_days<<endl;
    }
    return 0;
}

