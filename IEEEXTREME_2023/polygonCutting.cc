#include <bits/stdc++.h>
using namespace std;

double polygonArea(vector<pair<long, long>> &V, vector<long> &VN)
{
    double area = 0.0;
    long n = VN.size();
    long j = n - 1;
    for (long i = 0; i < n; i++)
    {
        area += (V[VN[j]].first + V[VN[i]].first) * (V[VN[j]].second - V[VN[i]].second);
        j = i; // j is previous vertex to i
    }
    return abs(area);
}

long findMaxSum(vector<long> &arr)
{
    long n = arr.size();
    long incl = arr[0];
    long excl = 0;
    long excl_new;
    long i;
 
    for (i = 1; i < n; i++) {
        excl_new = max(incl, excl);
 
        incl = excl + arr[i];
        excl = excl_new;
    }
 
    return max(incl, excl);
}

int main()
{
    vector<pair<long, long>> vertices;
    list<vector<long>> polygons;
    long N, M;
    long x, y, u, v;
    vector<long> polygon;

    cin >> N >> M;
    for (long v = 0; v < N; v++)
    {
        cin >> x >> y;
        vertices.push_back(make_pair(x, y));
        polygon.push_back(v);
    }
    polygons.push_back(polygon);

    for (long e = 0; e < M; e++)
    {
        cin >> u >> v;
        u--, v--;
        for (auto it = polygons.begin(); it != polygons.end(); it++)
        {
            vector<long> polygon = *it;
            if (find(polygon.begin(), polygon.end(), u) != polygon.end() && find(polygon.begin(), polygon.end(), v) != polygon.end())
            {
                long min_sep = min(u, v), max_sep = max(u, v);
                vector<long> l_polygon, r_polygon;
                for (auto ver : polygon)
                {
                    if (ver > max_sep || ver < min_sep)
                        l_polygon.push_back(ver);
                    else if (ver == max_sep || ver == min_sep)
                        r_polygon.push_back(ver), l_polygon.push_back(ver);
                    else
                        r_polygon.push_back(ver);
                }
                polygons.insert(it, l_polygon);
                polygons.insert(it, r_polygon);
                polygons.erase(it);
                break;
            }
        }
    }

    vector<long> areas;
    for (auto polygon_:polygons){
        areas.push_back(polygonArea(vertices,polygon_));   
    }
    cout<<findMaxSum(areas)<<endl;
return 0;

}


