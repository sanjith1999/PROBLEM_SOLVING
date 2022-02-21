#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> cities;
    vector<int> aCity;
    int n = 0, p = 0, a = 0, b = 0,ref=0;
    int invalidPairs = 0;

    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        aCity.push_back(-1);
    }
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        if (aCity[a] == -1 && aCity[b] == -1)
        {
            aCity[a] = cities.size();
            aCity[b] = cities.size();
            cities.push_back({a, b});
        }
        else if (aCity[a] != -1 && aCity[b] != -1 && aCity[a] != aCity[b])
        {
            cities[aCity[b]].insert(cities[aCity[b]].end(), cities[aCity[a]].begin(), cities[aCity[a]].end());
            ref=aCity[a];
            for(auto &city: cities[ref]){aCity[city]=aCity[b];}
            cities[ref] = {};
        }
        else if (aCity[a] == -1)
        {
            cities[aCity[b]].push_back(a);
            aCity[a] = aCity[b];
        }
        else if(aCity[b] == -1)
        {
            cities[aCity[a]].push_back(b);
            aCity[b] = aCity[a];
        }
    }

    for (auto &element : cities)
    {
        if (element.size())
        {
            invalidPairs += element.size() * (element.size() - 1) / 2;
        }
    }
    cout << n * (n - 1) / 2 - invalidPairs << endl;
    return 0;
}
